/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:24:05 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 10:38:07 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hard_code_sort_3(t_stack_list *stack)
{
	int	val[3];
	int	diff;

	val[0] = (stack->stack_a)->val;
	val[1] = ((stack->stack_a)->next)->val;
	val[2] = (((stack->stack_a)->next)->next)->val;
	ft_quicksort(val, 0, 2);
	diff = ((stack->stack_a)->next)->val - (stack->stack_a)->val;
	if (diff == val[1] - val[2] || diff == val[2] - val[0]
		|| diff == val[0] - val[1])
		ft_swap_n(stack, 1);
	if ((stack->stack_a)->val == val[1])
		ft_r_rotate_n(stack, 1);
	else if ((stack->stack_a)->val == val[2])
		ft_rotate_n(stack, 1);
}

void	ft_hard_code_sort_5(t_stack_list *stack)
{
	int	count_a;
	int	count_b;

	ft_push_n(stack, 2);
	ft_push_n(stack, 2);
	ft_hard_code_sort_3(stack);
	while (stack->size_b)
	{
		count_a = 0;
		count_b = 0;
		ft_find_min_count(*stack, &count_a, &count_b);
		ft_a_b_rotate(stack, &count_a, &count_b);
		ft_push_n(stack, 1);
	}
	if (ft_sort_a(*stack) > 0)
		ft_rotate_n_loop(stack, ft_sort_a(*stack), 1);
	else
		ft_r_rotate_n_loop(stack, ft_abs_n(ft_sort_a(*stack)), 1);
	while (stack->size_b)
		ft_push_n(stack, 1);
}

void	ft_hard_code_sort(t_stack_list *stack)
{
	if (stack->size_a == 3)
		ft_hard_code_sort_3(stack);
	else
		ft_hard_code_sort_5(stack);
}
