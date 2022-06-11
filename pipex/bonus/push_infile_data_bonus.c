/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_infile_data_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:18:17 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 02:23:40 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	read_infile_data(t_list *data)
{
	char	*tmp;
	char	*in_file_data;

	in_file_data = NULL;
	tmp = get_next_line(0);
	while (tmp != NULL)
	{
		if (diff_str(tmp, data->limmit, 1) == 1)
		{
			free(tmp);
			return ;
		}
		write(data->in_file_fd[1], tmp, ft_strlen(tmp));
		free(tmp);
		tmp = get_next_line(0);
	}
}

void	push_infile_data(t_list *data)
{
	read_infile_data(data);
	close_fd(data);
}
