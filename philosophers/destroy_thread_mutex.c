/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_thread_mutex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:58:26 by youhan            #+#    #+#             */
/*   Updated: 2022/06/20 17:33:42 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
