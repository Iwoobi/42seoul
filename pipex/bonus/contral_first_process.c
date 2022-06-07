/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contral_first_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:18:34 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:09:44 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
	if (data_size != 0)
		free(*data);
	*data = tmp;
}

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
			write(1, in_file_data, ft_strlen(in_file_data));
			return ;
		}
		join_infile_data(&in_file_data, &tmp);
		free(tmp);
		tmp = get_next_line(0);
	}
}

void	push_infile_data(t_list *data)
{
	dup2(data->in_file_fd[1], 1);
	close_fd(data);
	read_infile_data(data);
	close(1);
}
