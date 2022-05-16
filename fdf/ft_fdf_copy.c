// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_fdf.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/05/12 17:09:53 by youhan            #+#    #+#             */
// /*   Updated: 2022/05/16 16:06:45 by youhan           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>
// #include "get_next_line.h"
// #include <fcntl.h>
// #include "ft_fdf.h"
// #include <math.h>
// #include "./mlx/mlx.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str == NULL)
// 		return (0);
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// long long	ft_atoi(char *str)
// {
// 	int			sign;
// 	long long	n;

// 	sign = 1;
// 	n = 0;
// 	while ((*str >= 9 && *str <= 13) || *str == 32)
// 		str++;
// 	if (*str == '-')
// 	{
// 		sign = -1;
// 		str++;
// 	}
// 	else if (*str == '+')
// 	{
// 		sign = 1;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 		n = n * 10 + *str++ - '0';
// 	return (n * sign);
// }

// void	error_data_wrong(void)
// {
// 	write(2, "worng input data\n", 16);
// 	exit(1);
// }
// void	str_data_num_check(char *data)
// {
// 	int	i;
// 	int	check;

// 	i = 0;
// 	check = 0;
// 	if (data[0] == '+' || data[0] == '-')
// 		i++;
// 	while (data[i])
// 	{
// 		if (!((data[i] >= '0' && data[i] <= '9') || data[i] == '\n'))
// 	 		exit(1);
// 		else
// 			check = 1;
// 		i++;
// 	}
// 	if (check == 0)
// 		exit(1);
// }
// void	split_data_check(char **data)
// {
// 	int	i;

// 	i = 0;
// 	if (data == NULL)
// 		exit(1);
// 	while (data[i])
// 	{
// 		str_data_num_check(data[i]);
// 		i++;
// 	}
// }

// void	split_data_push(t_list *data, char **split_data, int row)
// {
// 	int	col;
	
// 	col = 0;
// 	while (split_data[col])
// 		col++;
// 	(data->arr_size)[row] = col;
// 	(data->arr)[row] = (double **)malloc(sizeof(double *) * col);
// 	if ((data->arr)[row] == NULL)
// 		exit(1);
// 	col = 0;
// 	while (split_data[col])
// 	{
// 		(data->arr)[row][col] = (double *)malloc(sizeof(double) * 4);
// 		if ((data->arr)[row][col] == NULL)
// 			exit(1);
// 		(data->arr)[row][col][0] = (double)col;
// 		(data->arr)[row][col][1] = (double)row;
// 		(data->arr)[row][col][2] = (double)ft_atoi(split_data[col]);
// 		col++;
// 	}
// }
// void	row_col_count_check(t_list *data)
// {
// 	int	i;
// 	int	val;

// 	i = 0;
// 	val = (data->arr_size)[0];
// 	while (i < data->row)
// 	{
// 		if (val != (data->arr_size)[i])
// 			error_data_wrong();
// 		i++;
// 	}
// 	data->col = val;
// }
// void	find_max_z(t_list *data)
// {
// 	int		i;
// 	int		j;
// 	double	max_val;
// 	double	min_val;

// 	i = 0;
// 	max_val = (data->arr)[0][0][2];
// 	min_val = (data->arr)[0][0][2];
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->col)
// 		{
// 			if (max_val < (data->arr)[i][j][2])
// 				max_val = (data->arr)[i][j][2];
// 			if (min_val > (data->arr)[i][j][2])
// 				min_val = (data->arr)[i][j][2];
// 			j++;
// 		}
// 		i++;
// 	}
// 	data->max_val = max_val;
// 	data->min_val = min_val;
// }

// void	inputdata_push(t_list *data)
// {
// 	char	**split_data;
// 	int		i;

// 	i = 0;
// 	while (i < data->row)
// 	{
// 		split_data = ft_split((data->input_data)[i], ' ');
// 		if (!split_data)
// 			error_data_wrong();
// 		split_data_check(split_data);
// 		split_data_push(data ,split_data, i);
// 		i++;
// 	}
// 	row_col_count_check(data);
// 	find_max_z(data);
// }

// void	row_count(int fd, t_list *data)
// {
// 	int i;

// 	i = 0;
// 	while (get_next_line(fd))
// 		i++;
// 	data->row = i;
// }

// int	open_file(char *file_name, t_list *data)
// {
// 	int	fd;
// 	int i;

// 	i = 0;
// 	fd = open(file_name, O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	row_count(fd, data);
// 	data->arr_size = (int *)malloc(sizeof(int) * data->row);
// 	data->arr = (double ***)malloc(sizeof(double **) * data->row);
// 	data->input_data = (char **)malloc(sizeof(char *) * data->row);
// 	if (!(data->arr_size) || !(data->arr) || !(data->input_data))
// 		exit(1);
// 	close(fd);
// 	fd = open(file_name, O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	while (i < data->row)
// 	{
// 		(data->input_data)[i] = get_next_line(fd); 
// 		i++;
// 	}
// 	close(fd);
// 	return(1);
// }

