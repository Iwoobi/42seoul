#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd_list;
	char			**str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

# endif