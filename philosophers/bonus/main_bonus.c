/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:44:47 by youhan            #+#    #+#             */
/*   Updated: 2022/06/21 05:44:26 by youhan           ###   ########.fr       */
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
	*print = sem_open("print",  O_CREAT, 0744, 1);
	*count = sem_open("count", O_CREAT, 0744, data->time_data[0]);
	while (i < data->time_data[0])
	{
		data->philo->print = print;
		data->philo->pid_id = 1 + i;
		data->philo->all_count = count;
		data->philo->fork = fork;
		data->philo->eating_count = 0;
		data->philo = data->philo->next;
		i++;
	}
}

int	philo_check(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		if (data->philo->pid_id == 0)
			return (0);
		i++;
		data->philo = data->philo->next;
	}
	return (1);
}

void	make_process(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		if (philo_check(data) == 1)
		{
			printf("pid : %d %d\n",data->philo->pid_id, data->philo->next->pid_id);
			data->philo->pid_id = fork();
			if (data->philo->pid_id == -1)
				exit(1);
		}
		data->philo = data->philo->next;
		i++;
	}
	printf("pid : %d %d\n",data->philo->pid_id, data->philo->next->pid_id);
	printf("i %d \n", i);

	i = 0;
	
	while (i < data->time_data[0])
	{
		if (data->philo->pid_id == 0)
		{
			creat_thread(data->philo);
		}
		data->philo = data->philo->next;
		i++;
	}
}

void	*must_eat_count(void *datas)
{
	t_list	*data;
	int		i;

	i = 0;
	data = (t_list *)datas;
	data->check = 0;
	while (i < data->time_data[0])
	{
		data->check += 1;
		sem_contral(data->philo->all_count, PUT_UP);
		i++;
	}
	i = 0;
	while (i < data->time_data[0])
	{
		sem_contral(data->philo->all_count, PUT_DOWN);
		i++;
		data->check -= 1;
	}
	sem_contral(data->philo->print, PUT_UP);
	data->status = 1;
	return (NULL);
}

void	kill_process(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		kill(data->philo->pid_id, SIGKILL);
		i++;
		data->philo = data->philo->next;
	}
}

void	wait_process(t_list *data)
{
	pid_t		j;
	pthread_t	thread;
	int			status;

	data->status = 0;
	pthread_create(&thread, NULL, must_eat_count, (void *)data);
	while (1)
	{
		j = waitpid(data->philo->pid_id, &status, WNOHANG);
		if (j > 0)
		{
			if (WEXITSTATUS(status) == 1)
			{
				pthread_detach(thread);
				return ;
			}
		}
		if (data->status == 1)
		{
			pthread_join(thread, NULL);
			return ;
		}
		data->philo = data->philo->next;
	}
}

void	semaphore_close(sem_t **print, sem_t **fork, sem_t **count)
{
	printf("print\n");
	sem_close(*print);
	printf("fork\n");
	sem_close(*fork);
	printf("count\n");
	sem_close(*count);
	printf("unlink1\n");
	sem_unlink("fork");

	printf("unlink2\n");
	sem_unlink("count");
	printf("unlink3\n");
	sem_unlink("print");
	printf("unlink4\n");
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
	printf("check\n");
	sem_contral(data->philo->print, PUT_DOWN);
	printf("printf\n");
}

int	main(int argc, char **argv)
{
	t_list			data;
	sem_t			*print;
	sem_t			*fork;
	sem_t			*count;

	if (input_init(argc, argv, &data) == -1)
		return (-1);
	if (make_philosophers(&data) == -1)
		return (-1);
	if (data.time_data[4] == 0)
		return (0);
	printf("%d\n", data.time_data[0]);
	semaphore_init(&data, &fork, &print, &count);
	make_process(&data);
	wait_process(&data);
	kill_process(&data);
	semaphore_put_down(&data);
	semaphore_close(&print, &fork, &count);
}
