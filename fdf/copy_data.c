/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:06:47 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:07:11 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	input_data_copy(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	data->arr_copy = (double ***)malloc(sizeof(double **) * data->row);
	if (data->arr_copy == NULL)
		exit(1);
	while (i < data->row)
	{
		j = 0;
		(data->arr_copy)[i] = (double **)malloc(sizeof(double *) * data->col);
		if (data->arr_copy[i] == NULL)
			exit(1);
		while (j < data->col)
		{
			(data->arr_copy)[i][j] = (double *)malloc(sizeof(double) * 3);
			if ((data->arr_copy)[i][j] == NULL)
				exit(1);
			data->arr_copy[i][j][0] = data->arr[i][j][0];
			data->arr_copy[i][j][1] = data->arr[i][j][1];
			data->arr_copy[i][j][2] = data->arr[i][j][2];
			j++;
		}
		i++;
	}
}