/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:51:52 by youhan            #+#    #+#             */
/*   Updated: 2022/06/17 21:52:55 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	print_philo_status(t_philo *philo, int status)
{
	int		num;
	size_t	time;

	num = philo->num;
	pthread_mutex_lock(philo->print);
	time = calculate_time(*(philo->start_time)) / 1000;
	if (*(philo->exit) == 0)
		return ;
	else if (status == TAKEN_FORK)
		printf("%ld %d has taken a fork\n", time, num);
	else if (status == EAT)
		printf("%ld %d is eating\n", time, num);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, num);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, num);
	else if (status == DEAD)
		printf("%ld %d died\n", time, num);
	pthread_mutex_unlock(philo->print);
}