/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:30:46 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:32:54 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	point_rotate(t_list *data, double theta, double alpha)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	z;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			x = (data->arr)[i][j][0];
			y = (data->arr)[i][j][1];
			z = (data->arr)[i][j][2];
			(data->arr)[i][j][0] = cos(theta) * cos(alpha) * x
				+ cos(theta) * sin(alpha) * y - sin(theta) * z;
			(data->arr)[i][j][1] = -sin(alpha) * x + cos(alpha) * y;
			(data->arr)[i][j][2] = sin(theta) * cos(alpha) * x
				+ sin(theta) * sin(alpha) * y + cos(theta) * z;
			j++;
		}
		i++;
	}
}

void	find_point(t_list *data, t_center_list *data_c)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	z;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			x = (data->arr)[i][j][0];
			y = (data->arr)[i][j][1];
			z = (data->arr)[i][j][2];
			(data->arr)[i][j][0] = data_c->n[0] * (data->arr)[i][j][3] + x;
			(data->arr)[i][j][1] = data_c->n[1] * (data->arr)[i][j][3] + y;
			(data->arr)[i][j][2] = data_c->n[2] * (data->arr)[i][j][3] + z;
			j++;
		}
		i++;
	}
}

void	ft_fdf_n_vector_t(t_list *data, t_center_list *data_c)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			(data->arr)[i][j][3] = -1 * ((data->arr)[i][j][0]
					* data_c->n[0] + (data->arr)[i][j][1]
					* data_c->n[1] + (data->arr)[i][j][2]
					* data_c->n[2]);
			j++;
		}
		i++;
	}
}

void	ft_fdf_n_vector(t_list *data, t_center_list *data_c)
{
	data_c->n[0] = sin(ft_radian(data_c->theta))
		* cos(ft_radian(data_c->alpha));
	data_c->n[1] = sin(ft_radian(data_c->theta))
		* sin(ft_radian(data_c->alpha));
	data_c->n[2] = cos(ft_radian(data_c->theta));
	translation_x_y_z(data, -(data->col) / 2, -(data->row) / 2,
		-(data->max_val + data->min_val) / 2);
}

void	ft_fdf(t_list *data)
{
	ft_fdf_n_vector(data, &(data->data_c));
	ft_fdf_n_vector_t(data, &(data->data_c));
	find_point(data, &(data->data_c));
	point_rotate(data, ft_radian((data->data_c).theta),
		ft_radian((data->data_c).alpha));
}
