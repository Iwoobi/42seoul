/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:03:44 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:51:05 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_swap_a(t_stack_list *stack)
{
	int	tmp;

	if (stack->stack_a == NULL)
		exit(0);
	if ((stack->stack_a)->next == NULL)
		exit(0);
	tmp = (stack->stack_a)->val;
	(stack->stack_a)->val = ((stack->stack_a)->next)->val;
	((stack->stack_a)->next)->val = tmp;
}

void	ft_swap_b(t_stack_list *stack)
{
	int	tmp;

	if (stack->stack_b == NULL)
		exit(0);
	if ((stack->stack_b)->next == NULL)
		exit(0);
	tmp = (stack->stack_b)->val;
	(stack->stack_b)->val = ((stack->stack_b)->next)->val;
	((stack->stack_b)->next)->val = tmp;
}

void	ft_swap_n(t_stack_list *stack, int mod)
{
	if (mod == 0)
	{
		write(1, "ss\n", 3);
		ft_swap_a(stack);
		ft_swap_b(stack);
	}
	else if (mod == 1)
	{
		ft_swap_a(stack);
		write(1, "sa\n", 3);
	}
	else if (mod == 2)
	{
		ft_swap_b(stack);
		write(1, "sb\n", 3);
	}
}
