/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:22 by youhan            #+#    #+#             */
/*   Updated: 2022/06/13 22:48:31 by youhan           ###   ########.fr       */
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

void	print_phlio_status(int num, int status)
{
	char	*philo;

	if (status == TAKEN_FORK)
		printf("%d has taken a fork\n",num);
	if (status == EAT)
		printf("%d is eating\n", num);
	if (status == THINK)
		printf("%d is thinking\n", num);
	if (status == SLEEP)
		printf("%d is sleeping\n", num);
	if (status == DEAD)
		printf("%d died\n", num);
	
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
		data->philo->next->status = THINK;
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
	t_philo	*first_philo;

	if (data->time_data[0] == 0)
		return (-1);
	data->philo = (t_philo *)malloc(sizeof(t_philo));
	if (data->philo == NULL)
		return (-1);
	data->philo->num = 1;
	data->philo->time_data = data->time_data;
	data->philo->status = THINK;
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

// void	print_philo(t_list data)
// {
// 	int	i;
// 	t_philo *next_p;
// 	i = 0;
// 	next_p = data.philo;
// 	while (i < data.time_data[0] * 2)
// 	{
// 		printf("%d philo fork = %d\n", i, next_p->fork);
// 		next_p = next_p->next;
// 		i++;
// 	}
// }
void	philo_think(t_philo *philo)
{
	philo->status = THINK;
	print_phlio_status(philo->num, THINK);
}
void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEP;
	print_phlio_status(philo->num, SLEEP);
	usleep(philo->time_data[SLEEP_TIME]);
	philo_think(philo);
}
void	philo_eating(t_philo *philo)
{
	if (philo->prev->status != EAT && philo->next->status != EAT)
	{
		if (philo->num % 2 == 0)
		{
			pthread_mutex_lock(&(philo->fork));
			pthread_mutex_lock(&(philo->prev->fork));
		}
		else
		{
			pthread_mutex_lock(&(philo->prev->fork));
			pthread_mutex_lock(&(philo->fork));
		}
		
		print_phlio_status(philo->num, TAKEN_FORK);
		print_phlio_status(philo->num, TAKEN_FORK);
		philo->status = EAT;
		print_phlio_status(philo->num, EAT);
		usleep(philo->time_data[EAT_TIME]);
		philo->eating_time = calculate_time(0);
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->prev->fork));
		philo_sleep(philo);
	}
}

void	*execution_thread(void *philos)
{
	t_philo *philo;
	philo = (t_philo *)philos;
	while (1)
	{
		philo_eating(philo);
		if (calculate_time(philo->eating_time) > philo->time_data[1] * 1000)
		{
			printf("%d dead\n", philo->num);
				return (NULL);
		}
	}
}

void	mutex_init(t_list *data)
{
	int		i;
	size_t	time;
	i = 0;
	time = calculate_time(0);
	while (i < data->time_data[0])
	{
		data->philo->start_time = time;
		data->philo->eating_time = time;
		pthread_mutex_init(&(data->philo->fork), NULL);
		data->philo = data->philo->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	data;
	int		i;

	i = 0;
	if (input_init(argc, argv, &data) == -1)
	{
		printf("error\n");
		return (-1);
	}
	if (make_philosophers(&data) == -1)
	{
		printf("error2\n");
		return (-1);
	}
	mutex_init(&data);
	while (i < data.time_data[0])
	{
		pthread_create(&(data.philo->thread),NULL, execution_thread, (void *)(data.philo));
		data.philo = data.philo->next;
		i++;
	}
	i = 0;
	while (i < data.time_data[0])
	{
		pthread_join(data.philo->thread, 0);
		i++;
		data.philo = data.philo->next;
	}
	

}