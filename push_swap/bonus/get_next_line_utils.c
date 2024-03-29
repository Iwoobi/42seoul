/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:53:55 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 14:34:47 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../push_swap.h"

void	ft_join(char **str, char *back, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (back == NULL)
	{
		(*str)[0] = '\0';
		return ;
	}	
	if (flag == 1)
	{
		while ((*str)[i] != '\0')
			i++;
	}
	while (back[j] != '\0')
	{
		(*str)[i + j] = back[j];
		j++;
	}
	(*str)[i + j] = '\0';
}
