/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:39:05 by youhan            #+#    #+#             */
/*   Updated: 2022/06/17 21:44:36 by youhan           ###   ########.fr       */
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

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int				num;
	int				eating_count;
	pthread_mutex_t	*print;
	int				*time_data;
	size_t			*start_time;
	size_t			eating_time;
	int				*exit;
	struct s_philo 	*next;
	struct s_philo 	*prev;
}	t_philo;

typedef struct s_list
{
	int 	time_data[5];
	t_philo *philo;
}	t_list;

#endif