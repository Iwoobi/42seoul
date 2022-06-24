/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:57:50 by youhan            #+#    #+#             */
/*   Updated: 2022/06/24 18:20:19 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_thread_check(t_list *data, int *exit, int *i, int *j)
{
	if (*j == data->time_data[0])
	{
		*exit = 0;
		return ;
	}
	data->philo = data->philo->next;
	*i += 1;
	if (*i == data->time_data[0])
	{
		*i = 0;
		*j = 0;
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
		if (data->philo->eating_count >= data->time_data[4]
			&& data->time_data[4] != -1)
			j++;
		if (calculate_time(data->philo->eating_time)
			> (size_t)(data->time_data[1] * 1000))
		{
			pthread_mutex_lock(data->philo->print);
			printf("%lu %d dead\n", calculate_time(*(data->philo->start_time))
				/ 1000, data->philo->num);
			*exit = 0;
			break ;
		}
		wait_thread_check(data, exit, &i, &j);
		usleep(50);
	}
}
