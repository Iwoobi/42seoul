/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:24:24 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:46:27 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	rotate_point(t_list *data, double theta)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			x = (data->arr)[i][j][0];
			y = (data->arr)[i][j][1];
			(data->arr)[i][j][0] = cos(theta) * x - sin(theta) * y;
			(data->arr)[i][j][1] = sin(theta) * x + cos(theta) * y;
			j++;
		}
		i++;
	}
}

void	input_data_init(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			data->arr[i][j][0] = data->arr_copy[i][j][0];
			data->arr[i][j][1] = data->arr_copy[i][j][1];
			data->arr[i][j][2] = data->arr_copy[i][j][2];
			j++;
		}
		i++;
	}
}

int	ft_close(void)
{
	exit(0);
}

int	main_loop(t_mlx *my_mlx)
{
	input_data_init(my_mlx->data);
	ft_fdf(my_mlx->data);
	rotate_point(my_mlx->data, ft_radian(90));
	arr_multiplication(my_mlx->data, my_mlx->data->mul * my_mlx->data->len,
		my_mlx->data->mul * my_mlx->data->len, my_mlx->data->mul
		* my_mlx->data->len);
	translation_x_y_z(my_mlx->data, 500 + my_mlx->data->data_c.mid_x,
		500 + my_mlx->data->data_c.mid_y, 0);
	draw_lines(my_mlx->data, my_mlx);
	mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, my_mlx->img.img, 0, 0);
	return (0);
}