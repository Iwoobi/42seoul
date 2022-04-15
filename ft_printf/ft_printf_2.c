/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:37:26 by youhan            #+#    #+#             */
/*   Updated: 2022/04/15 19:27:38 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen])
		strlen++;
	return (strlen);
}

void	ft_malloc_count_hexad(unsigned long long n, int *sign,
int *malloc_count, int base)
{
	*malloc_count = 1;
	*sign = 1;
	while (n > 0)
	{
		n = n / base;
		if (n == 0)
			return ;
		*malloc_count = *malloc_count + 1;
	}
	return ;
}

char	*ft_itoa_base_hexad(unsigned long long n, int base, int mod)
{
	int		malloc_count;
	int		sign;
	char	*n_address;

	ft_malloc_count_hexad(n, &sign, &malloc_count, base);
	n_address = malloc(sizeof(char) * malloc_count + 1);
	if (!n_address)
		return (NULL);
	n_address[malloc_count] = '\0';
	while (malloc_count > 0)
	{
		malloc_count--;
		if (n % base >= 10 && mod == 0)
			n_address[malloc_count] = 'a' + n % base - 10;
		else if (n % base >= 10 && mod == 1)
			n_address[malloc_count] = 'A' + n % base - 10;
		else
			n_address[malloc_count] = '0' + n % base;
		n = n / base;
	}
	if (sign == -1)
		n_address[0] = '-';
	return (n_address);
}

void	ft_malloc_count(long long n, int *sign, int *malloc_count, int base)
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
		n = n / base;
		if (n == 0)
			return ;
		*malloc_count = *malloc_count + 1;
	}
	return ;
}

char	*ft_itoa_base(long long n, int base, int mod)
{
	int		malloc_count;
	int		sign;
	char	*n_address;

	ft_malloc_count(n, &sign, &malloc_count, base);
	if (n < 0)
		n = n * (-1);
	n_address = malloc(sizeof(char) * malloc_count + 1);
	if (!n_address)
		return (NULL);
	n_address[malloc_count] = '\0';
	while (malloc_count > 0)
	{
		malloc_count--;
		if (n % base >= 10 && mod == 0)
			n_address[malloc_count] = 'a' + n % base - 10;
		else if (n % base >= 10 && mod == 1)
			n_address[malloc_count] = 'A' + n % base - 10;
		else
			n_address[malloc_count] = '0' + n % base;
		n = n / base;
	}
	if (sign == -1)
		n_address[0] = '-';
	return (n_address);
}
