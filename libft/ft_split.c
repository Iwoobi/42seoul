/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:46:41 by youhan            #+#    #+#             */
/*   Updated: 2021/12/10 18:54:05 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_strncpy(char *dest, char *src, unsigned int n)
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

static int	count_str(char *str, char set, int q, int a)
{
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	while (*str)
	{
		if (*str != set)
		{
			if (a == 0)
				count[0] += 1;
			else
				count[1] += 1;
			a = 1;
		}
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

static char	*ft_skipstr(char *str, char set)
{
	while (*str)
	{
		if (*str == set)
			str++;
		else
			return (str);
	}
	return (str);
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	int		a;
	int		b;
	int		i;

	b = -1;
	i = 0;
	a = count_str(str, c, 0, 0);
	arr = (char **)malloc(sizeof(char *) * a + 1);
	if (!arr)
		return (NULL);
	while (b++ < a)
	{
		str = ft_skipstr(str, c);
		i = count_str(str, c, 1, 1);
		arr[b] = (char *)malloc(sizeof(char) * i + 1);
		if (!arr[b])
			return (NULL);
		ft_strncpy(arr[b], str, i);
		str = str + i;
	}
	arr[b] = NULL;
	return (arr);
}
