/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:08:31 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:08:48 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	find_max_z(t_list *data)
{
	int		i;
	int		j;
	double	max_val;
	double	min_val;

	i = 0;
	max_val = (data->arr)[0][0][2];
	min_val = (data->arr)[0][0][2];
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (max_val < (data->arr)[i][j][2])
				max_val = (data->arr)[i][j][2];
			if (min_val > (data->arr)[i][j][2])
				min_val = (data->arr)[i][j][2];
			j++;
		}
		i++;
	}
	data->max_val = max_val;
	data->min_val = min_val;
}