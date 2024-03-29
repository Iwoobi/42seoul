/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:11:54 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:12:02 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_mlx_init(t_mlx *my_mlx, int size)
{
	my_mlx->mlx = mlx_init();
	if (my_mlx->mlx == NULL)
		exit(1);
	my_mlx->win = mlx_new_window(my_mlx->mlx, size, size, "FDF");
	if (my_mlx->win == NULL)
		exit(1);
	my_mlx->img.img = mlx_new_image(my_mlx->mlx, size, size);
	if (my_mlx->img.img == NULL)
		exit(1);
	my_mlx->img.data = (int *)mlx_get_data_addr(my_mlx->img.img,
			&my_mlx->img.bpp, &my_mlx->img.size_l, &my_mlx->img.endian);
	if (my_mlx->img.data == NULL)
		exit(1);
}
