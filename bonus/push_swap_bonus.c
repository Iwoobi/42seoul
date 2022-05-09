/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:09 by youhan            #+#    #+#             */
/*   Updated: 2022/05/09 21:20:30 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../push_swap.h"


int	ft_command_check_4(t_stack_list *stack, char *cmd)
{
	if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'a' && cmd[3] == '\n')
		ft_r_rotate_a(stack);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'b' && cmd[3] == '\n')
		ft_r_rotate_b(stack);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'r' && cmd[3] == '\n')
	{
		ft_r_rotate_a(stack);
		ft_r_rotate_b(stack);
	}
	else
		return (-1);
	return (1);
}

int	ft_command_check_3(t_stack_list *stack, char *cmd)
{
	if (cmd[0] == 'p' && cmd[1] == 'a' && cmd[2] == '\n')
		ft_push_a(stack);
	else if (cmd[0] == 'p' && cmd[1] == 'b' && cmd[2] == '\n')
		ft_push_b(stack);
	else if (cmd[0] == 's' && cmd[1] == 'a' && cmd[2] == '\n')
		ft_swap_a(stack);
	else if (cmd[0] == 's' && cmd[1] == 'b' && cmd[2] == '\n')
		ft_swap_b(stack);
	else if (cmd[0] == 's' && cmd[1] == 's' && cmd[2] == '\n')
	{
		ft_swap_a(stack);
		ft_swap_b(stack);
	}
	else if (cmd[0] == 'r' && cmd[1] == 'a' && cmd[2] == '\n')
		ft_rotate_a(stack);
	else if (cmd[0] == 'r' && cmd[1] == 'b' && cmd[2] == '\n')
		ft_rotate_b(stack);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == '\n')
	{
		ft_rotate_a(stack);
		ft_rotate_b(stack);
	}
	else
		return (-1);
	return (1);
}

int	ft_command_check(t_stack_list *stack, char *cmd)
{
	int	i;

	i = ft_strlen(cmd);
	if (i < 3 || i > 4)
		return (-1);
	if (i == 3)
	{
		if (ft_command_check_3(stack, cmd) == -1)
			return (-1);
	}
	if (i == 4)
	{
		if (ft_command_check_4(stack, cmd) == -1)
			return (-1);
	}
	return (1);
}

int	ft_checker(t_stack_list	*stack)
{
	char	*command;
	
	command = get_next_line(0);
	while (command != NULL)
	{
		if (ft_command_check(stack, command) == -1)
			return (-1);
		command = get_next_line(0);
	}
	return (1);
}

int	ft_error_printf(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int				*sort_arr;
	t_stack_list	*ps_stack;

	if (argc < 3)
		return (ft_error_printf());
	if (ft_input_number_push(argc, argv, &sort_arr) == -1)
		return (-1);
	ft_quicksort(sort_arr, 0, argc - 2);
	ft_make_stack(&ps_stack, argc - 1);
	ps_stack->stack_a
		= ft_make_num_stack(&(ps_stack->stack_a), sort_arr, argv, argc - 1);
	if (ft_input_sort(ps_stack->stack_a, argc) == -1)
		ft_error_printf();
	if (ft_checker(ps_stack) == -1)
		ft_error_printf();
	if (ft_input_sort(ps_stack->stack_a, argc) == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}