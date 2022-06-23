/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_thread_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:50:03 by youhan            #+#    #+#             */
/*   Updated: 2022/06/23 22:17:00 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	execution_thread(t_philo *philo)
{
	while (1)
	{
		if (philo->time_data[0] % 2 == 0)
			philo_eating_even(philo);
		else
			philo_eating_odd(philo);
		usleep(100);
	}
}

void	*wait_thread(void	*philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (1)
	{
		if (calculate_time(philo->eating_time)
			> (size_t)(philo->time_data[1] * 1000))
		{
			sem_contral(philo->all_count, PUT_DOWN);
			print_philo_status_bonus(philo, DEAD);
			exit(1);
		}
		usleep(100);
	}
}

void	creat_thread(t_philo *philo)
{
	philo->eating_count = 0;
	sem_contral(philo->all_count, PUT_UP);
	pthread_create(&(philo->thread),
		NULL, wait_thread, (void *)(philo));
	execution_thread(philo);
	exit(1);
}
