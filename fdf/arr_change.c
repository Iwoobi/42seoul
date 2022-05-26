/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:35:27 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:36:08 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	arr_multiplication(t_list *data, double x_val,
	double y_val, double z_val)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			(data->arr)[i][j][0] *= x_val;
			(data->arr)[i][j][1] *= y_val;
			(data->arr)[i][j][2] *= z_val;
			j++;
		}
		i++;
	}
}

void	translation_x_y_z(t_list *data, double x_val,
	double y_val, double z_val)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			(data->arr)[i][j][0] += x_val;
			(data->arr)[i][j][1] += y_val;
			(data->arr)[i][j][2] += z_val;
			j++;
		}
		i++;
	}
}