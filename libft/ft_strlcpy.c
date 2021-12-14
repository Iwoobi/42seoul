/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:47:49 by youhan            #+#    #+#             */
/*   Updated: 2021/12/14 17:19:19 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src != '\0')
	{
		if (size > 1)
		{
			*dest++ = *src;
			size--;
		}
		src++;
		i++;
	}
	if (size >= 1)
		*dest = '\0';
	return (i);
}
