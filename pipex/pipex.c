/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:55:13 by youhan            #+#    #+#             */
/*   Updated: 2022/06/01 22:50:44 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	error_cmd(char *cmd)
{
	write(2, "command not found : ", 21);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

void	open_file(char *file_1, char *file_2, t_list *data)
{
	if (data->bonus_mod == -1)
	{
		data->fd.r_fd = open(file_1, O_RDONLY);
		if (data->fd.r_fd == -1)
			error_code(1);
	}
	data->fd.w_fd = open(file_2, O_WRONLY);
	if (data->fd.w_fd == -1)
		error_code(1);
}

int	diff_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (1);
}
void	push_inputdata(int argc, char **argv, t_list *data)
{
	int	i;

	i = 0;
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
	if (diff_str(argv[1], "here_doc"))
		data->bonus_mod = 1;
	data->pipe_num = argc - 4;
	open_file(argv[1], argv[argc - 1], data);
	push_inputdata(argc, argv, data);
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
		error_code(1);
}

void	malloc_pfd_pid(t_list *data)
{
	int	i;

	i = 0;
	data->p_fd = (int **)malloc(sizeof(int *) * data->pipe_num);
	data->pid = (pid_t *)malloc(sizeof(pid_t *) * data->pipe_num);
	if (data->p_fd == NULL || data->pid == NULL)
		error_code(2);
	while (i < data->pipe_num)
	{
		data->pid[i] = i + 1;
		data->p_fd[i] = (int *)malloc(sizeof(int) * 2);
		if (data->p_fd == NULL)
			error_code(2);
		if (pipe(data->p_fd[i]) == -1)
			error_code(2);
		i++;
	}
}

void	make_process(t_list *data)
{
	int	i;
	int	j;
	int	child;

	i = 0;
	while(i < data->pipe_num)
	{
		j = 0;
		child = 0;
		while (j < data->pipe_num)
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

	i = 0;
	if (pid == 0)
	{
		while (i < data.pipe_num)
		{
			if (data.pid[i] == 0)
				return (-1);
			i++;
		}
		return (1);
	}
	else
	{
		while (i < data.pipe_num)
		{
			if(data.pid[pid - 1] == 0)
				return (1);
			i++;
		}
	}
	return (-1);
}

void	print_pid(t_list data)
{
	int i;

	i = 0;
	while (i < data.pipe_num)
	{
		printf("%d ",data.pid[i]);
		i++;
	}
	printf("\n");
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

void	exist_cmd(t_list *data, int process, char **dir_cmd)
{
	int	i;

	i = 0;
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

void	contral_first_process(t_list *data, int process, char **env)
{
	char	*dir_cmd;

	dup2(data->p_fd[0][1], 1);
	close_read_pipe_fd(data, -1);
	exist_cmd(data, process, &dir_cmd);
	char **a = (char **)malloc(sizeof(char *)*3);
	a[0] = "cat";
	a[1] = "file1";
	a[2] = NULL;
	if (execve(dir_cmd, a, env) == -1)
		error_cmd(data->cmd[0][0]);
	free(dir_cmd);
}

void	contral_last_process(t_list *data, int process, char **env)
{
	char	*dir_cmd;

	dup2(data->p_fd[process - 1][0], 0);
	close_write_pipe_fd(data, process);
	exist_cmd(data, process, &dir_cmd);
	char **a = (char **)malloc(sizeof(char *)*3);
	a[0] = "wc";
	a[1] = NULL;
	if (execve(dir_cmd, a, env) == -1)
		error_cmd(data->cmd[process][0]);
	free(dir_cmd);
}

void	contral_mid_process(t_list *data, int process, char **env)
{
	char	*dir_cmd;

	dup2(data->p_fd[process - 1][0], 0);
	close_write_pipe_fd(data, process);
	dup2(data->p_fd[process][1], 1);
	close_read_pipe_fd(data, process - 1);
	exist_cmd(data, process, &dir_cmd);
	if (execve(dir_cmd, data->cmd[process], env) == -1)
		error_cmd(data->cmd[process][0]);
	free(dir_cmd);
}
void	contral_pipe_pid(t_list *data, char **env)
{
	int i;
	
	i = 0;
	while (i < data->pipe_num + 1)
	{
		if (i == 0 && process_num(*data, i) == 1)
		{
			contral_first_process(data, i, env);
			return ;
		}
		else if (i == data->pipe_num && process_num(*data, i) == 1)
		{
			contral_last_process(data, i, env);
			return ;
		}
		else if (process_num(*data, i) == 1)
		{
			contral_mid_process(data, i, env);
			return ;
		}
		i++;
	}
}
void	print_cmd(t_list data)
{
	int i = 0;
	int j = 0;

	i = 0;
	while (data.cmd[i])
	{
		j = 0;
		while (data.cmd[i][j])
		{
			printf("%s\n", data.cmd[i][j]);
			j++;
		}
		i++;
	}
	printf("asd");
}
int	main(int argc, char **argv, char **env)
{
	t_list	data;

	inputdata_check(argc, argv, &data);
	find_cmd_local(env, &data);
	malloc_pfd_pid(&data);
	make_process(&data);
	contral_pipe_pid(&data, env);
}