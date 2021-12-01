/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:50:36 by youhan            #+#    #+#             */
/*   Updated: 2021/12/01 17:48:51 by youhan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
void	ft_memcpy(void *dest, const void *source, unsigned int num)
{
	char		*dest_point;
	const char	*source_point;

	dest_point = dest;
	source_point = source;
	while (num > 0)
	{
		dest_point[num - 1] = source_point[num - 1];
		num--;
	}
}
