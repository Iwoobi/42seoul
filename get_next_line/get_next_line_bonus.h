#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				fd_list;
	char			**str;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
char	**ft_list_fd(int fd, t_list *list);

#endif