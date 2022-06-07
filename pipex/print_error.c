/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:40:47 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:09:14 by youhan           ###   ########.fr       */
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
