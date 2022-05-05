/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:57:27 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:43:49 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_find_all_min_b(int a_val, t_stack_list stack)
{
	int	diff;
	int	i;
	int	count_b;

	diff = 0;
	i = 0;
	while (stack.size_a > i)
	{
		if (diff > stack.stack_a->val - a_val)
		{
			diff = stack.stack_a->val - a_val;
			count_b = i;
		}
		i++;
		stack.stack_a = stack.stack_a->next;
	}
	if (count_b > stack.size_a / 2)
		return ((stack.size_a - count_b) * -1);
	else
		return (count_b);
}

int	ft_find_min_count_b(int a_val, t_stack_list stack)
{
	int				diff;
	int				count_b;
	t_stack_list	save;

	save = stack;
	diff = stack.size_a + stack.size_b;
	if (stack.stack_a == NULL)
		return (0);
	ft_find_min_count_b_while(a_val, stack, &count_b, &diff);
	if (diff == stack.size_a + stack.size_b)
		return (ft_find_all_min_b(a_val, save));
	if (count_b > stack.size_a / 2)
		return ((stack.size_a - count_b) * -1);
	else
		return (count_b);
}

int	ft_a_b_set_count(int a, int b)
{
	if (a * b < 0)
	{
		return (ft_abs_n(a) + ft_abs_n(b));
	}
	else
	{
		if (ft_abs_n(a) > ft_abs_n(b))
			return (ft_abs_n(a));
		return (ft_abs_n(b));
	}
}

void	ft_find_min_count(t_stack_list stack, int *count_a, int *count_b)
{
	int	i;
	int	now_a;
	int	now_b;

	i = 0;
	while (stack.size_b > i)
	{
		if (i > stack.size_b / 2)
			now_b = (stack.size_b - i) * -1;
		else
			now_b = i;
		now_a = ft_find_min_count_b(stack.stack_b->val, stack);
		if (ft_a_b_set_count(now_a, now_b)
			< ft_a_b_set_count(*count_a, *count_b) || i == 0)
		{
			*count_a = now_a;
			*count_b = now_b;
		}
		stack.stack_b = stack.stack_b->next;
		i++;
	}
}

void	ft_greedy_a_to_b(t_stack_list *stack)
{
	int	count_a;
	int	count_b;

	ft_rough_sort(stack);
	while (stack->size_a != 0)
		ft_push_n(stack, 2);
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
