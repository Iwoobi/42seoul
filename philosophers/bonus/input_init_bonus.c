/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:45:42 by youhan            #+#    #+#             */
/*   Updated: 2022/06/20 17:42:04 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_all_num_check(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '+')
		i++;
	while (argv[i] != '\0')
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

int	input_check(char **argv, t_list *data)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (input_all_num_check(argv[i]) == -1)
			return (-1);
		i++;
	}
	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) > 2148473647)
			return (-1);
		data->time_data[i - 1] = ft_atoi(argv[i]);
		if (data->time_data[i - 1] == 0 && i - 1 != 5)
			return (-1);
		i++;
	}
	if (i == 5)
		data->time_data[4] = -1;
	return (1);
}

int	input_init(int argc, char **argv, t_list *data)
{
	if (!(argc == 5 || argc == 6))
		return (-1);
	if (input_check(argv, data) == -1)
		return (-1);
	return (1);
}
