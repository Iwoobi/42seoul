/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:18:07 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:09:27 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	process_num(t_list data, int pid)
{
	int	i;

	if (pid == 0)
	{
		i = 0;
		while (i < data.pipe_num + 1)
		{
			if (data.pid[i] == 0)
				return (-1);
			i++;
		}
		return (1);
	}
	else
	{
		if (data.pid[pid - 1] == 0)
			return (1);
	}
	return (-1);
}
