/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:31:29 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 02:28:28 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	all_close_write_pipe_fd(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->pipe_num)
	{
		close(data->p_fd[i][1]);
		i++;
	}
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
}

void	close_fd(t_list *data)
{
	close(data->fd.r_fd);
	close(data->fd.w_fd);
	all_close_read_pipe_fd(data);
	all_close_write_pipe_fd(data);
}
