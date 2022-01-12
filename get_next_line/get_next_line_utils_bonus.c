/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:02:35 by youhan            #+#    #+#             */
/*   Updated: 2022/01/12 16:44:45 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str, t_list *list, t_list *add, int flag)
{
	int	i;

	if (flag == 0)
	{
		i = 0;
		if (str == NULL)
			return (0);
		while (str[i] != '\0')
			i++;
		return (i);
	}
	while ((list)->next != NULL)
		list = (list)->next;
	(list)->next = add;
	return (0);
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
	tmp = malloc(sizeof(char) * ft_strlen(&((*str)[a]), NULL, NULL, 0) + 1);
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
