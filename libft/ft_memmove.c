/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:13:50 by youhan            #+#    #+#             */
/*   Updated: 2021/11/23 16:21:44 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char		*dest_point;
	int			i;
	const char	*src_point;

	dest_point = dest;
	src_point = src;
	if (dest_point < src_point)
	{
		while (num > 0)
		{
			dest_point[num - 1] = src_point[num - 1];
			num--;
		}
	}
	else
	{
		i = 0;
		while (num > i)
		{
			dest_point[i] = *src_point[i];
			i++;
		}
	}
	return (dest);
}
