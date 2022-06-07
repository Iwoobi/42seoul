/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diif_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:39:43 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:10:15 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
