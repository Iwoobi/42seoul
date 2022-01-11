/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:54:18 by youhan            #+#    #+#             */
/*   Updated: 2022/01/11 19:54:18 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_list_add(t_list *list, t_list *add)
{
	while ((list)->next != NULL)
		list = (list)->next;
	(list)->next = add;
}

void	ft_join(char **str, char *back, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (back == NULL)
	{
		(*str)[0] = '\0';
		return ;
	}	
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

int	ft_move_str(char **str, int a)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(&((*str)[a])) + 1);
	if (!tmp)
		return (-1);
	while ((*str)[a + i] != '\0')
	{
		tmp[i] = (*str)[a + i];
		i++;
	}
	tmp[i] = '\0';
	free((*str));
	(*str) = malloc(sizeof(char) * i + 1);
	if (!(*str))
		return (-1);
	ft_join(str, tmp, 0);
	free(tmp);
	return (1);
}

void	ft_list_free(int fd, t_list **list)
{
	t_list	*save;
	t_list	*back;

	save = *list;
	while ((*list) != NULL)
	{
		if ((*list)->fd_list == fd)
		{
			free((*list)->str);
			if (save != *list)
				back->next = (*list)->next;
			else
			{
				back = *list;
				*list = (*list)->next;
				free(back);
				return ;
			}
			free(*list);
		}
		back = *list;
		*list = (*list)->next;
	}
	*list = save;
}

char	*ft_str_return_fin(char **str, int *i, int *j)
{
	char	*tmp;

	*j = *i;
	tmp = malloc(sizeof(char) * (*i + 1) + 1);
	if (!tmp)
		return (NULL);
	tmp[*i + 1] = '\0';
	while (*i >= 0)
	{
		tmp[*i] = (*str)[*i];
		*i = *i - 1;
	}
	if ((*str)[*j + 1] == '\0')
	{
		free(*str);
		*str = NULL;
		return (tmp);
	}
	if (ft_move_str(str, *j + 1) == -1)
		return (NULL);
	return (tmp);
}

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
		tmp = malloc(sizeof(char) * ft_strlen(*str));
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
	tmp = malloc(sizeof(char) * ft_strlen(*str) + 1);
	if (!tmp)
		return (-2);
	ft_join(&tmp, *str, 4);
	if (*str != NULL)
		free(*str);
	*str = malloc(sizeof(char) * i + ft_strlen(tmp) + 1);
	if (*str == NULL)
		return (-2);
	ft_join(str, tmp, 5);
	ft_join(str, buff, 1);
	free(tmp);
	return (i);
}

char	**ft_list_fd(int fd, t_list **list)
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
	*list = malloc(sizeof(t_list));
	(*list)->str = malloc(sizeof(char *));
	*((*list)->str) = NULL;
	(*list)->fd_list = fd;
	(*list)->next = NULL;
	savestr = (*list)->str;
	if (save != NULL)
	{
		ft_list_add(save, *list);
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
	str_backup = ft_list_fd(fd, &list);
	while (1)
	{
		if (i[0] == 0 || i[0] == 3)
			i[1] = ft_read(fd, str_backup, buff, BUFFER_SIZE);
		if (i[1] == 0 && *str_backup == NULL || i[1] == -2 || i[0] == -1)
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
