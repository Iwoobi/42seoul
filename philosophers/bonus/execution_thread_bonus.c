/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_thread_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:50:03 by youhan            #+#    #+#             */
/*   Updated: 2022/06/21 05:43:55 by youhan           ###   ########.fr       */
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
		usleep(50);
	}
}

void	*wait_thread(void	*philos)
{
	t_philo *philo;
	int		i;
	
	i = 0;
	philo = (t_philo *)philos;
	while (1)
	{
		if (calculate_time(philo->eating_time)
			> (size_t)(philo->time_data[1] * 1000))
		{
			print_philo_status_bonus(philo, DEAD);
			exit(1);
		}
		if (philo->eating_count >= philo->time_data[4] && philo->time_data[4] != -1 && i == 0)
		{
			sem_contral(philo->all_count, PUT_DOWN);
			i = 1;
		}
	}
}

void	creat_thread(t_philo *philo)
{
	// int		i;
	// size_t	time;

	// i = 0;
	// philo->eating_count = 0;
	// sem_contral(philo->all_count, PUT_UP);
	// time = calculate_time(0);
	// philo->start_time = time;
	// philo->eating_time = time;
	// pthread_create(&(philo->thread),
	// 	NULL, wait_thread, (void *)(philo));
	// execution_thread(philo);
	printf("num : %d\n", philo->num);
	exit(1);
}
