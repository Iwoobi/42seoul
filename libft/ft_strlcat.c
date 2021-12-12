/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:47:20 by youhan            #+#    #+#             */
/*   Updated: 2021/12/13 03:47:20 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst++ != '\0')
		i++;
	dst--;
	if (i > size)
	{
		i = size;
		size = 1;
	}
	else
		size = size - i;
	while (*src != '\0')
	{
		if (size > 1)
		{
			*dst++ = *src;
			size--;
		}
		src++;
		i++;
	}
	*dst = '\0';
	return (i);
}
