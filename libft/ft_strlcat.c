/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:47:20 by youhan            #+#    #+#             */
/*   Updated: 2021/12/14 17:51:02 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_con(size_t *i, size_t size)
{
	if (*i > size)
	{
		*i = size;
		size = 1;
	}
	else
		size = size - *i;
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst++ != '\0')
		i++;
	dst--;
	size = ft_size_con(&i, size);
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
	if (size >= 1)
		*dst = '\0';
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *dest; 
// 	dest = malloc(sizeof(char)*15);
// 	memset(dest,0,15);
// 	memset(dest,'r',6);
// 	printf("%zu\n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 	printf("%s",dest);
// }