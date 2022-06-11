/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contral_first_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:29:03 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 03:38:50 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	contral_first_process(t_list *data)
{
	int		i;
	int		status;
	pid_t	j;

	if (data->bonus_mod == 1)
		push_infile_data(data);
	else
		close_fd(data);
	while (1)
	{
		i = 0;
		while (i < data->pipe_num + 1)
		{
			j = waitpid(data->pid[i], &status, WNOHANG);
			if (j > 0)
			{
				if (i == data->pipe_num)
				{
					data->status = WEXITSTATUS(status);
					return ;
				}
			}
			i++;
		}
	}
}
