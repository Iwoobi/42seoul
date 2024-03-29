/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:39:05 by youhan            #+#    #+#             */
/*   Updated: 2022/06/24 18:15:21 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define EAT 1
# define THINK 2
# define SLEEP 3
# define DEAD 0
# define TAKEN_FORK 4
# define N 0
# define DEAD_TIME 1
# define EAT_TIME 2
# define SLEEP_TIME 3
# define PUT_DOWN 1
# define PUT_UP 2

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <stdio.h>
# include <signal.h>

typedef struct s_philo
{
	int				num;
	int				*time_data;
	int				eating_count;
	pid_t			*pid_id;
	sem_t			**fork;
	sem_t			**print;
	sem_t			**all_count;
	pthread_t		thread;
	size_t			start_time;
	size_t			eating_time;
}	t_philo;

typedef struct s_list
{
	int		time_data[5];
	int		status;
	int		check;
	t_philo	*philo;
}	t_list;

int			ft_strlen(char *str);
void		ft_usleep(size_t time);
long long	ft_atoi(char *str);
size_t		calculate_time(size_t p_time);
void		print_philo_status_bonus(t_philo *philo, int status);
void		sem_contral(sem_t **sem, int mod);
int			input_init(int argc, char **argv, t_list *data);
void		make_philosophers(t_list *data);
void		creat_thread(t_philo *philo);
void		philo_put_down(t_philo *philo);
void		philo_taken_fork(t_philo *philo);
void		philo_eating_even(t_philo *philo);
void		philo_eating_odd(t_philo *philo);
void		wait_process(t_list *data);
void		semaphore_init(t_list *data, sem_t **fork,
				sem_t **print, sem_t **count);
void		kill_process(t_list *data);
void		semaphore_close(sem_t **print, sem_t **fork, sem_t **count);
void		semaphore_put_down(t_list *data);
void		make_process(t_list *data);

#endif