#ifndef FT_FDF_H
# define FT_FDF_H

#define _USE_MATH_DEFINES

typedef struct s_list
{
	int			col;
	int			row;
	double		min_val;
	double		max_val;
	int 		*arr_size;
	double		***arr;
	char		**input_data;
}	t_list;

typedef struct s_center_list
{
	int 	theta;
	int		alpha;
	int		mid_x;
	int		mid_y;
	int		mid_z;
	double	n[3];
}	t_center_list;

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

}	t_mlx;

int		ft_strlen(char *str);
char	**ft_split(const char *s, char c);
void	count_str_2(int *count, int *a);

#endif
