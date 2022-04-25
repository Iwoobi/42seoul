/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:45:15 by youhan            #+#    #+#             */
/*   Updated: 2022/04/25 22:43:15 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}

void	ft_quicksort(int *arr, int L, int R)
{
	int	left;
	int	right;
	int	pivot;

	left = L;
	right = R;
	pivot = arr[(L + R) / 2];
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			ft_swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	if (L < right)
		ft_quicksort(arr, L, right);
	if (R > left)
		ft_quicksort(arr, left, R);
}

long long	ft_atoi(char *str)
{
	int			sign;
	long long	n;

	sign = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		n = n * 10 + *str++ - '0';
	return (n * sign);
}

int	ft_check_input_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (-1);
			j++;
		}
		if (j > 11)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_input_unique(int *arr, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

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
	return (-1);
}

t_list	*ft_make_stack(t_list **stack_n, int *arr, char **argv, int len)
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
		(*stack_n)->next = malloc(sizeof(t_list));
		if ((*stack_n)->next == NULL)
			return (NULL);
		(*stack_n)->val = ft_input_number_index(arr, argv, len, i);
		if ((*stack_n)->next == NULL)
			return (NULL);
		((*stack_n)->next)->before = (*stack_n);
		*stack_n = (*stack_n)->next;
		i++;
	}
	return (save_add);
}

void	ft_free_list(t_list **stack)
{
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	*stack = (*stack)->before;
	while ((*stack)->before == NULL)
	{
		free((*stack)->next);
		(*stack)->next = NULL;
		*stack = (*stack)->before;
	}
	free(*stack);
	*stack = NULL;
}

void	ft_printf_list(t_list *stack)
{
	while (stack->next != NULL)
	{
		printf("%d\n", stack->val);
		stack = stack->next;
	}
	printf("%d\n", stack->val);
}

int	main(int argc, char **argv)
{
	int	*sort_arr;

	if (argc < 3)
		return (-1);
	if (ft_input_number_push(argc, argv, &sort_arr) == -1)
		return (-1);
	ft_quicksort(sort_arr, 0, argc - 2);
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = (t_list *)malloc(sizeof(t_list));
	stack_b = (t_list *)malloc(sizeof(t_list)); 
	stack_a->next = NULL;
	stack_b->before = NULL;

	stack_a = ft_make_stack(&stack_a, sort_arr, argv, argc - 1);
	ft_printf_list(stack_a);
	ft_free_list(&stack_a);
}
