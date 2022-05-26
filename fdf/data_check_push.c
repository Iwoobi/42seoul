/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:02:57 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:06:08 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	str_data_num_check(char *data)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (data[0] == '+' || data[0] == '-')
		i++;
	while (data[i])
	{
		if (!((data[i] >= '0' && data[i] <= '9') || data[i] == '\n'\
			|| data[i] == ' '))
			exit(1);
		else
			check = 1;
		i++;
	}
	if (check == 0)
		exit(1);
}

void	split_data_check(char **data)
{
	int	i;

	i = 0;
	if (data == NULL)
		exit(1);
	while (data[i])
	{
		str_data_num_check(data[i]);
		i++;
	}
}

void	row_col_count_check(t_list *data)
{
	int	i;
	int	val;

	i = 0;
	val = (data->arr_size)[0];
	while (i < data->row)
	{
		if (val != (data->arr_size)[i])
			error_data_wrong();
		i++;
	}
	data->col = val;
}

void	split_data_push(t_list *data, char **split_data, int row)
{
	int	col;

	col = 0;
	while (split_data[col])
		col++;
	(data->arr_size)[row] = col;
	(data->arr)[row] = (double **)malloc(sizeof(double *) * col);
	if ((data->arr)[row] == NULL)
		exit(1);
	col = 0;
	while (split_data[col])
	{
		(data->arr)[row][col] = (double *)malloc(sizeof(double) * 4);
		if ((data->arr)[row][col] == NULL)
			exit(1);
		(data->arr)[row][col][0] = (double)col;
		(data->arr)[row][col][1] = (double)row;
		(data->arr)[row][col][2] = (double)ft_atoi(split_data[col]);
		col++;
	}
}

void	inputdata_push(t_list *data)
{
	char	**split_data;
	int		i;

	i = 0;
	while (i < data->row)
	{
		split_data = ft_split((data->input_data)[i], ' ');
		if (!split_data)
			error_data_wrong();
		split_data_check(split_data);
		split_data_push(data, split_data, i);
		i++;
	}
	row_col_count_check(data);
	find_max_z(data);
	input_data_copy(data);
}
