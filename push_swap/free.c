/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:04:47 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 20:34:28 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_free_2(char ***argv)
{
	int	i;

	i = 1;
	while ((*argv)[i])
	{
		free((*argv)[i]);
		i++;
	}
	free((*argv));
}

int	ft_free(t_stack_list **stack, int **sort_arr, char ***argv)
{
	free(*sort_arr);
	free((*stack)->stack_b);
	if ((*stack)->size_a > 1)
	{
		while (((*stack)->stack_a)->next != NULL)
			(*stack)->stack_a = ((*stack)->stack_a)->next;
		(*stack)->stack_a = ((*stack)->stack_a)->before;
		while ((*stack)->size_a > 1)
		{
			(((*stack)->stack_a)->next)->before = NULL;
			free((((*stack)->stack_a)->next));
			(*stack)->size_a -= 1;
			if ((*stack)->size_a > 1)
			(*stack)->stack_a = ((*stack)->stack_a)->before;
		}
	}
	free((*stack)->stack_a);
	free((*stack));
	ft_free_2(argv);
	return (1);
}
