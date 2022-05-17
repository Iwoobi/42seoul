/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:09:53 by youhan            #+#    #+#             */
/*   Updated: 2022/05/18 03:10:09 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include "ft_fdf.h"
#include <math.h>
#include "./mlx/mlx.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

long long	ft_atoi(char *str)
{
	int			sign;
	long long	n;

	sign = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		n = n * 10 + *str++ - '0';
	return (n * sign);
}

void	error_data_wrong(void)
{
	write(2, "worng input data\n", 16);
	exit(1);
}

void	str_data_num_check(char *data)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (data[0] == '+' || data[0] == '-')
		i++;
	while (data[i])
	{
		if (!((data[i] >= '0' && data[i] <= '9') || data[i] == '\n'\
			|| data[i] == ' '))
			exit(1);
		else
			check = 1;
		i++;
	}
	if (check == 0)
		exit(1);
}

void	split_data_check(char **data)
{
	int	i;

	i = 0;
	if (data == NULL)
		exit(1);
	while (data[i])
	{
		str_data_num_check(data[i]);
		i++;
	}
}

void	split_data_push(t_list *data, char **split_data, int row)
{
	int	col;

	col = 0;
	while (split_data[col])
		col++;
	(data->arr_size)[row] = col;
	(data->arr)[row] = (double **)malloc(sizeof(double *) * col);
	if ((data->arr)[row] == NULL)
		exit(1);
	col = 0;
	while (split_data[col])
	{
		(data->arr)[row][col] = (double *)malloc(sizeof(double) * 4);
		if ((data->arr)[row][col] == NULL)
			exit(1);
		(data->arr)[row][col][0] = (double)col;
		(data->arr)[row][col][1] = (double)row;
		(data->arr)[row][col][2] = (double)ft_atoi(split_data[col]);
		col++;
	}
}

void	row_col_count_check(t_list *data)
{
	int	i;
	int	val;

	i = 0;
	val = (data->arr_size)[0];
	while (i < data->row)
	{
		if (val != (data->arr_size)[i])
			error_data_wrong();
		i++;
	}
	data->col = val;
}

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

void	inputdata_push(t_list *data)
{
	char	**split_data;
	int		i;

	i = 0;
	while (i < data->row)
	{
		split_data = ft_split((data->input_data)[i], ' ');
		if (!split_data)
			error_data_wrong();
		split_data_check(split_data);
		split_data_push(data, split_data, i);
		i++;
	}
	row_col_count_check(data);
	find_max_z(data);
	input_data_copy(data);
}

void	row_count(int fd, t_list *data)
{
	int	i;

	i = 0;
	while (get_next_line(fd))
		i++;
	data->row = i;
}

int	open_file(char *file_name, t_list *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	row_count(fd, data);
	data->arr_size = (int *)malloc(sizeof(int) * data->row);
	data->arr = (double ***)malloc(sizeof(double **) * data->row);
	data->input_data = (char **)malloc(sizeof(char *) * data->row);
	if (!(data->arr_size) || !(data->arr) || !(data->input_data))
		exit(1);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (i < data->row)
	{
		(data->input_data)[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

/*void	print_arr(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->arr_size[i])
		{
			printf("(%f, %f, %f)", floor((data->arr)[i][j][0]), floor((data->arr)[i][j][1]), (data->arr)[i][j][2]);
			if (j == data->arr_size[i] - 1)
				printf("\n");
			else
				printf(" ");
			j++;
		}
		i++;
	}
}*/

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

void	printf_t(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->arr_size[i])
		{
			printf("(%f)", (data->arr)[i][j][3]);
			if (j == data->arr_size[i] - 1)
				printf("\n");
			else
				printf(" ");
			j++;
		}
		i++;
	}
}

double	ft_radian(int a)
{
	return ((double)(a * M_PI) / 180);
}

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

void	ft_mlx_init(t_mlx *my_mlx, int size)
{
	my_mlx->mlx = mlx_init();
	my_mlx->win = mlx_new_window(my_mlx->mlx, size, size, "FDF");
	my_mlx->img.img = mlx_new_image(my_mlx->mlx, size, size);
	my_mlx->img.data = (int *)mlx_get_data_addr(my_mlx->img.img,
		&my_mlx->img.bpp, &my_mlx->img.size_l, &my_mlx->img.endian);
}

int	ft_close(void)
{
	exit(0);
}

