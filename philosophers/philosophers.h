/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:52 by youhan            #+#    #+#             */
/*   Updated: 2022/06/16 22:41:21 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
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
	struct s_philo 	*next;
	struct s_philo 	*prev;
	int				diff_error;
}	t_philo;

typedef struct s_list
{
	int 	time_data[5];
	t_philo *philo;
}	t_list;



#endif