/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:36:06 by youhan            #+#    #+#             */
/*   Updated: 2022/03/25 15:36:27 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_strlen(char *str);
void	ft_malloc_count(long long n, int *sign, int *malloc_count, int base);
char	*ft_itoa_base(long long n, int base, int mod);
void	ft_printf_write(char *buf, int *count, int free_nece);
void	ft_printf_flag_print_2(int flag, va_list ap, int *i);
void	ft_printf_flag_print(int flag, va_list ap, int *i);
int		ft_flag_len(const char **str, va_list ap, int *i);
int		ft_printf(const char *str, ...);
char	*ft_itoa_base_hexad(unsigned long long n, int base, int mod);
void	ft_malloc_count_hexad(unsigned long long n, int *sign, int *malloc_count, int base);

#endif