/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sign_a_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:54:38 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:48:38 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_pa_pb(t_stack_list *stack, int *count_a, int *count_b)
{
	if (*count_a > *count_b)
	{
		ft_rotate_n_loop(stack, *count_b, 0);
		ft_rotate_n_loop(stack, *count_a - *count_b, 1);
	}
	else
	{
		ft_rotate_n_loop(stack, *count_a, 0);
		ft_rotate_n_loop(stack, *count_b - *count_a, 2);
	}
}

void	ft_rotate_pa_mb(t_stack_list *stack, int *count_a, int *count_b)
{
	ft_rotate_n_loop(stack, *count_a, 1);
	ft_r_rotate_n_loop(stack, ft_abs_n(*count_b), 2);
}

void	ft_rotate_ma_pb(t_stack_list *stack, int *count_a, int *count_b)
{
	ft_rotate_n_loop(stack, *count_b, 2);
	ft_r_rotate_n_loop(stack, ft_abs_n(*count_a), 1);
}

void	ft_rotate_ma_mb(t_stack_list *stack, int *count_a, int *count_b)
{
	if (ft_abs_n(*count_a) > ft_abs_n(*count_b))
	{
		ft_r_rotate_n_loop(stack, ft_abs_n(*count_b), 0);
		ft_r_rotate_n_loop(stack, *count_b - *count_a, 1);
	}
	else
	{
		ft_r_rotate_n_loop(stack, ft_abs_n(*count_a), 0);
		ft_r_rotate_n_loop(stack, *count_a - *count_b, 2);
	}
}
