/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:49:09 by youhan            #+#    #+#             */
/*   Updated: 2022/06/20 18:30:41 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
