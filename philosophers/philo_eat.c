/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:54:12 by youhan            #+#    #+#             */
/*   Updated: 2022/06/17 21:56:15 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eating_odd(t_philo *philo)
{
	if (philo->num % 2 == 1 && philo->num != philo->time_data[0])
	{
		if (((calculate_time(*(philo->start_time))
					/ (philo->time_data[2] * 1000)) % 3) == 0)
			philo_taken_fork(philo);
		else
			return ;
	}
	else if (philo->num % 2 == 0)
	{
		if (((calculate_time(*(philo->start_time))
					/ (philo->time_data[2] * 1000)) % 3) == 1)
			philo_taken_fork(philo);
		else
			return ;
	}
	else
	{
		if (((calculate_time(*(philo->start_time))
					/ (philo->time_data[2] * 1000)) % 3) == 2)
			philo_taken_fork(philo);
		else
			return ;
	}
	philo_put_down(philo);
}

void	philo_eating_even(t_philo *philo)
{
	if (philo->num % 2 == 1)
	{
		if (((calculate_time(*(philo->start_time))
					/ (philo->time_data[2] * 1000)) % 2) == 0)
			philo_taken_fork(philo);
		else
			return ;
	}
	else if (philo->num % 2 == 0)
	{
		if (((calculate_time(*(philo->start_time))
					/ (philo->time_data[2] * 1000)) % 2) == 1)
			philo_taken_fork(philo);
		else
			return ;
	}
	philo_put_down(philo);
}