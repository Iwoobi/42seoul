/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:04:47 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:47:39 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_push_b(t_stack_list *stack)
{
	t_list	*save_stack;

	save_stack = stack->stack_a;
	if ((stack->stack_a)->next != NULL)
		((stack->stack_a)->next)->before = NULL;
	stack->stack_a = (stack->stack_a)->next;
	save_stack->next = stack->stack_b;
	if (stack->stack_b != NULL)
		(save_stack->next)->before = save_stack;
	stack->stack_b = save_stack;
	(stack->size_b)++;
	(stack->size_a)--;
}

void	ft_push_a(t_stack_list *stack)
{
	t_list	*save_stack;

	save_stack = stack->stack_b;
	if ((stack->stack_b)->next != NULL)
		((stack->stack_b)->next)->before = NULL;
	stack->stack_b = (stack->stack_b)->next;
	save_stack->next = stack->stack_a;
	if (save_stack->next != NULL)
		(save_stack->next)->before = save_stack;
	stack->stack_a = save_stack;
	(stack->size_a)++;
	(stack->size_b)--;
}

void	ft_push_n(t_stack_list *stack, int mod)
{
	if (mod == 1)
	{
		write(1, "pa\n", 3);
		ft_push_a(stack);
	}
	if (mod == 2)
	{
		ft_push_b(stack);
		write(1, "pb\n", 3);
	}
}
