/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:30:22 by youhan            #+#    #+#             */
/*   Updated: 2021/12/15 18:52:25 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char *)s1);
	while (j + i < len)
	{
		if (s1[j] != '\0')
		{
			if (s1[j+i] == s2[i])
				i++;
			else
				i = 0;
			if (s2[i] == '\0')
				return ((char *)(s1 + j));
		}
		else
			return (NULL);
		if (i == 0)
			j++;
	}
	return (NULL);
}
