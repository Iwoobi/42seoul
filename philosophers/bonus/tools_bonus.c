/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:13:56 by youhan            #+#    #+#             */
/*   Updated: 2022/06/23 22:18:39 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	calculate_time(size_t p_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 * 1000 + time.tv_usec - p_time);
}

void	ft_usleep(size_t time)
{
	size_t	start_time;

	start_time = calculate_time(0);
	while (calculate_time(0) - start_time < time)
	{
		usleep(100);
	}
}

void	sem_contral(sem_t **sem, int mod)
{
	if (mod == PUT_UP)
		sem_wait(*sem);
	else
		sem_post(*sem);
	return ;
}

void	print_philo_status_bonus(t_philo *philo, int status)
{
	int		num;
	size_t	time;

	num = philo->num;
	sem_contral(philo->print, PUT_UP);
	time = calculate_time(philo->start_time) / 1000;
	if (status == TAKEN_FORK)
		printf("%ld %d has taken a fork\n", time, num);
	else if (status == EAT)
	{	
		printf("%ld %d is eating\n", time, num);
		return ;
	}
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, num);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, num);
	else if (status == DEAD)
	{
		printf("%ld %d died\n", time, num);
		return ;
	}
	sem_contral(philo->print, PUT_DOWN);
}
