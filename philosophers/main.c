/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:22 by youhan            #+#    #+#             */
/*   Updated: 2022/06/16 22:50:21 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <sys/time.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	calculate_time(size_t p_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 * 1000 + time.tv_usec - p_time);
}

void	ft_usleep(size_t time)
{
	size_t	start_time;
	
	start_time = calculate_time(0);
	while (calculate_time(0) - start_time < time)
	{
		usleep(50);
	}
}

long long	ft_atoi(char *str)
{
	int			sign;
	long long	n;

	sign = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		n = n * 10 + *str++ - '0';
	return (n * sign);
}

void	print_philo_status(t_philo *philo, int status)
{
	int		num;
	size_t	time;

	num = philo->num;
	pthread_mutex_lock(philo->print);
	time = calculate_time(*(philo->start_time)) / 1000;
	// if (time % 100 != 0)
	// {
	// 	philo->eating_time -= time % 100;
	// 	*(philo->start_time) -= time % 100;
	// }
	// philo->diff_error = time % 10;
	// time = time - time % 100;
	
	if (*(philo->exit) == 0)
		return ;
	else if (status == TAKEN_FORK)
		printf("%ld %d has taken a fork\n", time, num);
	else if (status == EAT)
		printf("%ld %d is eating\n", time, num);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, num);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, num);
	else if (status == DEAD)
		printf("%ld %d died\n", time, num);
	pthread_mutex_unlock(philo->print);
}

int	ft_input_unique(int *arr, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	input_all_num_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

int	input_check(char **argv, t_list *data)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (input_all_num_check(argv[i]) == -1)
			return (-1);
		i++;
	}
	i = 1;
	while (argv[i] != NULL)
	{
		data->time_data[i - 1] = ft_atoi(argv[i]);
		if (data->time_data[i - 1] == 0  && i - 1 != 5)
			return (-1);
		i++;
	}
	if (i == 5)
		data->time_data[4] = -1;
	return (1);
}

int	input_init(int argc, char **argv, t_list *data)
{
	if (!(argc == 5 || argc == 6))
		return (-1);
	if (input_check(argv, data) == -1)
		return (-1);
	return (1);
}

int	make_philo(t_list *data)
{
	int		i;
	t_philo	*first_philo;
	t_philo	*prev_philo;

	first_philo = data->philo;
	i = 1;
	while (i < data->time_data[0])
	{
		prev_philo = data->philo;
		data->philo->next = (t_philo *)malloc(sizeof(t_philo));
		if (data->philo->next == NULL)
			return (-1);
		data->philo->next->num = i + 1;
		data->philo->next->time_data = data->time_data;
		data->philo->next->prev = prev_philo;
		data->philo = data->philo->next;
		i++;
	}
	data->philo->next = first_philo;
	first_philo->prev = data->philo;
	data->philo = first_philo;
	return (1);
}

int	make_philosophers(t_list *data)
{
	if (data->time_data[0] == 0)
		return (-1);
	data->philo = (t_philo *)malloc(sizeof(t_philo));
	if (data->philo == NULL)
		return (-1);
	data->philo->num = 1;
	data->philo->time_data = data->time_data;
	data->philo->next = NULL;
	data->philo->prev = NULL;
	if (make_philo(data) == -1)
		return (-1);
	return (1);
}

void	print_time_data(t_list data)
{
	printf("philo : %d\n", data.time_data[0]);
	printf("die : %d\n", data.time_data[1]);
	printf("eat : %d\n", data.time_data[2]);
	printf("sleep : %d\n", data.time_data[3]);
	printf("must : %d\n", data.time_data[4]);
}

void	philo_think(t_philo *philo)
{
	print_philo_status(philo, THINK);
}
void	philo_sleep(t_philo *philo)
{
	print_philo_status(philo, SLEEP);
	ft_usleep(philo->time_data[SLEEP_TIME] * 1000);
	philo_think(philo);
}

void	philo_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	print_philo_status(philo, TAKEN_FORK);
	pthread_mutex_lock(&(philo->prev->fork));
	print_philo_status(philo, TAKEN_FORK);
}
void	philo_put_down(t_philo *philo)
{
	print_philo_status(philo, EAT);
	philo->eating_time = calculate_time(0);
	philo->eating_count += 1;
	ft_usleep(philo->time_data[EAT_TIME] * 1000);
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(&(philo->prev->fork));
	philo_sleep(philo);
}

void	philo_eating_even(t_philo *philo)
{
	if (philo->num % 2 == 1)
	{
		if (((calculate_time(*(philo->start_time)) / (philo->time_data[2] * 1000)) % 2) == 0)
			philo_taken_fork(philo);
		else
			return ;
	}
	else if (philo->num % 2 == 0)
	{
		if (((calculate_time(*(philo->start_time)) / (philo->time_data[2] * 1000)) % 2) == 1)
			philo_taken_fork(philo);
		else
			return ;
	}
	philo_put_down(philo);
}

void	philo_eating_odd(t_philo *philo)
{
	if (philo->num % 2 == 1 && philo->num != philo->time_data[0])
	{
		if (((calculate_time(*(philo->start_time)) / (philo->time_data[2] * 1000)) % 3) == 0)
			philo_taken_fork(philo);
		else
			return ;
	}
	else if (philo->num % 2 == 0)
	{
		if (((calculate_time(*(philo->start_time)) / (philo->time_data[2] * 1000)) % 3) == 1)
			philo_taken_fork(philo);
		else
			return ;
	}
	else
	{
		if (((calculate_time(*(philo->start_time)) / (philo->time_data[2] * 1000)) % 3) == 2)
			philo_taken_fork(philo);
		else
			return ;
	}
	philo_put_down(philo);
}
 
void	*execution_thread(void *philos)
{
	t_philo *philo;
	int		i;

	i = 1;
	philo = (t_philo *)philos;
	while (1)
	{
		while (*(philo->exit) == 1)
		{
			if (i == 1)
			{
				philo->eating_time = *(philo->start_time);
				i = 2;
			}
			if (philo->time_data[0] % 2 == 0)
				philo_eating_even(philo);
			else
				philo_eating_odd(philo);
			usleep(50);
		}
		philo->eating_time = *(philo->start_time);
		usleep(50);
	}
}

void	mutex_init(t_list *data, pthread_mutex_t *print)
{
	int		i;

	i = 0;
	pthread_mutex_init(print, NULL);
	while (i < data->time_data[0])
	{
		pthread_mutex_init(&(data->philo->fork), NULL);
		data->philo->print = print;
		data->philo = data->philo->next;
		i++;
	}
}

void	creat_thread(t_list *data, int *exit, size_t *time)
{
	int		i;

	i = 0;
	*time = calculate_time(0);
	*exit = 0;
	while (i < data->time_data[0])
	{
		data->philo->exit = exit;
		data->philo->eating_count = 0;
		data->philo->start_time = time;
		data->philo->eating_time = *time;
		pthread_create(&(data->philo->thread), NULL, execution_thread, (void *)(data->philo));
		data->philo = data->philo->next;
		i++;
		if (i == data->time_data[0])
		{
			*time = calculate_time(0);
			*exit = 1;
		}
	}
}

void	wait_thread(t_list *data, int *exit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(data->philo->exit) == 1)
	{
		if (data->philo->eating_count >= data->time_data[4] && data->time_data[4] != -1)
			j++;
		if (calculate_time(data->philo->eating_time) > (size_t)(data->time_data[1] * 1000))
		{
			pthread_mutex_lock(data->philo->print);
			printf("%lu %d dead\n",calculate_time(*(data->philo->start_time)) / 1000, data->philo->num);
			*exit = 0;
			break ;
		}
		if (j == data->time_data[0])
		{
			*exit = 0;
			return ;
		}
		data->philo = data->philo->next;
		i++;
		if (i == data->time_data[0])
		{
			i = 0;
			j = 0;
		}
	}
}

void	destroy_thread_mutex(t_list *data, pthread_mutex_t *print)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		pthread_detach(data->philo->thread);
		i++;
		data->philo = data->philo->next;
	}
	i = 0;
	while (i < data->time_data[0])
	{
		pthread_mutex_destroy(&(data->philo->fork));
		i++;
		data->philo = data->philo->next;
	}
	pthread_mutex_destroy(print);
}

int	main(int argc, char **argv)
{
	t_list			data;
	size_t			time;
	int				i;
	int				exit;
	pthread_mutex_t	print;

	i = 0;
	if (input_init(argc, argv, &data) == -1)
		return (-1);
	if (make_philosophers(&data) == -1)
		return (-1);
	if (data.time_data[4] == 0)
		return (0);
	mutex_init(&data, &print);
	creat_thread(&data, &exit, &time);
	wait_thread(&data, &exit);
	destroy_thread_mutex(&data, &print);
}
