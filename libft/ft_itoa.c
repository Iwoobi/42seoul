/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 02:11:30 by youhan            #+#    #+#             */
/*   Updated: 2021/12/12 02:11:30 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_malloc_count(int n, int *sign, int *malloc_count)
{
	*malloc_count = 1;
	*sign = 1;
	if (n < 0)
	{
		*sign = -1;
		*malloc_count = *malloc_count + 1;
		n = -1 * n;
	}
	while (n > 0)
	{
		n = n / 10;
		if (n == 0)
			return ;
		*malloc_count = *malloc_count + 1;
	}
	return ;
}

char	*ft_itoa(int n)
{
	int		malloc_count;
	int		sign;
	char	*n_address;

	ft_malloc_count(n, &sign, &malloc_count);
	if (n < 0)
		n = n * (-1);
	n_address = malloc(sizeof(char) * malloc_count + 1);
	if (!n_address)
		return (NULL);
	n_address[malloc_count] = '\0';
	while (malloc_count-- >= 0)
	{
		n_address[malloc_count] = '0' + n % 10;
		n = n / 10;
	}
	if (sign == -1)
		n_address[0] = '-';
	return (n_address);
}
