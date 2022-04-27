/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:58:31 by youhan            #+#    #+#             */
/*   Updated: 2022/04/28 07:24:23 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				val;
	int				use;
	struct s_list	*before;
	struct s_list	*next;
}	t_list;

typedef	struct m_list
{
	int		size_a;
	int		size_b;
	t_list	*stack_a;
	t_list	*head_a;
	t_list	*stack_b;
	t_list	*head_b;
}	t_stack_list;

#endif