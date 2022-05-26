/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:45:22 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:47:00 by youhan           ###   ########.fr       */
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
			my_mlx->img.data[i * 1000 + j] = 0x000000;
			j++;
		}
		i++;
	}
}

int	deal_key_var3(int key_code, t_mlx *my_mlx)
{
	if (key_code == 14)
	{
		my_mlx->data->data_c.mid_y -= 0.3 * my_mlx->data->len;
		ft_mlx_img_clear(my_mlx);
	}
	else if (key_code == 15)
	{
		my_mlx->data->data_c.mid_y += 0.3 * my_mlx->data->len;
		ft_mlx_img_clear(my_mlx);
	}
	else if (key_code == 16)
	{
		my_mlx->data->mul += 0.1;
		ft_mlx_img_clear(my_mlx);
	}
	else if (key_code == 17)
	{
		my_mlx->data->mul -= 0.1;
		ft_mlx_img_clear(my_mlx);
	}
	return (0);
}

int	deal_key_var2(int key_code, t_mlx *my_mlx)
{
	if (key_code == 126)
	{
		my_mlx->data->data_c.alpha += 3;
		ft_mlx_img_clear(my_mlx);
	}
	else if (key_code == 12)
	{
		ft_mlx_img_clear(my_mlx);
		my_mlx->data->data_c.mid_x += 0.3 * my_mlx->data->len;
	}
	else if (key_code == 13)
	{
		ft_mlx_img_clear(my_mlx);
		my_mlx->data->data_c.mid_x -= 0.3 * my_mlx->data->len;
	}
	return (0);
}

int	deal_key(int key_code, t_mlx *my_mlx)
{
	if (key_code == 53)
		exit(0);
	else if (key_code == 123)
	{
		ft_mlx_img_clear(my_mlx);
		my_mlx->data->data_c.theta += 1;
	}
	else if (key_code == 124)
	{
		ft_mlx_img_clear(my_mlx);
		my_mlx->data->data_c.theta -= 1;
	}
	else if (key_code == 125)
	{
		my_mlx->data->data_c.alpha -= 3;
		ft_mlx_img_clear(my_mlx);
	}
	else
		deal_key_var2(key_code, my_mlx);
	return (0);
}
