/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:05:52 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 11:58:12 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_input_number_push(int argc, char **argv, int **sort_arr)
{
	int	i;

	if (ft_check_input_number(argc, argv) == -1)
		return (-1);
	*sort_arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!(*sort_arr))
		return (-1);
	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[1 + i]) > 2147483647)
			return (-1);
		if (ft_atoi(argv[i + 1]) < -2147483648)
			return (-1);
		(*sort_arr)[i] = (int)ft_atoi(argv[1 + i]);
		i++;
	}
	if (ft_input_unique(*sort_arr, argc) == -1)
		return (-1);
	return (1);
}

int	ft_input_number_index(int *arr, char **argv, int len, int i)
{
	int	j;

	j = 0;
	while (j < len)
	{
		if (arr[j] == ft_atoi(argv[1 + i]))
			return (1 + j);
		j++;
	}
	exit(1);
}

t_list	*ft_make_num_stack(t_list **stack_n, int *arr, char **argv, int len)
{
	int		i;
	t_list	*save_add;

	save_add = *stack_n;
	i = 0;
	while (i < len)
	{
		if (i == len - 1)
		{
			(*stack_n)->next = NULL;
			(*stack_n)->val = ft_input_number_index(arr, argv, len, i);
			return (save_add);
		}
		(*stack_n)->next = (t_list *)malloc(sizeof(t_list));
		if ((*stack_n)->next == NULL)
			exit(1);
		(*stack_n)->val = ft_input_number_index(arr, argv, len, i);
		((*stack_n)->next)->before = (*stack_n);
		*stack_n = (*stack_n)->next;
		i++;
	}
	return (save_add);
}

void	ft_make_stack(t_stack_list **stack, int size)
{
	*stack = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (!(*stack))
		exit(1);
	(*stack)->stack_a = (t_list *)malloc(sizeof(t_list));
	if (!((*stack)->stack_a))
		exit(1);
	((*stack)->stack_a)->next = NULL;
	((*stack)->stack_a)->before = NULL;
	(*stack)->size_a = size;
	(*stack)->size_b = 0;
	(*stack)->stack_b = NULL;
}
