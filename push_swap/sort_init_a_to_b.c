/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:55:45 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:50:24 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rough_sort_a_to_b_2(t_stack_list *stack, int *save_top)
{
	if (*save_top == 0)
		*save_top = (stack->stack_a)->val;
	if (stack->size_a >= 2)
		ft_rotate_n(stack, 1);
}

void	ft_rough_sort_a_to_b(t_stack_list *stack, int pivot_low, int *save_top)
{
	int	a_val;

	a_val = (stack->stack_a)->val;
	if (a_val <= 2 * pivot_low)
	{
		ft_push_n(stack, 2);
		if (a_val < pivot_low)
		{
			if ((stack->stack_a)->val > 2 * pivot_low
				&& *save_top != (stack->stack_a)->val)
			{
				if (*save_top == 0)
					*save_top = (stack->stack_a)->val;
				if (stack->size_b >= 2 && stack->size_a >= 2)
					ft_rotate_n(stack, 0);
			}
			if (stack->size_b >= 2)
				ft_rotate_n(stack, 2);
		}
	}
	else
		ft_rough_sort_a_to_b_2(stack, save_top);
}

void	ft_rough_sort(t_stack_list *stack)
{
	int	pivot_low;
	int	save_top;

	pivot_low = ((stack->size_a) / 3);
	save_top = 0;
	if (stack->size_a <= 3)
		return ;
	while (stack->size_a >= pivot_low && (stack->stack_a)->val != save_top)
	{
		ft_rough_sort_a_to_b(stack, pivot_low, &save_top);
	}
}
