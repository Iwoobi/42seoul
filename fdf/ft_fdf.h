/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 03:20:28 by youhan            #+#    #+#             */
/*   Updated: 2022/05/27 03:20:28 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define _USE_MATH_DEFINES

# include <stdio.h>
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"

typedef struct s_center_list
{
	double	theta;
	double	alpha;
	double	t;
	double	mid_x;
	double	mid_y;
	double	mid_z;
	double	n[3];
}	t_center_list;

typedef struct s_list
{
	int				col;
	int				row;
	double			min_val;
	double			max_val;
	int				*arr_size;
	double			***arr;
	double			***arr_copy;
	char			**input_data;
	double			len;
	double			mul;
	double			k;
	t_center_list	data_c;
}	t_list;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_list	*data;
}	t_mlx;

typedef struct s_line
{
	int			w;
	int			h;
	int			d;
	int			x;
	int			y;
}	t_line;

long long	ft_atoi(char *str);
double		ft_radian(int a);
void		error_data_wrong(void);
int			open_file(char *file_name, t_list *data);
int			ft_strlen(char *str);
char		**ft_split(const char *s, char c);
void		count_str_2(int *count, int *a);
void		input_data_copy(t_list *data);
void		find_max_z(t_list *data);
void		inputdata_push(t_list *data);
void		translation_x_y_z(t_list *data, double x_val,
				double y_val, double z_val);
void		arr_multiplication(t_list *data, double x_val,
				double y_val, double z_val);
void		ft_fdf_init(t_list *data);
void		ft_mlx_init(t_mlx *my_mlx, int size);
int			ft_close(void);
int			main_loop(t_mlx *my_mlx);
void		ft_fdf(t_list *data);
void		draw_lines(t_list *data, t_mlx *my_mlx);
int			deal_key(int key_code, t_mlx *my_mlx);

#endif
