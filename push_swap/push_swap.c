/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:45:15 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 20:57:16 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int				*sort_arr;
	t_stack_list	*ps_stack;

	ft_make_arg(&argc, &argv);
	if (ft_input_number_push(argc, argv, &sort_arr) == -1)
		ft_error_printf();
	ft_quicksort(sort_arr, 0, argc - 2);
	ft_make_stack(&ps_stack, argc - 1);
	ps_stack->stack_a
		= ft_make_num_stack(&(ps_stack->stack_a), sort_arr, argv, argc - 1);
	if (ft_input_sort(ps_stack->stack_a, ps_stack->size_a) == -1)
		exit(1);
	if (argc == 4 || argc == 6)
		ft_hard_code_sort(ps_stack);
	else
		ft_greedy_a_to_b(ps_stack);
	ft_free(&ps_stack, &sort_arr, &argv);
}
