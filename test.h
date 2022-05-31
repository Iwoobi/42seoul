#ifndef TEST_H
# define TEST_H

typedef struct s_fd
{
	int	o_fd;
	int	w_fd;
}	t_fd;

typedef struct s_list
{
	t_fd	fd;
	int		pipex_num;
}	t_list;

#endif