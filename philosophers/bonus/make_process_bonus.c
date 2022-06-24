/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:41:23 by youhan            #+#    #+#             */
/*   Updated: 2022/06/24 18:14:45 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_check(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		if (data->philo->pid_id[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	start_process(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		if (data->philo->pid_id[i] == 0)
		{
			data->philo->num = i + 1;
			creat_thread(data->philo);
		}
		i++;
	}
}

void	make_process(t_list *data)
{
	int		i;
	size_t	time;

	time = calculate_time(0);
	data->philo->start_time = time;
	data->philo->eating_time = time;
	i = 0;
	while (i < data->time_data[0])
	{
		if (philo_check(data) == 1)
		{
			data->philo->pid_id[i] = fork();
			if (data->philo->pid_id[i] == -1)
				exit(1);
		}
		else
			break ;
		i++;
	}
	if (philo_check(data) == 0)
		start_process(data);
}
