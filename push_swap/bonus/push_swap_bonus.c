/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:09 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 21:39:40 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_init(t_stack_list *stack)
{
	int	i;

	i = 0;
	while (stack->size_b)
		ft_push_a(stack);
}

int	main(int argc, char **argv)
{
	int				*sort_arr;
	t_stack_list	*ps_stack;

	if (argc == 1)
		return (1);
	ft_make_arg(&argc, &argv);
	if (ft_input_number_push(argc, argv, &sort_arr) == -1)
		ft_error_printf();
	ft_quicksort(sort_arr, 0, argc - 2);
	ft_make_stack(&ps_stack, argc - 1);
	ps_stack->stack_a
		= ft_make_num_stack(&(ps_stack->stack_a), sort_arr, argv, argc - 1);
	if (ft_checker(ps_stack) == -1)
		ft_error_printf();
	if (ft_input_sort(ps_stack->stack_a, ps_stack->size_a) == -1
		&& ps_stack->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_init(ps_stack);
	ft_free(&ps_stack, &sort_arr, &argv);
}
