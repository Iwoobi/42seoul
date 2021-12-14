/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:03:10 by youhan            #+#    #+#             */
/*   Updated: 2021/12/14 18:12:32 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*ptr_1;
	const unsigned char	*ptr_2;

	ptr_1 = (const unsigned char *)ptr1;
	ptr_2 = (const unsigned char *)ptr2;
	while (num > 0)
	{
		if (*ptr_1 - *ptr_2 != 0)
			return (*ptr_1 - *ptr_2);
		num--;
		ptr_1++;
		ptr_2++;
	}
	return (0);
}
