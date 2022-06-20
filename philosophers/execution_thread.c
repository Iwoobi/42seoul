/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:53:45 by youhan            #+#    #+#             */
/*   Updated: 2022/06/20 17:33:47 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*execution_thread(void *philos)
{
	t_philo	*philo;
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
