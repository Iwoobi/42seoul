/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contral_pipe_pid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:15:47 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:06:01 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	contral_mid_process(t_list *data, int process, char **env)
{
	char	*dir_cmd;

	dup2(data->p_fd[process - 1][0], 0);
	dup2(data->p_fd[process][1], 1);
	all_close_write_pipe_fd(data);
	all_close_read_pipe_fd(data);
	exist_cmd(data, process, &dir_cmd);
	if (execve(dir_cmd, data->cmd[process], env) == -1)
		error_cmd(data, data->cmd[process][0]);
	free(dir_cmd);
}

void	contral_last_process(t_list *data, char **env)
{
	char	*dir_cmd;

	dup2(data->p_fd[data->pipe_num - 1][0], 0);
	dup2(data->fd.w_fd, 1);
	all_close_write_pipe_fd(data);
	all_close_read_pipe_fd(data);
	exist_cmd(data, data->pipe_num, &dir_cmd);
	if (execve(dir_cmd, data->cmd[data->pipe_num], env) == -1)
		error_cmd(data, data->cmd[data->pipe_num][0]);
	free(dir_cmd);
}

void	contral_first_cmd_process(t_list *data, char **env)
{
	char	*dir_cmd;

	if (data->fd.r_fd == -1)
		error_file(data);
	dup2(data->fd.r_fd, 0);
	dup2(data->p_fd[0][1], 1);
	close(data->fd.r_fd);
	all_close_write_pipe_fd(data);
	all_close_read_pipe_fd(data);
	exist_cmd(data, 0, &dir_cmd);
	if (execve(dir_cmd, data->cmd[0], env) == -1)
		error_cmd(data, data->cmd[0][0]);
	free(dir_cmd);
}

void	contral_pipe_pid(t_list *data, char **env)
{
	int	i;

	i = 0;
	while (i < data->pipe_num + 2)
	{
		if (i == 0 && process_num(*data, i) == 1)
			contral_first_process(data);
		else if (i == 1 && process_num(*data, i) == 1)
			contral_first_cmd_process(data, env);
		else if (i == data->pipe_num + 1 && process_num(*data, i) == 1)
			contral_last_process(data, env);
		else if (process_num(*data, i) == 1)
			contral_mid_process(data, i - 1, env);
		i++;
	}
}
