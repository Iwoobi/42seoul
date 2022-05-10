/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:11:34 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 20:56:45 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		{
			free(command);
			return (-1);
		}
		free(command);
		command = get_next_line(0);
	}
	return (1);
}
