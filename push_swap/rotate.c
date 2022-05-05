/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:01:41 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:49:11 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_rotate_a(t_stack_list *stack)
{
	t_list	*save;

	if (stack->stack_a == NULL)
		exit(0);
	if ((stack->stack_a)->next == NULL)
		exit(0);
	save = stack->stack_a;
	((stack->stack_a)->next)->before = NULL;
	stack->stack_a = (stack->stack_a)->next;
	while ((stack->stack_a)->next != NULL)
		stack->stack_a = (stack->stack_a)->next;
	save->before = (stack->stack_a);
	save->next = NULL;
	(stack->stack_a)->next = save;
	while ((stack->stack_a)->before != NULL)
		stack->stack_a = (stack->stack_a)->before;
}

void	ft_rotate_b(t_stack_list *stack)
{
	t_list	*save;

	if (stack->stack_b == NULL)
		exit(0);
	if ((stack->stack_b)->next == NULL)
		exit(0);
	save = stack->stack_b;
	((stack->stack_b)->next)->before = NULL;
	stack->stack_b = (stack->stack_b)->next;
	while ((stack->stack_b)->next != NULL)
		stack->stack_b = (stack->stack_b)->next;
	save->before = (stack->stack_b);
	save->next = NULL;
	(stack->stack_b)->next = save;
	while ((stack->stack_b)->before != NULL)
		stack->stack_b = (stack->stack_b)->before;
}

void	ft_rotate_n(t_stack_list *stack, int mod)
{
	if (mod == 0)
	{
		write(1, "rr\n", 3);
		ft_rotate_a(stack);
		ft_rotate_b(stack);
	}
	if (mod == 1)
	{
		write(1, "ra\n", 3);
		ft_rotate_a(stack);
	}
	if (mod == 2)
	{
		write(1, "rb\n", 3);
		ft_rotate_b(stack);
	}
}
