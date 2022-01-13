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
int	ft_flag_len(const char *str, int *printf_flag)
{
	int		i;
	int		flag_len;
	char    *fin_flag;

	flag_len = 0;
	fin_flag = "%cspdiuxX";
	
	while (*str)
	{
		i = 8;
		while(i >= 0)
		{
			if (*str == fin_flag[i])
			{
				printf_flag[i] = 1; 
				return (flag_len);
			}
			i--;
		}
		str++;
		flag_len++;
	}
	return (-1);
}
void	ft_arr_reset(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr[i] = 0;
		i++;
	}
}
/*
0 : c
1 : s
2 : p
3 : d
4 : i
5 : u
6 : x
7 : X
8 : %
9 : 0
10: -
11: +
12:' '
13: #
14: . 
*/
int ft_printf(const char *str, ...)
{
	va_list ap;
	int		printf_flag[15];

	va_start(ap, str);
	ft_arr_reset(printf_flag, 15);
	while (*str)
	{
		if (*str == '%')
		{
			printf("len : %d",ft_flag_len(str, printf_flag));
			int i = 0;
			while(i < 15)
			{
				printf("\nflag : %d", printf_flag[i]);
				i++;
			}
		}
		str++;
	}
	return 0;
}
int main()
{
	ft_printf("%++--d");
}