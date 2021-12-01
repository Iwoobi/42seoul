/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:05:43 by youhan            #+#    #+#             */
/*   Updated: 2021/12/01 17:53:14 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int a)
{
	while (*str != '\0')
	{
		if (*str == (char)a)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
