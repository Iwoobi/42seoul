/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:54:02 by youhan            #+#    #+#             */
/*   Updated: 2022/01/12 16:44:36 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char	*ft_str_return_fin(char **str, int *i, int *j);
void	ft_list_free(int fd, t_list **list);
int		ft_move_str(char **str, int a);
void	ft_join(char **str, char *back, int flag);
int		ft_strlen(char *str, t_list *list, t_list *add, int flag);
char	*ft_str_return(char **str, int *k);
int		ft_read(int fd, char **str, char *buff, int size);
int		ft_list_fd_fin(int fd, t_list **list, int *i);
char	**ft_list_fd(int fd, t_list **list, int *i);

#endif
