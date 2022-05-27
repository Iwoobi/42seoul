/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:57:32 by youhan            #+#    #+#             */
/*   Updated: 2022/05/27 19:07:09 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	row_count(int fd, t_list *data)
{
	char *tmp;
	int	i;

	i = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	data->row = i;
}

int	open_file(char *file_name, t_list *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	row_count(fd, data);
	data->arr_size = (int *)malloc(sizeof(int) * data->row);
	data->arr = (double ***)malloc(sizeof(double **) * data->row);
	data->input_data = (char **)malloc(sizeof(char *) * data->row);
	if (!(data->arr_size) || !(data->arr) || !(data->input_data))
		exit(1);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (i < data->row)
	{
		(data->input_data)[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}
