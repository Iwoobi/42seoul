#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
void	ft_join(char **str, char *back, int flag);
int		ft_move_str(char **str, int a);
char	*ft_str_return_fin(char **str, int *i, int *j);
char	*ft_str_return(char **str, int *k);
int		ft_read(int fd, char **str, char *buff, int size);
char	*get_next_line(int fd);

#endif
