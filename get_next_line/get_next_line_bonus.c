/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:44:07 by youhan            #+#    #+#             */
/*   Updated: 2021/12/21 20:52:43 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct s_list
{
	int				fd_list;
	char			**str;
	struct s_list	*next;
}				t_list;

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_join(char **str, char *back, int flag)
{
	int	i;
	int	j;
	static int k;

	k++;


	i = 0;
	j = 0;
	if (flag == 1)
	{
		while ((*str)[i] != '\0')
			i++;
	}
	while (back[j] != '\0')
	{
		(*str)[i + j] = back[j];
		j++;
	}
	(*str)[i + j] = '\0';
}

static int	ft_move_str(char ***str, int a)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(&((**str)[a])) + 1);
	if (!tmp)
		return (-1);
	while ((**str)[a + i] != '\0')
	{
		tmp[i] = (**str)[a + i];
		i++;
	}
	tmp[i] = '\0';
	free((**str));
	(**str) = malloc(sizeof(char) * i + 1);
	if (!(**str))
		return (-1);
	ft_join(*str, tmp, 2);
	free(tmp);
	return (1);
}

static char	*ft_str_return(char ***str, int *k)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	*k = -1;
	while ((**str)[i] != '\0')
	{
		if ((**str)[i] == '\n')
		{
			j = i;
			tmp = malloc(sizeof(char) * (i + 1) + 1);
			if (!tmp)
				return (NULL);
			tmp[i + 1] = '\0';
			while (i-- + 1 > 0)
				tmp[i + 1] = (**str)[i + 1];
			if ((**str)[j + 1] == '\0')
			{
				free(**str);
				**str = NULL;
				return (tmp);
			}
			if (ft_move_str(str, j + 1) == -1)
				return (NULL);
			return (tmp);
		}
		i++;
	}
	*k = 0;
	if (k[1] == 0)
	{
		tmp = malloc(sizeof(char) * ft_strlen(**str) + 1);
		ft_join(&tmp, **str, 0);
		free(**str);
		**str=NULL;
		*k=2;
		return (tmp);
	}
	return (NULL);
}

static int	ft_read(int fd, char ***str, char *buff, int size)
{
	int		i;
	char	*tmp;

	i = read(fd, buff, size);
	if (i <= 0)
		return (0);
	buff[i] = '\0';
	if (**str == NULL)
	{
		**str = malloc(sizeof(char) * i + 1);
		if (!(**str))
			return (-2);
		ft_join(*str, buff, 3);
		return (i);
	}
	tmp = malloc(sizeof(char) * ft_strlen(**str) + 1);
	if (!tmp)
		return (-2);
	ft_join(&tmp,**str, 4);
	free(**str);
	**str = malloc(sizeof(char) * i + ft_strlen(tmp) + 1);
	if (!tmp)
		return (-2);
	ft_join(*str, tmp, 5);
	ft_join(*str, buff, 1);
	free(tmp);
	return (i);
}

char	**ft_list_fd(int fd, t_list *list)
{
	while(list->next != NULL)
	{
		if (list->fd_list == fd)
			return (list->str);
		list = list->next;
	}
	if (list->fd_list == fd)
		return (list->str);
	list->next = malloc(sizeof(t_list));
	(list->next)->str = malloc(sizeof(char *) * 1);
	*((list->next)->str) = NULL;
	(list->next)->fd_list = fd;
	(list->next)->next = NULL;
	return ((list->next)->str);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		**str_backup;
	static t_list	*list;
	char		*str_return;
	int			i[3];

	i[0] = 3;
	if (fd < 0)
		return (NULL);
	if (list == NULL)
	{
		list = malloc(sizeof(t_list));
		list->next = NULL;
		list->str = malloc(sizeof(char *) * 1);
		*(list->str) = NULL;
		list->fd_list = fd;
	}
	str_backup = ft_list_fd(fd, list);
	while (1)
	{
		if (i[0] == 0 || i[0] == 3)
			i[1] = ft_read(fd, &str_backup, buff, BUFFER_SIZE);
		printf("%s\n",*str_backup);
		if (i[1] == -2 || i[0] == -1)
			return (NULL);
		if (i[1] == 0 && *str_backup == NULL)
			return (NULL);
		str_return = ft_str_return(&str_backup, &i[0]);
		if (str_return != NULL)
			return (str_return);
	}
}
int main()
{
	int	fd;
	
	fd = open("asd.txt", O_RDONLY);
	printf("%s:",get_next_line(fd));
	printf("%s:",get_next_line(fd));
	printf("%s:",get_next_line(fd));
	printf("%s:",get_next_line(fd));
	printf("%s:",get_next_line(fd));
	printf("%s:",get_next_line(fd));
	close(fd);
}

