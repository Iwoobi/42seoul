/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:15:00 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:07:43 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_process(t_list *data)
{
	int	i;
	int	j;
	int	child;

	i = 0;
	while (i < data->pipe_num + 1)
	{
		j = 0;
		child = 0;
		while (j < data->pipe_num + 1)
		{
			if (data->pid[j] == 0)
				child = 1;
			j++;
		}
		if (child == 0)
		{
			data->pid[i] = fork();
			if (data->pid[i] == -1)
				error_code(2);
		}
		i++;
	}
}