// void	print_arr(t_list *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->arr_size[i])
// 		{
// 			printf("(%f, %f, %f)", floor((data->arr)[i][j][0]), floor((data->arr)[i][j][1]), (data->arr)[i][j][2]);
// 			if (j == data->arr_size[i] - 1)
// 				printf("\n");
// 			else
// 				printf(" ");
// 			j++;
// 		}
// 		i++;
// 	}
// }
// void	translation_x_y_z(t_list *data ,double x_val, double y_val, double z_val)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->col)
// 		{
// 			(data->arr)[i][j][0] += x_val;
// 			(data->arr)[i][j][1] += y_val;
// 			(data->arr)[i][j][2] += z_val;
// 			j++;
// 		}
// 		i++;
// 	}
// }
// void	arr_multiplication(t_list *data, double x_val, double y_val, double z_val)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->col)
// 		{
// 			(data->arr)[i][j][0] *= x_val;
// 			(data->arr)[i][j][1] *= y_val;
// 			(data->arr)[i][j][2] *= z_val;
// 			j++;
// 		}
// 		i++;
// 	}
// }
// void	printf_t(t_list *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->arr_size[i])
// 		{
// 			printf("(%f)", (data->arr)[i][j][3]);
// 			if (j == data->arr_size[i] - 1)
// 				printf("\n");
// 			else
// 				printf(" ");
// 			j++;
// 		}
// 		i++;
// 	}

// }
// double	ft_radian(int a)
// {
// 	return ((double)(a * M_PI) / 180);
// }
// void	point_rotate(t_list *data, double theta, double alpha)
// {
// 	int	i;
// 	int	j;
// 	double	x;
// 	double	y;
// 	double	z;
	
// 	i = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->col)
// 		{
// 			x = (data->arr)[i][j][0];
// 			y = (data->arr)[i][j][1];
// 			z = (data->arr)[i][j][2];
// 			(data->arr)[i][j][0] = cos(theta) * cos(alpha) * x + cos(theta) * sin(alpha) * y - sin(theta) * z;  
// 			(data->arr)[i][j][1] = -sin(alpha) * x + cos(alpha) * y;
// 			(data->arr)[i][j][2] = sin(theta) * cos(alpha) * x + sin(theta) * sin(alpha) * y + cos(theta) * z;
// 			j++;
// 		}
// 		i++;
// 	}

// }
// void	find_point(t_list *data, t_center_list *data_c)
// {
// 	int	i;
// 	int	j;
// 	double	x;
// 	double	y;
// 	double	z;

// 	i = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->col)
// 		{
// 			x = (data->arr)[i][j][0];
// 			y = (data->arr)[i][j][1];
// 			z = (data->arr)[i][j][2];
// 			(data->arr)[i][j][0] = data_c->n[0] * (data->arr)[i][j][3] + x;
// 			(data->arr)[i][j][1] = data_c->n[1] * (data->arr)[i][j][3] + y;
// 			(data->arr)[i][j][2] = data_c->n[2] * (data->arr)[i][j][3] + z;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	rotate_point(t_list *data, double theta)
// {
// 	int	i;
// 	int	j;
// 	double	x;
// 	double	y;

// 	i = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->col)
// 		{
// 			x = (data->arr)[i][j][0];
// 			y = (data->arr)[i][j][1];
// 			(data->arr)[i][j][0] = cos(theta) * x - sin(theta) * y;
// 			(data->arr)[i][j][1] = sin(theta) * x + cos(theta) * y;
// 			j++;
// 		}
// 		i++;
// 	}

// }
// void	ft_fdf(t_list *data)
// {
// 	t_center_list	*data_c;
// 	int				i;
// 	int				j;

// 	data_c = (t_center_list *)malloc(sizeof(t_center_list));
// 	if (data_c == NULL)
// 		exit(1);
// 	data_c->mid_x = 0;
// 	data_c->mid_y = 0;
// 	data_c->mid_z = 0;
// 	data_c->theta = 60;
// 	data_c->alpha = -45;
// 	data_c->n[0] = sin(ft_radian(data_c->theta)) * cos(ft_radian(data_c->alpha));
// 	data_c->n[1] = sin(ft_radian(data_c->theta)) * sin(ft_radian(data_c->alpha));
// 	data_c->n[2] = cos(ft_radian(data_c->theta));
// 	translation_x_y_z(data, -(data->col)/2 - data_c->mid_x, -(data->row)/2 - data_c->mid_y, -(data->max_val - data->min_val)/2 + data_c->mid_z);
// 	i = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->col)
// 		{
// 			(data->arr)[i][j][3] = -1 * ((data->arr)[i][j][0]
// 				* data_c->n[0] + (data->arr)[i][j][1]
// 				* data_c->n[1] + (data->arr)[i][j][2]
// 				* data_c->n[2]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	find_point(data, data_c);
// 	point_rotate(data, ft_radian(data_c->theta), ft_radian(data_c->alpha));
// }

