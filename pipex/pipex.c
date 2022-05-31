/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:55:13 by youhan            #+#    #+#             */
/*   Updated: 2022/05/31 22:39:27 by youhan           ###   ########.fr       */
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

void	inputdata_check(int argc, char **argv, t_list *data)
{
	if (argc < 5)
		error_code(1);
	data->bonus_mod = -1;
	if (diff_str(argv[1], "here_doc"))
		data->bonus_mod = 1;
	data->pipe_num = argc - 4;
	open_file(argv[1], argv[argc - 1], data);
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
	if (data->p_fd == NULL && data->pid == NULL)
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
			if (data->p_fd[j] == 0)
				child = 1;
			j++;			
		}
		if (child != 1)
		{
			data->pid[i] = fork();
			if (data->pid[i] == -1)
				error_code(2);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list	data;
	int	j;
	int	child = 0;
	inputdata_check(argc, argv, &data);
	find_cmd_local(env, &data);
	malloc_pfd_pid(&data);
	make_process(&data);

	j = 0;
	while (j < data.pipe_num)
	{
		printf("%d ",data.pid[j]);
		j++;
	}
	printf("\n");
	
}
