/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 02:11:30 by youhan            #+#    #+#             */
/*   Updated: 2021/12/14 19:01:31 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_malloc_count(long long n, int *sign, int *malloc_count)
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
	long	n_1;

	ft_malloc_count(n, &sign, &malloc_count);
	n_1 = n;
	if (n_1 < 0)
		n_1 = n_1 * (-1);
	n_address = malloc(sizeof(char) * malloc_count + 1);
	if (!n_address)
		return (NULL);
	n_address[malloc_count] = '\0';
	while (malloc_count-- >= 0)
	{
		n_address[malloc_count] = '0' + n_1 % 10;
		n_1 = n_1 / 10;
	}
	if (sign == -1)
		n_address[0] = '-';
	return (n_address);
}
