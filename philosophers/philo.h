/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:41:22 by youhan            #+#    #+#             */
/*   Updated: 2022/06/20 17:35:10 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define EAT 1
# define THINK 2
# define SLEEP 3
# define DEAD 0
# define TAKEN_FORK 4
# define N 0
# define DEAD_TIME 1
# define EAT_TIME 2
# define SLEEP_TIME 3
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo
{
	int				num;
	int				eating_count;
	pthread_t		thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	fork;
	int				*time_data;
	size_t			*start_time;
	size_t			eating_time;
	int				*exit;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;

typedef struct s_list
{
	int		time_data[5];
	t_philo	*philo;
}	t_list;

size_t		calculate_time(size_t p_time);
void		ft_usleep(size_t time);
void		print_philo_status(t_philo *philo, int status);
int			ft_strlen(char *str);
long long	ft_atoi(char *str);
int			input_init(int argc, char **argv, t_list *data);
int			input_all_num_check(char *argv);
int			input_check(char **argv, t_list *data);
int			make_philo(t_list *data);
int			make_philosophers(t_list *data);
void		mutex_init(t_list *data, pthread_mutex_t *print);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_taken_fork(t_philo *philo);
void		philo_put_down(t_philo *philo);
void		philo_eating_even(t_philo *philo);
void		philo_eating_odd(t_philo *philo);
void		*execution_thread(void *philos);
void		creat_thread(t_list *data, int *exit, size_t *time);
void		wait_thread(t_list *data, int *exit);
void		destroy_thread_mutex(t_list *data, pthread_mutex_t *print);

#endif