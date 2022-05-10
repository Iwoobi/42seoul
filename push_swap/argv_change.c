/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:55:06 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 19:25:16 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

char	*ft_strjoin(char **s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = ft_strlen(*s1);
	j = ft_strlen(s2);
	str = malloc((i + j) * sizeof(char) + 2);
	if (!str)
		return (NULL);
	k = 0;
	while (k < i + j)
	{
		if (k < i)
			str[k] = (*s1)[k];
		if (k < j)
			str[k + i] = s2[k];
		k++;
	}
	str[i + j] = ' ';
	str[i + j + 1] = '\0';
	if ((*s1) != NULL)
		free(*s1);
	return (str);
}

int	ft_non_num_check(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			check = 1;
		i++;
	}
	if (check == 0)
		return (-1);
	return (1);
}

void	ft_make_arg(int *argc, char ***argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = 1;
	tmp = 0;
	while (i < *argc)
	{
		if (ft_non_num_check((*argv)[i]) == -1)
			ft_error_printf();
		tmp = ft_strjoin(&tmp, (*argv)[i]);
		i++;
	}
	*argv = ft_split(tmp, ' ');
	free(tmp);
	i = 1;
	while ((*argv)[i])
		i++;
	*argc = i;
}
