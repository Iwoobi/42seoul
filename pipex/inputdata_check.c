/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputdata_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:09:59 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 03:34:49 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(char *file_1, char *file_2, t_list *data)
{
	data->fd.r_fd = open(file_1, O_RDONLY);
	data->fd.w_fd = open(file_2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd.w_fd == -1)
		error_code(2);
}

void	push_inputdata(char **argv, t_list *data, int mod)
{
	int	i;

	i = 0;
	data->cmd = (char ***)malloc(sizeof(char **) * (data->pipe_num + 2));
	if (data->cmd == NULL)
		error_code(2);
	data->cmd[data->pipe_num + 1] = NULL;
	while (i < data->pipe_num + 1)
	{
		data->cmd[i] = ft_split(argv[i + mod + 2], ' ');
		if (data->cmd[i][0] == NULL)
			error_code(2);
		i++;
	}
}

void	inputdata_check(int argc, char **argv, t_list *data)
{
	if (argc != 5)
		error_code(1);
	data->pipe_num = 1;
	data->in_file = argv[1];
	open_file(argv[1], argv[argc - 1], data);
	push_inputdata(argv, data, 0);
}
