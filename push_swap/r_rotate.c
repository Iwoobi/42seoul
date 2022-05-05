/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:02:25 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:48:26 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_r_rotate_a(t_stack_list *stack)
{
	t_list	*save;

	if (stack->stack_a == NULL)
		exit(0);
	if ((stack->stack_a)->next == NULL)
		exit(0);
	save = stack->stack_a;
	while ((stack->stack_a)->next != NULL)
		stack->stack_a = (stack->stack_a)->next;
	((stack->stack_a)->before)->next = NULL;
	(stack->stack_a)->before = NULL;
	save->before = stack->stack_a;
	(stack->stack_a)->next = save;
}

void	ft_r_rotate_b(t_stack_list *stack)
{
	t_list	*save;

	if (stack->stack_b == NULL)
		exit(0);
	if ((stack->stack_b)->next == NULL)
		exit(0);
	save = stack->stack_b;
	while ((stack->stack_b)->next != NULL)
		stack->stack_b = (stack->stack_b)->next;
	((stack->stack_b)->before)->next = NULL;
	(stack->stack_b)->before = NULL;
	save->before = stack->stack_b;
	(stack->stack_b)->next = save;
}

void	ft_r_rotate_n(t_stack_list *stack, int mod)
{
	if (mod == 0)
	{
		write(1, "rrr\n", 4);
		ft_r_rotate_a(stack);
		ft_r_rotate_b(stack);
	}
	if (mod == 1)
	{
		ft_r_rotate_a(stack);
		write(1, "rra\n", 4);
	}
	if (mod == 2)
	{
		ft_r_rotate_b(stack);
		write(1, "rrb\n", 4);
	}
}
