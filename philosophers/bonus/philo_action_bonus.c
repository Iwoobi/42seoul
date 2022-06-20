/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:04:51 by youhan            #+#    #+#             */
/*   Updated: 2022/06/20 20:39:01 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_think(t_philo *philo)
{
	print_philo_status_bonus(philo, THINK);
}

void	philo_sleep(t_philo *philo)
{
	print_philo_status_bonus(philo, SLEEP);
	ft_usleep(philo->time_data[SLEEP_TIME] * 1000);
	philo_think(philo);
}

void	philo_taken_fork(t_philo *philo)
{
	sem_contral(philo->fork, PUT_UP);
	print_philo_status_bonus(philo, TAKEN_FORK);
	sem_contral(philo->fork, PUT_UP);
	print_philo_status_bonus(philo, TAKEN_FORK);
}

void	philo_put_down(t_philo *philo)
{
	print_philo_status_bonus(philo, EAT);
	philo->eating_count += 1;
	philo->eating_time = calculate_time(0);
	ft_usleep(philo->time_data[EAT_TIME] * 1000);
	sem_contral(philo->fork, PUT_DOWN);
	sem_contral(philo->fork, PUT_DOWN);
	philo_sleep(philo);
}
