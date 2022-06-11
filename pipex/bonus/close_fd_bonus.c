/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:31:29 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 02:26:51 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	all_close_write_pipe_fd(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->pipe_num)
	{
		close(data->p_fd[i][1]);
		i++;
	}
	if (data->bonus_mod == 1)
		close(data->in_file_fd[1]);
}

void	all_close_read_pipe_fd(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->pipe_num)
	{
		close(data->p_fd[i][0]);
		i++;
	}
	if (data->bonus_mod == 1)
		close(data->in_file_fd[0]);
}

void	close_fd(t_list *data)
{
	if (data->bonus_mod != 1)
		close(data->fd.r_fd);
	close(data->fd.w_fd);
	all_close_read_pipe_fd(data);
	all_close_write_pipe_fd(data);
}
