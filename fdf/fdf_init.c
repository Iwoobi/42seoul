/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:10:46 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:11:10 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_fdf_init(t_list *data)
{
	t_center_list	data_c;

	data_c.mid_x = 0;
	data_c.mid_y = 0;
	data_c.mid_z = 0;
	data_c.theta = 180 * acos(1 / sqrt(3)) / M_PI;
	data_c.alpha = 45;
	data_c.t = 0;
	data->k = sin(ft_radian(data_c.theta)) * sin(ft_radian(data_c.alpha));
	data->data_c = data_c;
	data->len = 500 / sqrt(pow(data->row / 2, 2) + pow(data->col / 2, 2)
			+ pow((data->max_val - data->min_val) / 2, 2));
	data->mul = 1;
}