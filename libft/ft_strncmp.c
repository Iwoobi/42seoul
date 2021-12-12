/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:05:53 by youhan            #+#    #+#             */
/*   Updated: 2021/11/18 17:41:26 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i + 1 < n && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
