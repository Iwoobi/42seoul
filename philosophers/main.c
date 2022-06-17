/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:22 by youhan            #+#    #+#             */
/*   Updated: 2022/06/17 21:58:47 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ft_input_unique(int *arr, int argc)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		j = i + 1;
// 		while (j < argc - 1)
// 		{
// 			if (arr[i] == arr[j])
// 				return (-1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_list			data;
	size_t			time;
	int				i;
	int				exit;
	pthread_mutex_t	print;

	i = 0;
	if (input_init(argc, argv, &data) == -1)
		return (-1);
	if (make_philosophers(&data) == -1)
		return (-1);
	if (data.time_data[4] == 0)
		return (0);
	mutex_init(&data, &print);
	creat_thread(&data, &exit, &time);
	wait_thread(&data, &exit);
	destroy_thread_mutex(&data, &print);
}
