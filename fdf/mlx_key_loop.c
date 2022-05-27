/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:45:22 by youhan            #+#    #+#             */
/*   Updated: 2022/05/27 18:56:08 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_mlx_img_clear(t_mlx *my_mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			my_mlx->img.data[i * 1000 + j] = 0;
			j++;
		}
		i++;
	}
}

int	deal_key_var4(int key_code, t_mlx *my_mlx)
{
	if (key_code == KEY_DOWN)
	{
		if (my_mlx->data->data_c.alpha < -360)
			my_mlx->data->data_c.alpha += 360;
		my_mlx->data->data_c.alpha -= 3;
	}
	else if (key_code == KEY_UP)
	{
		my_mlx->data->data_c.alpha += 3;
		if (my_mlx->data->data_c.alpha > 360)
			my_mlx->data->data_c.alpha -= 360;
	}
	else if (key_code == KEY_A)
	{
		my_mlx->data->rot_a += 1;
		if (my_mlx->data->rot_a > 360)
			my_mlx->data->rot_a -= 360;
	}
	else if (key_code == KEY_S)
	{
		my_mlx->data->rot_a -= 1;
		if (my_mlx->data->rot_a < -360)
			my_mlx->data->rot_a += 360;
	}	
	return (0);
}

int	deal_key_var3(int key_code, t_mlx *my_mlx)
{
	if (key_code == KEY_D)
	{
		if (my_mlx->data->mul < 20)
			my_mlx->data->mul += 0.1;
	}
	else if (key_code == KEY_F)
	{
		if (my_mlx->data->mul > 0.1)
			my_mlx->data->mul -= 0.1;
	}
	else if (key_code == KEY_SPA)
		ft_fdf_init(my_mlx->data);
	else
		deal_key_var4(key_code, my_mlx);
	return (0);
}

int	deal_key_var2(int key_code, t_mlx *my_mlx)
{
	ft_mlx_img_clear(my_mlx);
	if (key_code == KEY_Q)
	{
		if (my_mlx->data->data_c.mid_x < 1500)
			my_mlx->data->data_c.mid_x += 5 * my_mlx->data->mul;
	}
	else if (key_code == KEY_W)
	{
		if (my_mlx->data->data_c.mid_x > -1500)
			my_mlx->data->data_c.mid_x -= 5 * my_mlx->data->mul;
	}
	else if (key_code == KEY_E)
	{
		if (my_mlx->data->data_c.mid_y > -1500)
			my_mlx->data->data_c.mid_y -= 5 * my_mlx->data->mul;
	}
	else if (key_code == KEY_R)
	{
		if (my_mlx->data->data_c.mid_y < 1500)
			my_mlx->data->data_c.mid_y += 5 * my_mlx->data->mul;
	}
	else
		deal_key_var3(key_code, my_mlx);
	return (0);
}

int	deal_key(int key_code, t_mlx *my_mlx)
{
	if (key_code == 53)
		exit(0);
	else if (key_code == KEY_LEFT)
	{
		ft_mlx_img_clear(my_mlx);
		if (my_mlx->data->data_c.theta > 360)
			my_mlx->data->data_c.theta -= 360;
		my_mlx->data->data_c.theta += 1;
	}
	else if (key_code == KEY_RIGHT)
	{
		ft_mlx_img_clear(my_mlx);
		if (my_mlx->data->data_c.theta < -360)
			my_mlx->data->data_c.theta += 360;
		my_mlx->data->data_c.theta -= 1;
	}
	else
		deal_key_var2(key_code, my_mlx);
	return (0);
}
