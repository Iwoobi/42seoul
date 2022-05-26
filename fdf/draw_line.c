/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:36:31 by youhan            #+#    #+#             */
/*   Updated: 2022/05/26 23:37:53 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	draw_line_more_h(t_mlx *my_mlx,
	t_line *line, double *start, double *fin)
{
	line->d = (2 * line->w) - line->h;
	while (line->y != (int)fin[1])
	{
		if (line->d < 0)
			line->d += 2 * line->w;
		else
		{
			line->x++;
			if (start[0] - fin[0] > 0)
				line->x -= 2;
			line->d += (2 * line->w - 2 * line->h);
		}
		if (line->x < 1000 && line->y < 1000 && line->x >= 0 && line->y >= 0)
			my_mlx->img.data[line->y * 1000 + line->x] = 0xFFFFFF;
		line->y++;
		if (start[1] - fin[1] > 0)
			line->y -= 2;
	}
}

void	draw_line_more_w(t_mlx *my_mlx,
	t_line *line, double *start, double *fin)
{
	line->d = (2 * line->h) - line->w;
	while (line->x != (int)(fin[0]))
	{
		if (line->d < 0)
			line->d += 2 * line->h;
		else
		{
			line->y++;
			if (start[1] - fin[1] > 0)
				line->y -= 2;
			line->d += (2 * line->h - 2 * line->w);
		}
		if (line->x < 1000 && line->y < 1000 && line->x >= 0 && line->y >= 0)
			my_mlx->img.data[line->y * 1000 + line->x] = 0xFFFFFF;
		line->x++;
		if (start[0] - fin[0] > 0)
			line->x -= 2;
	}	
}

void	draw_line(double *start, double *fin, t_mlx *my_mlx)
{
	t_line	line;

	line.x = (int)(start[0]);
	line.y = (int)(start[1]);
	line.w = fabs(start[0] - fin[0]);
	line.h = fabs(start[1] - fin[1]);
	if (line.w > line.h)
		draw_line_more_w(my_mlx, &line, start, fin);
	else
		draw_line_more_h(my_mlx, &line, start, fin);
}

void	draw_lines(t_list *data, t_mlx *my_mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (j != data->col - 1)
				draw_line((data->arr)[i][j], (data->arr)[i][j + 1], my_mlx);
			if (i != data->row - 1)
				draw_line((data->arr)[i][j], (data->arr)[i + 1][j], my_mlx);
			j++;
		}
		i++;
	}
}

