/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:25:23 by youhan            #+#    #+#             */
/*   Updated: 2021/12/08 19:53:41 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	str = malloc((i + j) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	k = 0;
	while (k < i + j)
	{
		if (k < i)
			str[k] = s1[k];
		if (k < j)
			str[k + i] = s2[k];
		k++;
	}
	str[i + j] = '\0';
	return (str);
}
