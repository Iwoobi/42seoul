#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

char	*ft_str_return(char **str, int *k)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	*k = -1;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
			return (ft_str_return_fin(str, &i, &j));
		i++;
	}
	*k = 0;
	if (k[1] == 0)
	{
		*k = 2;
		tmp = malloc(sizeof(char) * ft_strlen(*str, NULL, NULL, 0));
		if (!tmp)
			return (NULL);
		ft_join(&tmp, *str, 0);
		free(*str);
		*str = NULL;
		return (tmp);
	}
	return (NULL);
}

int	ft_read(int fd, char **str, char *buff, int size)
{
	int		i;
	char	*tmp;

	i = read(fd, buff, size);
	if (i <= 0)
		return (0);
	buff[i] = '\0';
	tmp = malloc(sizeof(char) * ft_strlen(*str, NULL, NULL, 0) + 1);
	if (!tmp)
		return (-2);
	ft_join(&tmp, *str, 4);
	if (*str != NULL)
		free(*str);
	*str = malloc(sizeof(char) * i + ft_strlen(tmp, NULL, NULL, 0) + 1);
	if (*str == NULL)
		return (-2);
	ft_join(str, tmp, 5);
	ft_join(str, buff, 1);
	free(tmp);
	return (i);
}

int	ft_list_fd_fin(int fd, t_list **list, int *i)
{
	*list = malloc(sizeof(t_list));
	(*list)->str = malloc(sizeof(char *));
	if (!(*list) || !((*list)->str))
	{
		i[0] = 1;
		i[1] = -2;
		return (-1);
	}
	*((*list)->str) = NULL;
	(*list)->fd_list = fd;
	(*list)->next = NULL;
	return (0);
}

char	**ft_list_fd(int fd, t_list **list, int *i)
{
	t_list	*save;
	char	**savestr;

	save = *list;
	while (*list != NULL)
	{
		if ((*list)->fd_list == fd)
		{
			savestr = (*list)->str;
			*list = save;
			return (savestr);
		}
		*list = (*list)->next;
	}
	if (ft_list_fd_fin(fd, list, i) == -1)
		return (NULL);
	savestr = (*list)->str;
	if (save != NULL)
	{
		ft_strlen(NULL, save, *list, 1);
		*list = save;
	}
	return (savestr);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	char			**str_backup;
	static t_list	*list;
	char			*str_return;
	int				i[2];

	i[0] = 3;
	str_backup = ft_list_fd(fd, &list, i);
	while (1)
	{
		if (i[0] == 0 || i[0] == 3)
			i[1] = ft_read(fd, str_backup, buff, BUFFER_SIZE);
		if ((i[1] == 0 && *str_backup == NULL) || i[1] == -2 || i[0] == -1)
		{
			ft_list_free(fd, &list);
			return (NULL);
		}
		str_return = ft_str_return(str_backup, &i[0]);
		if (str_return != NULL)
		{
			if (*str_backup == NULL)
				ft_list_free(fd, &list);
			return (str_return);
		}
	}
}
