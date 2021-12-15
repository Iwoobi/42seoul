/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:01:04 by youhan            #+#    #+#             */
/*   Updated: 2021/12/15 17:59:07 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char		*ptr_a;

	ptr_a = (const unsigned char *)ptr;
	while (num > 0)
	{
		if (*ptr_a == (unsigned char)value)
			return ((void *)ptr_a);
		ptr_a++;
		num--;
	}
	return (NULL);
}
