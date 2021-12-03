/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:17:21 by youhan            #+#    #+#             */
/*   Updated: 2021/12/03 20:50:45 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
void    *ft_calloc(size_t count, size_t size)
{
	unsigned char    *mem;

	mem = (unsigned char *)malloc(count * size);
	if (*mem)
		return (NULL);
	while (count > 0)
	{
		while (size >0)
		{
			*mem = 0;
			mem++;
			size--;
		}
		count--;
	}

}