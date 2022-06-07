/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:27:08 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:11:57 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while (src[a] && a < n)
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return ;
}

static int	count_str(const char *str, char set, int q, int a)
{
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != set)
			count_str_2(count, &a);
		else
		{
			if (q == 1 && a == 1)
				return (count[1]);
			a = 0;
		}
		str++;
	}
	if (q == 1 && *str == '\0' && a == 1)
		return (count[1]);
	return (count[0]);
}

static int	ft_malloc_free(char **arr, int b)
{
	if (!arr[b])
	{
		while (b >= 0)
		{
			free(arr[b]);
			b--;
		}
		free(arr);
		return (-1);
	}
	return (1);
}

static int	ft_skipstr(const char *str, char set)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == set)
		{
			str++;
			i++;
		}
		else
			return (i);
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		a;
	int		b;
	int		i;

	b = 0;
	i = 0;
	a = count_str(s, c, 0, 0);
	arr = (char **)malloc(sizeof(char *) * (a + 1));
	if (!arr)
		return (NULL);
	while (b < a)
	{
		s += ft_skipstr(s, c);
		i = count_str(s, c, 1, 1);
		arr[b] = (char *)malloc(sizeof(char) * i + 1);
		if (ft_malloc_free(arr, b) == -1)
			return (NULL);
		ft_strncpy(arr[b], s, i);
		s = s + i;
		b++;
	}
	arr[a] = NULL;
	return (arr);
}
