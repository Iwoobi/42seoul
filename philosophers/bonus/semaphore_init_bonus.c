/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:41:36 by youhan            #+#    #+#             */
/*   Updated: 2022/06/24 17:41:37 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	semaphore_init(t_list *data, sem_t **fork, sem_t **print, sem_t **count)
{
	int	i;

	i = 0;
	sem_unlink("fork");
	sem_unlink("count");
	sem_unlink("print");
	*fork = sem_open("fork", O_CREAT, 0744, data->time_data[0]);
	*print = sem_open("print", O_CREAT, 0744, 1);
	*count = sem_open("count", O_CREAT, 0744, data->time_data[0]);
	data->philo->print = print;
	data->philo->all_count = count;
	data->philo->fork = fork;
	data->philo->eating_count = 0;
}
