/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:01:04 by youhan            #+#    #+#             */
/*   Updated: 2021/12/03 18:35:57 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	val;
	const char		*ptr_a;

	val = (unsigned char)value;
	ptr_a = (const char *)ptr;
	while (num > 0 && *ptr_a != '\0')
	{
		if (*ptr_a == val)
			return ((void *)ptr_a);
		ptr_a++;
		num--;
	}
	return (NULL);
}
