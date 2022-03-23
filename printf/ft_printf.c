/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:56:34 by youhan            #+#    #+#             */
/*   Updated: 2022/03/23 18:59:52 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/*
0 : % %기호 출력
1 : c 하나의 문자
2 : s 문자열
3 : p void 16진수
4 : d 10진수 숫자
5 : i 10진수 정수
6 : u 10진수 정수
7 : x 소문자 사용 16진수
8 : X 대문자 사용 16진수

*/
int	ft_atoi(const char *str)
{
	int	sign;
	int	n;

	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		n = n * 10 + *str++ - '0';
	return (n * sign);
}

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen])
		strlen++;
	return (strlen);
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

char	*ft_itoa_base(long n, int base, int mod)
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
	while (malloc_count >= 0)
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

void	ft_printf_flag_print_2(int flag, va_list ap, int *i)
{
	char	*char_buf;

	char_buf = ft_itoa_base(va_arg(ap, int), 10, 0);
	if (flag == 4)
		write(1, char_buf, ft_strlen(char_buf));
	else if (flag == 5)
		write(1, char_buf, ft_strlen(char_buf));
	else if (flag == 6)
		write(1, char_buf, ft_strlen(char_buf));
	else if (flag == 7)
	{
		char_buf = ft_itoa_base(va_arg(ap, int), 16, 0);
		write(1, char_buf, ft_strlen(char_buf));
	}
	else if (flag == 8)
	{
		char_buf = ft_itoa_base(va_arg(ap, int), 16, 1);
		write(1, char_buf, ft_strlen(char_buf));
	}
	*i = *i + ft_strlen(char_buf);
}

void	ft_printf_flag_print(int flag, va_list ap, int *i)
{
	char	buf;
	long	long_buf;
	char	*char_buf;

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
	{
		char_buf = va_arg(ap, char *);
		write(1, char_buf, ft_strlen(char_buf));
		*i = *i + ft_strlen(char_buf);
	}
	else if (flag == 3)
	{
		long_buf = va_arg(ap, long);
		char_buf = ft_itoa_base(long_buf, 16, 0);
		write(1, "0x", 2);
		write(1, char_buf, ft_strlen(char_buf));
		*i = *i + 2 + ft_strlen(char_buf);
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
	int		printf_flag[9];
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
	return (i);
}
int main()
{
	ft_printf("%s", NULL);
}