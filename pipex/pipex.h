#ifndef PIPEX_H
# define PIPEX_H

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef struct s_fd
{
	int	r_fd;
	int	w_fd;
}	t_fd;

typedef struct s_list
{
	t_fd	fd;
	int		pipe_num;
	int		**p_fd;
	pid_t	*pid;
	int		bonus_mod;
	char	**path;
	char	*shell;
	char	***cmd;
	char	*limmit;
	char	*in_file;
	int		status;
	int		in_file_fd[2];
}	t_list;

void	count_str_2(int *count, int *a);
char	**ft_split(const char *s, char c);

#endif