/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:53:59 by youhan            #+#    #+#             */
/*   Updated: 2021/12/10 16:47:00 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const s1, char const *set)
{
	while (*set != '\0')
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

static void	ft_point(int *k, int *j, char const *s1, char const *set)
{
	int	i;
	int	a;

	a = 1;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_check_set(s1[i], set) && a == 1)
			*k = i + 1;
		else
			a = 0;
		i++;
	}
	a = 1;
	i--;
	while (i > 0 && *k < i)
	{
		if (ft_check_set(s1[i], set) && a == 1)
			*j = i - 1;
		else
			a = 0;
		i--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	k;
	int	j;

	k = 1;
	j = 1;
	ft_point(&k, &j, s1, set);
	return (ft_substr(s1, k + 1, j - k + 1));
}
