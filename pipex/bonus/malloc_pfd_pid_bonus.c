/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_pfd_pid_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:14:12 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 02:34:10 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	if (pipe(data->in_file_fd) == -1)
		error_code(2);
	data->pid[i] = i + 1;
}
