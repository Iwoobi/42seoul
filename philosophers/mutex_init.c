/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:50:04 by youhan            #+#    #+#             */
/*   Updated: 2022/06/20 17:33:58 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
