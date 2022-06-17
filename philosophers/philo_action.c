/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:55:22 by youhan            #+#    #+#             */
/*   Updated: 2022/06/17 21:56:35 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	print_philo_status(philo, THINK);
}

void	philo_sleep(t_philo *philo)
{
	print_philo_status(philo, SLEEP);
	ft_usleep(philo->time_data[SLEEP_TIME] * 1000);
	philo_think(philo);
}

void	philo_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	print_philo_status(philo, TAKEN_FORK);
	pthread_mutex_lock(&(philo->prev->fork));
	print_philo_status(philo, TAKEN_FORK);
}

void	philo_put_down(t_philo *philo)
{
	print_philo_status(philo, EAT);
	philo->eating_count += 1;
	philo->eating_time = calculate_time(0);
	ft_usleep(philo->time_data[EAT_TIME] * 1000);
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(&(philo->prev->fork));
	philo_sleep(philo);
}