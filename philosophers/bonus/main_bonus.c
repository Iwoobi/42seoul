/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:44:47 by youhan            #+#    #+#             */
/*   Updated: 2022/06/24 18:12:10 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
