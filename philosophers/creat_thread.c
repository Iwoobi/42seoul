/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:51:05 by youhan            #+#    #+#             */
/*   Updated: 2022/06/17 21:51:54 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		pthread_create(&(data->philo->thread),
			NULL, execution_thread, (void *)(data->philo));
		data->philo = data->philo->next;
		i++;
		if (i == data->time_data[0])
		{
			*time = calculate_time(0);
			*exit = 1;
		}
	}
}