/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:09:53 by youhan            #+#    #+#             */
/*   Updated: 2022/05/12 22:59:18 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include "ft_fdf.h"
#include <math.h>

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
			printf("(%f, %f, %f)", (data->arr)[i][j][0], (data->arr)[i][j][1], (data->arr)[i][j][2]);
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
void	point_rotate(t_list *data, t_center_list *data_center)
{
	int	i;
	int	j;
	double	a;
	double	b;
	double	c;

	a = data->arr[i][j][0] = data_center->n_veter[0] * data_center->n_veter[3] + data_center->n_veter[1] * data_center->n_veter[3] + data_center->n_veter[2];
	b = data->arr[i][j][1] = data_center->n_veter[1] - data_center->n_veter[3];
	b = data->arr[i][j][2] = data_center->n_veter[3] - data_center->n_veter[0] * data_center->n_veter[2] - data_center->n_veter[1] * data_center->n_veter[2];

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			(data->arr)[i][j][0] * a + (data->arr)[i][j][1] * b + (data->arr)[i][j][2] * c; 
			j++; /// 회전부분
		}
		i++;
	}

}
void	find_point(t_list *data, t_center_list *data_center)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			(data->arr)[i][j][0] = (data_center->n_veter[0]) * (data->arr)[i][j][3] + (data->arr)[i][j][0];
			(data->arr)[i][j][0] = (data_center->n_veter[1]) * (data->arr)[i][j][3] + (data->arr)[i][j][1];
			(data->arr)[i][j][0] = (data_center->n_veter[2]) * (data->arr)[i][j][3] + (data->arr)[i][j][2];
			j++;
		}
		i++;
	}
}
void	ft_fdf(t_list *data)
{
	t_center_list	*data_center;
	int				i;
	int				j;

	i = 0;
	data_center = (t_center_list *)malloc(sizeof(t_center_list));
	if (data_center == NULL)
		exit(1);
	data_center->mid_x = 0;
	data_center->mid_y = 0;
	data_center->mid_z = 0;
	data_center->theta = 45;
	data_center->alpha = 45;
	data_center->n_veter[0] = cos(ft_radian(data_center->theta));
	data_center->n_veter[1] = sin(ft_radian(data_center->theta));
	data_center->n_veter[2] = sin(ft_radian(data_center->alpha));
	data_center->n_veter[3] = cos(ft_radian(data_center->alpha));
	translation_x_y_z(data, -(data->col)/2 - data_center->mid_x, -(data->row)/2 - data_center->mid_y, -(data->max_val - data->min_val)/2 + data_center->mid_z);
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			(data->arr)[i][j][3] = -1 * ((data->arr)[i][j][0]
				* data_center->n_veter[0] + (data->arr)[i][j][1]
				* data_center->n_veter[1] + (data->arr)[i][j][2]
				* data_center->n_veter[2])
				/ (1 + data_center->n_veter[2] * data_center->n_veter[2]);
			j++;
		}
		i++;
	}
	find_point(data, data_center);
	point_rotate(data, data_center);
	print_arr(data);
}

int	main(int argc, char **argv)
{
	t_list *data;

	data = (t_list *)malloc(sizeof(t_list));
	if (data == NULL)
		return (-1);
	if (argc != 2)
		return (-1);
	if (open_file(argv[1], data) == -1)
		exit(1);
	inputdata_push(data);
	print_arr(data);
	ft_fdf(data);
	
}
