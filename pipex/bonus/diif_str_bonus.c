/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diif_str_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:17:36 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 02:20:00 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	diff_str(char *s1, char *s2, int mod)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (-1);
	if (ft_strlen(s1) != ft_strlen(s2) + mod)
		return (-1);
	while (i < ft_strlen(s2) - mod)
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	if (mod == 1)
	{
		if (s1[ft_strlen(s2)] != '\n')
			return (-1);
	}
	return (1);
}
