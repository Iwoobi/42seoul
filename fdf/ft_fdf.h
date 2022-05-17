#ifndef FT_FDF_H
# define FT_FDF_H

#define _USE_MATH_DEFINES


typedef struct s_center_list
{
	double 	theta;
	double	alpha;
	double	t;
	double	mid_x;
	double	mid_y;
	double	mid_z;
	double	n[3];
}	t_center_list;

typedef struct s_list
{
	int			col;
	int			row;
	double		min_val;
	double		max_val;
	int 		*arr_size;
	double		***arr;
	double		***arr_copy;
	char		**input_data;
	double		len;
	double		mul;
	double		k;
	t_center_list	data_c;
}	t_list;

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_list	*data;
}	t_mlx;

typedef struct	s_line
{
	int			w;
	int			h;
	int			d;
	int			x;
	int			y;
}	t_line;

int		ft_strlen(char *str);
char	**ft_split(const char *s, char c);
void	count_str_2(int *count, int *a);

#endif
