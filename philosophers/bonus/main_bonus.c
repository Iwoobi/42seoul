/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:44:47 by youhan            #+#    #+#             */
/*   Updated: 2022/06/20 22:04:33 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	semaphore_init(t_list *data, sem_t **fork, sem_t **print, sem_t **count)
{
	int	i;

	i = 0;
	*fork = sem_open("fork", O_CREAT, 0744, data->time_data[0]);
	*print = sem_open("print",  O_CREAT, 0744, 1);
	*count = sem_open("count", O_CREAT, 0744, 0);
	while (i < data->time_data[0])
	{
		data->philo->print = print;
		data->philo->pid_id = 1;
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
	}
	return (1);
}

void	make_process(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->time_data[0])
	{
		if (philo_check(data) != 0)
		{
			data->philo->pid_id = fork();
			if (data->philo->pid_id == 0)
				creat_thread(data);
		}
		data->philo = data->philo->next;
		i++;		
	}
}

int	check_status(t_list *data)
{
	sem_post(*(data->philo->all_count));
	if (**(data->philo->all_count) == data->time_data[0])
	{
		sem_post(*(data->philo->print));
		return (1);
	}
	sem_wait(*(data->philo->all_count));
	return (0);
}
void	wait_process(t_list *data)
{
	pid_t	j;
	int		status;

	while (1)
	{
		j = waitpid(data->philo->pid_id, &status, WNOHANG);
		if (j > 0)
		{
			if (WEXITSTATUS(status) == 1)
			{
				sem_post(*(data->philo->print));
				print_philo_status_bonus(data->philo, DEAD);
				return ;
			}
			if (check_status(data) == 1)
				return ;
		}
		data->philo = data->philo->next;
	}
}

void	make_data_status(t_list *data)
{
	int	i;

	i = 0;
	data->status = (int *)malloc(sizeof(int) * data->time_data[0]);
	if (data->status == NULL)
		exit(-1);
	while (i < data->time_data[0])
	{
		data->status[i] = 0; 
		i++;
	}
}

// void	close_semaphore(t_list *data)
// {
	
// }

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
	make_data_status(&data);
	semaphore_init(&data, &fork, &print, &count);
	make_process(&data);
	wait_process(&data);
	// close_semaphore(&data);
}
