/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:06:00 by youhan            #+#    #+#             */
/*   Updated: 2021/11/18 17:37:50 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int a)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	while (i > 0)
	{
		if (*str == (char)a)
			return ((char *)str);
		str--;
		i--;
	}
	if (*str == (char)a)
		return ((char *)str);
	return ('\0');
}
