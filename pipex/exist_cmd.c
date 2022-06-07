/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:32:50 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:06:42 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