// void	draw_line(double *start, double *fin, t_mlx *my_mlx)
// {
// 	int	w;
// 	int	h;
// 	int	d;
// 	int	x;
// 	int	y;

// 	x = (int)(start[0]);
// 	y = (int)(start[1]);
// 	w = fabs(start[0] - fin[0]);
// 	h = fabs(start[1] - fin[1]);
// 	if (w > h)
// 	{
// 		d = (2 * h) - w;
//  		while (x != (int)(fin[0]))
// 		{
// 			if (d < 0)
// 				d += 2 * h;
// 			else
// 			{
// 				y++;
// 				if (start[1] - fin[1] > 0)
// 					y -= 2;
// 				d += (2 * h - 2 * w);
// 			}
// 			my_mlx->img.data[y * 900 + x] = 0xFFFFFF;
// 			x++;
// 			if (start[0] - fin[0]> 0)
// 				x -= 2;
// 		}
// 	}
// 	else
// 	{
// 		d = (2 * w) - h;
//  		while (y != (int)fin[1])
// 		{
//   			if (d < 0)
// 				d += 2 * w;
// 			else
// 			{
// 				x++;
// 				if (start[0] - fin[0]> 0)
// 					x -= 2;
// 				d += (2 * w - 2 * h);
// 			}
// 			my_mlx->img.data[y * 900 + x] = 0xFFFFFF;
// 			y++;
// 			if (start[1] - fin[1] > 0)
// 				y -= 2;
// 		}
// 	}
// }

// void	draw_lines(t_list *data, t_mlx *my_mlx)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->col)
// 		{
// 			if (j != data->col - 1)
// 				draw_line((data->arr)[i][j], (data->arr)[i][j + 1], my_mlx);
// 			if (i != data->row - 1)
// 				draw_line((data->arr)[i][j], (data->arr)[i + 1][j], my_mlx);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	ft_mlx_init(t_mlx *my_mlx, int	size)
// {
// 	my_mlx->mlx = mlx_init();
// 	my_mlx->win = mlx_new_window(my_mlx->mlx, size, size, "FDF");
// 	my_mlx->img.img = mlx_new_image(my_mlx->mlx, size - 100, size - 100);
// 	my_mlx->img.data = (int *)mlx_get_data_addr(my_mlx->img.img, &my_mlx->img.bpp, &my_mlx->img.size_l, &my_mlx->img.endian);
// }

// int 	ft_close(void)
// {
// 		exit(0);
// }

// int		deal_key(int key_code)
// {
// 	if (key_code == 53)
// 		exit(0);
// 	return (0);
// }
// int		main_loop(t_mlx *my_mlx)
// {
// 	draw_lines(my_mlx->data, my_mlx);
// 	mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, my_mlx->img.img, 0, 0);
// 	return (0);
// }
// int	main(int argc, char **argv)
// {
// 	t_list	*data;
// 	t_mlx	my_mlx;

// 	data = (t_list *)malloc(sizeof(t_list));
// 	if (data == NULL)
// 		return (-1);
// 	if (argc != 2)
// 		return (-1);
// 	if (open_file(argv[1], data) == -1)
// 		exit(1);
// 	inputdata_push(data);
// 	ft_fdf(data);
// 	print_arr(data);
// 	arr_multiplication(data, 40, 40, 40);
// 	translation_x_y_z(data, 500, 500, 0);
// 	my_mlx.data = data;
// 	ft_mlx_init(&my_mlx, 1000);
// 	mlx_hook(my_mlx.win, 2, 0, &deal_key, &my_mlx);
// 	mlx_hook(my_mlx.win, 17, 0, &ft_close, &my_mlx);
// 	mlx_loop_hook(my_mlx.mlx, &main_loop, &my_mlx);
// 	mlx_loop(my_mlx.mlx);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:09:53 by youhan            #+#    #+#             */
/*   Updated: 2022/05/16 16:05:18 by youhan           ###   ########.fr       */
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
		if (!((data[i] >= '0' && data[i] <= '9') || data[i] == '\n'))
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
		split_data_push(data ,split_data, i);
		i++;
	}
	row_col_count_check(data);
	find_max_z(data);
}

