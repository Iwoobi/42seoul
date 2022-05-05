/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:45:15 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:56:40 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_free_list(t_list **stack)
{
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	*stack = (*stack)->before;
	while ((*stack)->before != NULL)
	{
		free((*stack)->next);
		(*stack)->next = NULL;
		*stack = (*stack)->before;
	}
	free(*stack);
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	int				*sort_arr;
	t_stack_list	*ps_stack;

	if (argc < 3)
		return (-1);
	if (ft_input_number_push(argc, argv, &sort_arr) == -1)
		return (-1);
	ft_quicksort(sort_arr, 0, argc - 2);
	ft_make_stack(&ps_stack, argc - 1);
	ps_stack->stack_a
		= ft_make_num_stack(&(ps_stack->stack_a), sort_arr, argv, argc - 1);
	ft_greedy_a_to_b(ps_stack);
}
