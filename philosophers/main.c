/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:22 by youhan            #+#    #+#             */
/*   Updated: 2022/06/11 21:25:49 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

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
	t_philo	*last_philo;
	t_philo	*prev_philo;

	first_philo = data->philo;
	i = 1;
	while (i < data->time_data[0])
	{
		prev_philo = data->philo;
		data->philo->next = (t_philo *)malloc(sizeof(t_philo));
		if (data->philo->next == NULL)
			return (-1);
		data->philo->next->fork = i + 1;
		data->philo->next->status = 0;
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
	data->philo->fork = 1;
	data->philo->status = 0;
	data->philo->next = NULL;
	data->philo->prev = NULL;
	if (make_philo(data) == -1)
		return (-1);
	return (1);
}

// int	make_mutex_resource(t_list *data)
// {
	
// }

void	print_time_data(t_list data)
{
	printf("philo : %d\n", data.time_data[0]);
	printf("die : %d\n", data.time_data[1]);
	printf("eat : %d\n", data.time_data[2]);
	printf("sleep : %d\n", data.time_data[3]);
	printf("must : %d\n", data.time_data[4]);
}

void	print_philo(t_list data)
{
	int	i;
	t_philo *next_p;
	i = 0;
	next_p = data.philo;
	while (i < data.time_data[0] * 2)
	{
		printf("%d philo fork = %d\n", i, next_p->fork);
		next_p = next_p->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	data;

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
	

}