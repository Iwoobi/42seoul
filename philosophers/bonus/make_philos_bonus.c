/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:49:09 by youhan            #+#    #+#             */
/*   Updated: 2022/06/23 22:17:42 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	make_philo(t_list *data)
{
	int	i;

	i = 0;
	data->philo->num = i + 1;
	data->philo->time_data = data->time_data;
	data->philo->pid_id = (pid_t *)malloc(sizeof(pid_t) * data->time_data[0]);
	if (data->philo->pid_id == NULL)
		exit(-1);
	while (i < data->time_data[0])
	{
		data->philo->pid_id[i] = i + 1;
		i++;
	}
}

void	make_philosophers(t_list *data)
{
	if (data->time_data[0] == 0)
		exit(-1);
	data->philo = (t_philo *)malloc(sizeof(t_philo));
	if (data->philo == NULL)
		exit(-1);
	data->philo->num = 1;
	data->philo->time_data = data->time_data;
	make_philo(data);
}
