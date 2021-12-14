/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:14:37 by youhan            #+#    #+#             */
/*   Updated: 2021/12/14 18:41:54 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (start >= i)
	{
		*str = '\0';
		return (str);
	}
	i = 0;
	while (i < len)
	{
		if (s[start + i] != '\0')
			str[i] = s[start + i];
		else
			str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
