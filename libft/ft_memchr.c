/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:01:04 by youhan            #+#    #+#             */
/*   Updated: 2021/12/14 17:58:21 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const char		*ptr_a;

	ptr_a = (const char *)ptr;
	while (num > 0 && *ptr_a != '\0')
	{
		if (*ptr_a == value)
			return ((void *)ptr_a);
		ptr_a++;
		num--;
	}
	if (*ptr_a =='\0' && value == 0)
		return ((void *)ptr_a);
	return (NULL);
}
