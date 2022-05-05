/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:53:01 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:45:16 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_n_loop(t_stack_list *stack, int loop, int mod)
{
	int	i;

	i = 0;
	while (i < loop)
	{
		ft_rotate_n(stack, mod);
		i++;
	}
}

void	ft_r_rotate_n_loop(t_stack_list *stack, int loop, int mod)
{
	int	i;

	i = 0;
	while (i < loop)
	{
		ft_r_rotate_n(stack, mod);
		i++;
	}
}
