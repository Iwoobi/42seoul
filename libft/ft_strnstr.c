/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:30:22 by youhan            #+#    #+#             */
/*   Updated: 2021/12/13 18:39:31 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (len > 0)
	{
		if (*s1 != '\0')
		{
			if (*s1 == s2[i])
				i++;
			else
				i = 0;
			if (s2[i] == '\0')
				return ((char *)s1 - i + 1);
			s1++;
		}
		len--;
	}
	return (NULL);
}
