/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:56:34 by youhan            #+#    #+#             */
/*   Updated: 2022/03/24 21:57:45 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_write(char *buf, int *count, int free_nece)
{
	if (buf == NULL)
	{
		write(1, "(null)", 6);
		*count = *count + 6;
		return ;
	}
	write(1, buf, ft_strlen(buf));
	*count = *count + ft_strlen(buf);
	if (buf != NULL && free_nece == 0)
		free(buf);
}

/*
0:%
1:c
2:s
3:p
4:d
5:i
6:u
7:x
8:X
*/

void	ft_printf_flag_print_2(int flag, va_list ap, int *i)
{
	if (flag == 4)
		ft_printf_write(ft_itoa_base(va_arg(ap, int), 10, 0), i, 0);
	else if (flag == 5)
		ft_printf_write(ft_itoa_base(va_arg(ap, int), 10, 0), i, 0);
	else if (flag == 6)
		ft_printf_write(ft_itoa_base(va_arg(ap, unsigned int), 10, 0), i, 0);
	else if (flag == 7)
		ft_printf_write(ft_itoa_base_hexad(va_arg(ap, unsigned long long), 16, 0), i, 0);
	else if (flag == 8)
		ft_printf_write(ft_itoa_base_hexad(va_arg(ap, unsigned long long), 16, 1), i, 0);
}

void	ft_printf_flag_print(int flag, va_list ap, int *i)
{
	int	buf;

	if (flag == 0)
	{
		write(1, "%", 1);
		*i = *i + 1;
	}
	else if (flag == 1)
	{
		buf = va_arg(ap, int);
		write(1, &buf, 1);
		*i = *i + 1;
	}
	else if (flag == 2)
		ft_printf_write(va_arg(ap, char *), i, 1);
	else if (flag == 3)
	{
		write(1, "0x", 2);
		ft_printf_write(ft_itoa_base_hexad(va_arg(ap, long long), 16, 0), i, 0);
		*i = *i + 2;
	}
	else
		ft_printf_flag_print_2(flag, ap, i);
}

int	ft_flag_len(const char **str, va_list ap, int *i)
{
	int		flag_len;
	char	*fin_flag;

	flag_len = 0;
	fin_flag = "%cspdiuxX";
	(*str)++;
	while (flag_len <= 8)
	{
		if (**str == fin_flag[flag_len])
		{
			ft_printf_flag_print(flag_len, ap, i);
			(*str)++;
			return (flag_len);
		}
		flag_len++;
	}
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_flag_len(&str, ap, &i) == -1)
				return (-1);
		}
		else
		{
			write(1, str, 1);
			str++;
			i++;
		}
	}
	va_end(ap);
	return (i);
}
#include <stdio.h>
int main()
{
	printf("%lx\n",9223372036854775807LL);
	ft_printf("%x",9223372036854775807LL);
}