void	row_count(int fd, t_list *data)
{
	int i;

	i = 0;
	while (get_next_line(fd))
		i++;
	data->row = i;
}

int	open_file(char *file_name, t_list *data)
{
	int	fd;
	int i;

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
	return(1);
}

void	print_arr(t_list *data)
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
}
void	translation_x_y_z(t_list *data ,double x_val, double y_val, double z_val)
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
void	arr_multiplication(t_list *data, double x_val, double y_val, double z_val)
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
	int	i;
	int	j;
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
			(data->arr)[i][j][0] = cos(theta) * cos(alpha) * x + cos(theta) * sin(alpha) * y - sin(theta) * z;  
			(data->arr)[i][j][1] = -sin(alpha) * x + cos(alpha) * y;
			(data->arr)[i][j][2] = sin(theta) * cos(alpha) * x + sin(theta) * sin(alpha) * y + cos(theta) * z;
			j++;
		}
		i++;
	}

}
void	find_point(t_list *data, t_center_list *data_c)
{
	int	i;
	int	j;
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
	int	i;
	int	j;
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
	data_c->n[0] = sin(ft_radian(data_c->theta)) * cos(ft_radian(data_c->alpha));
	data_c->n[1] = sin(ft_radian(data_c->theta)) * sin(ft_radian(data_c->alpha));
	data_c->n[2] = cos(ft_radian(data_c->theta));
	translation_x_y_z(data, -(data->col)/2 - data_c->mid_x, -(data->row)/2 - data_c->mid_y, -(data->max_val - data->min_val)/2 + data_c->mid_z);
}
void	ft_fdf(t_list *data)
{
	ft_fdf_n_vector(data, &(data->data_c));
	ft_fdf_n_vector_t(data, &(data->data_c));
	find_point(data, &(data->data_c));
	point_rotate(data, ft_radian((data->data_c).theta), ft_radian((data->data_c).alpha));
	
}

void	draw_line(double *start, double *fin, t_mlx *my_mlx)
{
	int	w;
	int	h;
	int	d;
	int	x;
	int	y;

	x = (int)(start[0]);
	y = (int)(start[1]);
	w = fabs(start[0] - fin[0]);
	h = fabs(start[1] - fin[1]);
	if (w > h)
	{
		d = (2 * h) - w;
 		while (x != (int)(fin[0]))
		{
			if (d < 0)
				d += 2 * h;
			else
			{
				y++;
				if (start[1] - fin[1] > 0)
					y -= 2;
				d += (2 * h - 2 * w);
			}
			my_mlx->img.data[y * 900 + x] = 0xFFFFFF;
			x++;
			if (start[0] - fin[0]> 0)
				x -= 2;
		}
	}
	else
	{
		d = (2 * w) - h;
 		while (y != (int)fin[1])
		{
  			if (d < 0)
				d += 2 * w;
			else
			{
				x++;
				if (start[0] - fin[0]> 0)
					x -= 2;
				d += (2 * w - 2 * h);
			}
			my_mlx->img.data[y * 900 + x] = 0xFFFFFF;
			y++;
			if (start[1] - fin[1] > 0)
				y -= 2;
		}
	}
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

void	ft_mlx_init(t_mlx *my_mlx, int	size)
{
	my_mlx->mlx = mlx_init();
	my_mlx->win = mlx_new_window(my_mlx->mlx, size, size, "FDF");
	my_mlx->img.img = mlx_new_image(my_mlx->mlx, size - 100, size - 100);
	my_mlx->img.data = (int *)mlx_get_data_addr(my_mlx->img.img, &my_mlx->img.bpp, &my_mlx->img.size_l, &my_mlx->img.endian);
}

int 	ft_close(void)
{
		exit(0);
}

int		deal_key(int key_code)
{
	if (key_code == 53)
		exit(0);
	return (0);
}
int		main_loop(t_mlx *my_mlx)
{
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
	data_c.theta = 60;
	data_c.alpha = -45;
	data->data_c = data_c;
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
	printf("\n\nx,y,z,t,a:%f, %f, %f, %f, %f\n\n ", data->data_c.mid_x, data->data_c.mid_y, data->data_c.mid_z, data->data_c.theta, data->data_c.alpha  );
	ft_fdf(data);
	
	arr_multiplication(data, 40, 40, 40);
	translation_x_y_z(data, 500, 500, 0);
	my_mlx.data = data;
	ft_mlx_init(&my_mlx, 1000);
	mlx_hook(my_mlx.win, 2, 0, &deal_key, &my_mlx);
	mlx_hook(my_mlx.win, 17, 0, &ft_close, &my_mlx);
	mlx_loop_hook(my_mlx.mlx, &main_loop, &my_mlx);
	mlx_loop(my_mlx.mlx);
}

