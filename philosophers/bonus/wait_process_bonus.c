/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:41:30 by youhan            #+#    #+#             */
/*   Updated: 2022/06/24 17:41:31 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*must_eat_count(void *datas)
{
	t_list	*data;
	int		i;

	i = 0;
	data = (t_list *)datas;
	data->check = 0;
	usleep(data->time_data[1] * 500);
	while (i < data->time_data[0])
	{
		data->check += 1;
		sem_contral(data->philo->all_count, PUT_UP);
		usleep(100);
		i++;
	}
	data->status = 1;
	i = 0;
	while (i < data->time_data[0])
	{
		sem_contral(data->philo->all_count, PUT_DOWN);
		i++;
		usleep(100);
		data->check -= 1;
	}
	return (NULL);
}

void	wait_process_while(t_list *data)
{
	int		status;
	pid_t	j;
	int		i;

	i = 0;
	while (1)
	{
		j = waitpid(data->philo->pid_id[i], &status, WNOHANG);
		if (j > 0)
		{
			if (WEXITSTATUS(status) == 1)
			{
				pthread_detach(data->philo->thread);
				return ;
			}
		}
		if (data->status == 1)
		{
			pthread_join(data->philo->thread, NULL);
			return ;
		}
		usleep(50);
		i++;
		i = i % data->time_data[0];
	}
}

void	wait_process(t_list *data)
{
	data->status = 0;
	pthread_create(&data->philo->thread, NULL, must_eat_count, (void *)data);
	wait_process_while(data);
}