void	rotate_d_theta(t_mlx *my_mlx)
{
	double	n_1;
	double	sin_a;
	double	cos_a;
	double	cos_t;

	n_1 = my_mlx->data->data_c.n[0];
	sin_a = sin(ft_radian(my_mlx->data->data_c.alpha));
	cos_a = cos(ft_radian(my_mlx->data->data_c.alpha));
	cos_t = cos(ft_radian(my_mlx->data->data_c.theta));
	my_mlx->data->data_c.theta = 180 * acos(
		cos(ft_radian(my_mlx->data->data_c.t)) * cos_t) / M_PI;
	my_mlx->data->data_c.alpha = 180 * acos(
		((cos(ft_radian(my_mlx->data->data_c.t))
		* n_1 + sin_a * sin(ft_radian(my_mlx->data->data_c.t))))
		/ sin(ft_radian(my_mlx->data->data_c.theta))) / M_PI;
	printf("\n%f, %f, %f\n", my_mlx->data->data_c.t,
	my_mlx->data->data_c.theta, my_mlx->data->data_c.alpha);
}

int	deal_key(int key_code, t_mlx *my_mlx)
{
	if (key_code == 53)
		exit(0);
	if (key_code == 123)
	{
		ft_mlx_img_clear(my_mlx);
		my_mlx->data->data_c.theta += 1;
	}
	if (key_code == 124)
	{
		ft_mlx_img_clear(my_mlx);
		my_mlx->data->data_c.theta -= 1;
	}
	if (key_code == 125)
	{
		my_mlx->data->data_c.alpha -= 3;
		ft_mlx_img_clear(my_mlx);
	}
	if (key_code == 126)
	{
		my_mlx->data->data_c.alpha += 3;
		ft_mlx_img_clear(my_mlx);
	}
	if (key_code == 12)
	{
		ft_mlx_img_clear(my_mlx);
		my_mlx->data->data_c.mid_x += 0.3 * my_mlx->data->len;
	}
	if (key_code == 13)
	{
		ft_mlx_img_clear(my_mlx);
		my_mlx->data->data_c.mid_x -= 0.3 * my_mlx->data->len;
	}
	if (key_code == 14)
	{
		my_mlx->data->data_c.mid_y -= 0.3 * my_mlx->data->len;
		ft_mlx_img_clear(my_mlx);
	}
	if (key_code == 15)
	{
		my_mlx->data->data_c.mid_y += 0.3 * my_mlx->data->len;
		ft_mlx_img_clear(my_mlx);
	}
	if (key_code == 16)
	{
		my_mlx->data->mul += 0.1;
		ft_mlx_img_clear(my_mlx);
	}
	if (key_code == 17)
	{
		my_mlx->data->mul -= 0.1;
		ft_mlx_img_clear(my_mlx);
	}
	return (0);
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

int	main_loop(t_mlx *my_mlx)
{
	double	a[3];
	double	b[3];

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

void	ft_fdf_init(t_list *data)
{
	t_center_list	data_c;

	data_c.mid_x = 0;
	data_c.mid_y = 0;
	data_c.mid_z = 0;
	data_c.theta = 180 * acos(1 / sqrt(3)) / M_PI;
	data_c.alpha = 135;
	data_c.t = 0;
	data->k = sin(ft_radian(data_c.theta)) * sin(ft_radian(data_c.alpha));
	data->data_c = data_c;
	data->len = 500 / sqrt(pow(data->row / 2, 2) + pow(data->col / 2, 2)
			+ pow((data->max_val - data->min_val) / 2, 2));
	data->mul = 1;
}

int	main(int argc, char **argv)
{
	t_list	*data;
	t_mlx	my_mlx;

	data = (t_list *)malloc(sizeof(t_list));
	if (data == NULL)
		return (-1);
	if (argc != 2)
		return (-1);
	if (open_file(argv[1], data) == -1)
		exit(1);
	inputdata_push(data);
	ft_fdf_init(data);
	my_mlx.data = data;
	ft_mlx_init(&my_mlx, 1000);
	mlx_hook(my_mlx.win, 2, 0, &deal_key, &my_mlx);
	mlx_hook(my_mlx.win, 17, 0, &ft_close, &my_mlx);
	mlx_loop_hook(my_mlx.mlx, &main_loop, &my_mlx);
	mlx_loop(my_mlx.mlx);
}
