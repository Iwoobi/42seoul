/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:56:34 by youhan            #+#    #+#             */
/*   Updated: 2022/01/13 19:56:02 by youhan           ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen])
		strlen++;
	return (strlen);
}

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
void	ft_printf_flag_print(int flag, va_list ap)
{
	int	buf;
	if (flag == 0)
		write(1, "%", 1);
	else if (flag == 1)
		write(1, va_arg(ap, int *), 1);
	else if (flag == 2)
		write(1, va_arg(ap, char *), ft_strlen(ap));
	else if (flag == 3)
		return ;
}
int	ft_flag_len(const char **str, va_list ap)
{
	int		flag_len;
	char    *fin_flag; 

	flag_len = 0;
	fin_flag = "%cspdiuxX";
	(*str)++;
	while(flag_len <= 8)
	{
		if (**str == fin_flag[flag_len])
		{
			ft_printf_flag_print(flag_len, ap);
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
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if(ft_flag_len(&str, ap) == -1)
				return(-1);
		}
		else
		{
			write(1, str, 1);
			str++;
		}
	}
	return (0);
}

int	main(void)
{
	ft_printf("12%c", 'a');
}
