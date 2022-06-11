/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contral_pipe_pid_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:36:07 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 03:30:06 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	contral_first_cmd_process_bonus(t_list *data, char **env)
{
	char	*dir_cmd;

	dup2(data->in_file_fd[0], 0);
	dup2(data->p_fd[0][1], 1);
	all_close_write_pipe_fd(data);
	all_close_read_pipe_fd(data);
	exist_cmd(data, 0, &dir_cmd);
	if (execve(dir_cmd, data->cmd[0], env) == -1)
		error_cmd(data, data->cmd[0][0]);
	free(dir_cmd);
}

void	contral_mul_pipe_pid(t_list *data, char **env)
{
	int	i;

	i = 0;
	while (i < data->pipe_num + 2)
	{
		if (i == 0 && process_num(*data, i) == 1)
			contral_first_process(data);
		else if (i == 1 && process_num(*data, i) == 1)
			contral_first_cmd_process_bonus(data, env);
		else if (i == data->pipe_num + 1 && process_num(*data, i) == 1)
			contral_last_process(data, env);
		else if (process_num(*data, i) == 1)
			contral_mid_process(data, i - 1, env);
		i++;
	}
}

void	contral_here_doc_process(t_list *data, char **env)
{
	char	*dir_cmd;

	dup2(data->in_file_fd[0], 0);
	dup2(data->fd.w_fd, 1);
	all_close_write_pipe_fd(data);
	all_close_read_pipe_fd(data);
	exist_cmd(data, 0, &dir_cmd);
	if (execve(dir_cmd, data->cmd[0], env) == -1)
		error_cmd(data, data->cmd[0][0]);
	free(dir_cmd);
}

void	contral_pipe_pid_bonus(t_list *data, char **env)
{
	int	i;

	i = 0;
	if (data->pipe_num == 0)
	{
		while (i < 2)
		{
			if (i == 0 && process_num(*data, i) == 1)
				contral_first_process(data);
			if (i == 1 && process_num(*data, i) == 1)
				contral_here_doc_process(data, env);
			i++;
		}
	}
	else
		contral_mul_pipe_pid(data, env);
}
