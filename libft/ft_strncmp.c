/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:05:53 by youhan            #+#    #+#             */
/*   Updated: 2021/12/13 18:53:25 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i + 1 < n && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] != '\0')
		return (1);
	if (s1[i] != '\0' && s2[i] == '\0')
		return (1);
	return (s1[i] - s2[i]);
}
