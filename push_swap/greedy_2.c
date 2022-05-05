/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:20:02 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:44:32 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_min_count_b_while(int a_val,
	t_stack_list stack, int *count_b, int *diff)
{
	int	i;

	i = 0;
	while (stack.size_a > i)
	{
		if (a_val - stack.stack_a->val < 0
			&& *diff > stack.stack_a->val - a_val)
		{
			*diff = stack.stack_a->val - a_val;
			*count_b = i;
		}
		i++;
		stack.stack_a = stack.stack_a->next;
	}
}

void	ft_a_b_rotate(t_stack_list *stack, int *count_a, int *count_b)
{
	if (*count_a > 0)
	{
		if (*count_b > 0)
			ft_rotate_pa_pb(stack, count_a, count_b);
		else
			ft_rotate_pa_mb(stack, count_a, count_b);
	}
	else
	{
		if (*count_b > 0)
			ft_rotate_ma_pb(stack, count_a, count_b);
		else
			ft_rotate_ma_mb(stack, count_a, count_b);
	}
}

int	ft_sort_a(t_stack_list stack)
{
	int	i;

	i = 0;
	while (stack.size_a > i)
	{
		if ((stack.stack_a)->val == 1)
		{
			if (i > (stack.size_a) / 2)
				return (((stack.size_a) - i) * -1);
			else
				return (i);
		}
		stack.stack_a = (stack.stack_a)->next;
		i++;
	}
	return (i);
}
