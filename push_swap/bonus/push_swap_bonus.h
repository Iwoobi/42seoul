/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:10:13 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 19:23:20 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line.h"
# include "../push_swap.h"

int	ft_command_check_4(t_stack_list *stack, char *cmd);
int	ft_command_check_3(t_stack_list *stack, char *cmd);
int	ft_command_check(t_stack_list *stack, char *cmd);
int	ft_checker(t_stack_list	*stack);

#endif