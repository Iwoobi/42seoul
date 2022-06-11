/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:52 by youhan            #+#    #+#             */
/*   Updated: 2022/06/11 21:22:25 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int		fork;
	int		status;
	struct s_philo *next;
	struct s_philo *prev;
}	t_philo;

typedef struct s_list
{
	int 	time_data[5];
	t_philo *philo;
}	t_list;



#endif