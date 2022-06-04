/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:55:13 by youhan            #+#    #+#             */
/*   Updated: 2022/06/04 22:31:06 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

void	error_code(int mod)
{
	if (mod == 1)
	{
		write(2, "data_error", 11);
		exit(1);
	}
	if (mod == 2)
	{
		write(2, "system_error", 13);
		exit(1);
	}
}

void	error_file(t_list *data)
{
	data->status = 1;
	write(2, data->shell, ft_strlen(data->shell));
	write(2, ": no such file or directory: ", 29);
	write(2, data->in_file, ft_strlen(data->in_file));
	write(2, "\n", 1);
	exit(1);
}

void	error_cmd(t_list *data, char *cmd)
{
	data->status = 127;
	write(2, data->shell, ft_strlen(data->shell));
	write(2, ": command not found: ", 21);
	write(2, cmd, ft_strlen(cmd));	
	write(2, "\n", 1);
}

void	open_file(char *file_1, char *file_2, t_list *data)
{
	if (data->bonus_mod == -1)
	{
		data->fd.r_fd = open(file_1, O_RDONLY);
		data->fd.w_fd = open(file_2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->fd.w_fd == -1)
			error_code(2);
	}
	else
	{
		data->fd.w_fd = open(file_2, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (data->fd.w_fd == -1)
			error_code(2);
	}
}

int	diff_str(char *s1, char *s2, int mod)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (-1);
	if (ft_strlen(s1) != ft_strlen(s2) + mod)
		return (-1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	if (mod == 1)
	{
		if (s1[i] != '\n')
			return (-1);
	}
	return (1);
}

void	push_inputdata(char **argv, t_list *data, int i)
{
	data->cmd = (char ***)malloc(sizeof(char **) * (data->pipe_num + 2));
	if (data->cmd == NULL)
		error_code(2);
	data->cmd[data->pipe_num + 1] = NULL;
	while (i < data->pipe_num + 1)
	{
		data->cmd[i] = ft_split(argv[i + 2], ' ');
		if (data->cmd[i][0] == NULL)
			error_code(2);
		i++;
	}
}
void	inputdata_check(int argc, char **argv, t_list *data)
{
	if (argc < 5)
		error_code(1);
	data->bonus_mod = -1;
	if (diff_str(argv[1], "here_doc", 0) == 1)
		data->bonus_mod = 1;
	data->pipe_num = argc - 4;
	if (data->bonus_mod == 1)
	{
		data->pipe_num -= 1;
		push_inputdata(argv, data, 1);
		data->limmit = argv[2];
		printf("\n%s\n", data->cmd[0][0]);
	}
	else
	{
		data->in_file = argv[1];
		open_file(argv[1], argv[argc - 1], data);
		push_inputdata(argv, data, 0);
	}
}

void	input_shell(char ***tmp, t_list *data)
{
	int	i;

	i = 0;
	while ((*tmp)[i])
		i++;
	i -= 1;
	data->shell = (*tmp)[i];
	if (i > 0)
		i -= 1;
	while (i >= 0)
	{
		free((*tmp)[i]);
		i--;
	}
	free(*tmp);
}

void	find_shell(char **env, t_list *data)
{
	int		i;
	int		local;
	char	**tmp;

	i = 0;
	local = -1;
	while (env[i] != NULL)
	{
		if (env[i][5] != '\0')
		{
			if (env[i][0] == 'S' && env[i][1] == 'H' && env[i][2] == 'E'
				&& env[i][3] == 'L' && env[i][4] == 'L' && env[i][5])
				local = i;
		}
		i++;
	}
	if (local == -1)
		error_code(1);
	tmp = ft_split(env[local], '/');
	if (tmp == NULL)
		error_code(2);
	input_shell(&tmp, data);
}

void	find_cmd_local(char **env, t_list *data)
{
	int	i;
	int	local;

	i = 0;
	local = -1;
	while (env[i] != NULL)
	{
		if (env[i][4] != '\0')
		{
			if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
				&& env[i][3] == 'H' && env[i][4] == '=')
				local = i;
		}
		i++;
	}
	if (local == -1)
		error_code(1);
	data->path = ft_split(&(env[local][5]), ':');
	if (data->path == NULL)
		error_code(2);
}

void	malloc_pfd_pid(t_list *data)
{
	int	i;

	i = 0;
	data->p_fd = (int **)malloc(sizeof(int *) * data->pipe_num);
	data->pid = (pid_t *)malloc(sizeof(pid_t *) * (data->pipe_num + 1));
	if (data->p_fd == NULL || data->pid == NULL)
		error_code(2);
	while (i < data->pipe_num)
	{
		data->pid[i] = i + 1;
		data->p_fd[i] = (int *)malloc(sizeof(int) * 2);
		if (data->p_fd[i] == NULL)
			error_code(2);
		if (pipe(data->p_fd[i]) == -1)
			error_code(2);
		i++;
	}
	data->pid[i] = i + 1;
}

void	make_process(t_list *data)
{
	int	i;
	int	j;
	int	child;

	i = 0;
	while(i < data->pipe_num + 1)
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
		if(data.pid[pid - 1] == 0)
			return (1);
	}
	return (-1);
}

void	close_read_pipe_fd(t_list *data, int process)
{
	int	i;

	i = 0;
	while (i < data->pipe_num)
	{
		if (i != process)
			close(data->p_fd[i][0]);
		i++;
	}
}

void	close_write_pipe_fd(t_list *data, int process)
{
	int	i;

	i = 0;
	while (i < data->pipe_num)
	{
		if (i != process)
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

void	join_dir_cmd(char **dir_cmd, char *dir, char *cmd)
{
	int	dif_num;
	int	cmd_num;
	int	i;

	i = 0;
	dif_num = ft_strlen(dir);
	cmd_num = ft_strlen(cmd);
	*dir_cmd = (char *)malloc(sizeof(char) * (dif_num + cmd_num + 2));
	if (*dir_cmd == NULL)
		error_code(2);
	while (i < dif_num)
	{
		(*dir_cmd)[i] = dir[i];
		i++;
	}
	(*dir_cmd)[i] = '/';
	i++;
	while (i < dif_num + cmd_num + 2)
	{
		(*dir_cmd)[i] = cmd[i - dif_num - 1];
		i++;
	}
	(*dir_cmd)[i] = '\0';	
}

void	exist_cat(t_list *data,char **dir_cmd)
{
	int	i;

	i = 0;
	join_dir_cmd(dir_cmd, NULL, "cat");
	if (access(*dir_cmd, F_OK) == 0)
		return ;
	while (data->path[i])
	{
		join_dir_cmd(dir_cmd, data->path[i], "cat");
		if (access(*dir_cmd, F_OK) == -1)
			free(*dir_cmd);
		else
			return ;
		i++;
	}
	*dir_cmd = NULL;
}

void	exist_cmd(t_list *data, int process, char **dir_cmd)
{
	int	i;

	i = 0;
	join_dir_cmd(dir_cmd, NULL, data->cmd[process][0]);
	if (access(*dir_cmd, F_OK) == 0)
		return ;
	while (data->path[i])
	{
		join_dir_cmd(dir_cmd, data->path[i], data->cmd[process][0]);
		if (access(*dir_cmd, F_OK) == -1)
			free(*dir_cmd);
		else
			return ;
		i++;
	}
	*dir_cmd = NULL;
}

void	join_infile_data(char **data, char **back_data)
{
	int		data_size;
	int		back_size;
	char	*tmp;
	int		i;

	i = 0;
	data_size = ft_strlen(*data);
	back_size = ft_strlen(*back_data);
	tmp = (char *)malloc(sizeof(char) * (data_size + back_size + 1));
	if (tmp == NULL)
		exit(1);
	tmp[data_size + back_size] = '\0';
	while (i < data_size)
	{
		tmp[i] = (*data)[i];
		i++;
	}
	while (i < data_size + back_size)
	{
		tmp[i] = (*back_data)[i - data_size];
		i++;
	}
	free(*data);
	*data = tmp;
}

void	close_fd(t_list *data)
{
	if (data->bonus_mod != 1)
		close(data->fd.r_fd);
	close(data->fd.w_fd);
	all_close_read_pipe_fd(data);
	all_close_write_pipe_fd(data);
}


void	read_infile_data(t_list *data)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp != NULL)
	{
		if (diff_str(tmp, data->limmit, 1) == 1)
			return ;
		free(tmp);
		tmp = get_next_line(0);
	}
}

void	push_infile_data(t_list *data)
{
	close_fd(data);
	dup2(data->in_file_fd[1], 1);
	read_infile_data(data);
	close(data->in_file_fd[0]);
	close(data->in_file_fd[1]);
}

void	contral_first_process(t_list *data)
{
	int	i;
	int	status;
	pid_t	j;

	close_fd(data);
	if (data->bonus_mod == 1)
		push_infile_data(data);
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

void	contral_first_cmd_process_bonus(t_list *data, char **env)
{
	char	*dir_cmd;

	dup2(data->in_file_fd[0], 0);
	dup2(data->p_fd[0][1], 1);
	close(data->in_file_fd[0]);
	close(data->in_file_fd[1]);
	close(data->fd.r_fd);
	all_close_write_pipe_fd(data);
	all_close_read_pipe_fd(data);
	exist_cmd(data, 0, &dir_cmd);
	if (execve(dir_cmd, data->cmd[0], env) == -1)
		error_cmd(data ,data->cmd[0][0]);
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
	close(data->in_file_fd[0]);
	close(data->in_file_fd[1]);
	all_close_write_pipe_fd(data);
	all_close_read_pipe_fd(data);
	exist_cmd(data, 0, &dir_cmd);
	if (execve(dir_cmd, data->cmd[0], env) == -1)
		error_cmd(data ,data->cmd[0][0]);
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
		error_cmd(data ,data->cmd[data->pipe_num][0]);
	free(dir_cmd);
}

void	contral_mid_process(t_list *data,int process, char **env)
{
	char	*dir_cmd;

	dup2(data->p_fd[process - 1][0], 0);
	dup2(data->p_fd[process][1], 1);
	all_close_write_pipe_fd(data);
	all_close_read_pipe_fd(data);
	exist_cmd(data, process, &dir_cmd);
	if (execve(dir_cmd, data->cmd[process], env) == -1)
		error_cmd(data ,data->cmd[process][0]);
	free(dir_cmd);
}

void	contral_pipe_pid(t_list *data, char **env)
{
	int i;

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

void	contral_pipe_pid_bonus(t_list *data, char **env)
{
	int i;

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

int	main(int argc, char **argv, char **env)
{
	t_list	data;

	data.status = 0;
	inputdata_check(argc, argv, &data);
	find_cmd_local(env, &data);
	find_shell(env, &data);
	malloc_pfd_pid(&data);
	make_process(&data);
	if (data.bonus_mod == 1)
		contral_pipe_pid_bonus(&data, env);
	else
		contral_pipe_pid(&data, env);
	exit(data.status);
}
