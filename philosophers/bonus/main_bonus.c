/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:44:47 by youhan            #+#    #+#             */
/*   Updated: 2022/06/23 22:29:59 by youhan           ###   ########.fr       */
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

int	philo_check(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		if (data->philo->pid_id[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	start_process(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		if (data->philo->pid_id[i] == 0)
		{
			data->philo->num = i + 1;
			creat_thread(data->philo);
		}
		i++;
	}
}

void	make_process(t_list *data)
{
	int		i;
	size_t	time;

	time = calculate_time(0);
	data->philo->start_time = time;
	data->philo->eating_time = time;
	i = 0;
	while (i < data->time_data[0])
	{
		if (philo_check(data) == 1)
		{
			data->philo->pid_id[i] = fork();
			if (data->philo->pid_id[i] == -1)
				exit(1);
		}
		else
			break ;
		i++;
	}
	if (philo_check(data) == 0)
		start_process(data);
}

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

int	main(int argc, char **argv)
{
	t_list			data;
	sem_t			*print;
	sem_t			*fork;
	sem_t			*count;

	if (input_init(argc, argv, &data) == -1)
		return (-1);
	make_philosophers(&data);
	if (data.time_data[4] == 0)
		return (0);
	semaphore_init(&data, &fork, &print, &count);
	make_process(&data);
	wait_process(&data);
	kill_process(&data);
	semaphore_put_down(&data);
	semaphore_close(&print, &fork, &count);
}
