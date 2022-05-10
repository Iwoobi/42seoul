/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:04:47 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 12:05:25 by youhan           ###   ########.fr       */
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

void	ft_free(t_stack_list **stack, int **sort_arr, char ***argv)
{
	int	i;

	i = 0;
	free(*sort_arr);
	free((*stack)->stack_b);
	while ((*stack)->size_a - 2 > i)
	{
		i++;
		(*stack)->stack_a = ((*stack)->stack_a)->next;
	}
	while (i > -1)
	{
		i--;
		(((*stack)->stack_a)->next)->before = NULL;
		free((((*stack)->stack_a)->next));
		if (i != -1)
			(*stack)->stack_a = ((*stack)->stack_a)->before;
	}
	free((*stack)->stack_a);
	free((*stack));
	ft_free_2(argv);
}
