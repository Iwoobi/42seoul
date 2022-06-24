/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:41:58 by youhan            #+#    #+#             */
/*   Updated: 2022/06/24 18:12:03 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_process(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		kill(data->philo->pid_id[i], SIGKILL);
		i++;
	}
}

void	semaphore_close(sem_t **print, sem_t **fork, sem_t **count)
{
	sem_close(*print);
	sem_close(*fork);
	sem_close(*count);
	sem_unlink("fork");
	sem_unlink("count");
	sem_unlink("print");
}

void	semaphore_put_down(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		sem_contral(data->philo->all_count, PUT_DOWN);
		data->check -= 1;
		i++;
	}
	sem_contral(data->philo->print, PUT_DOWN);
}
