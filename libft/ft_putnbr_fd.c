/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:55:43 by youhan            #+#    #+#             */
/*   Updated: 2021/12/12 23:55:43 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_10_pow(int n_pow)
{
	int	a;

	a = 1;
	while (n_pow > 1)
	{
		a = a * 10;
		n_pow--;
	}
	return (a);
}

static int	ft_n_pow(int n)
{
	int	n_pow;

	n_pow = 1;
	while (n > 0)
	{
		n = n / 10;
		if (n == 0)
			return (n_pow);
		n_pow++;
	}
	return (n_pow);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	int		n_pow;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = n * (-1);
	}
	n_pow = ft_n_pow(n);
	if (sign == -1)
		ft_putchar_fd('-', fd);
	while (n_pow > 0)
	{
		ft_putchar_fd('0' + n / ft_10_pow(n_pow), fd);
		n = n % ft_10_pow(n_pow);
		n_pow--;
	}
	ft_putchar_fd('\n', fd);
}
