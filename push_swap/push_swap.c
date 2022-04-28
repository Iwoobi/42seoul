/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:45:15 by youhan            #+#    #+#             */
/*   Updated: 2022/04/28 07:45:21 by youhan           ###   ########.fr       */
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
			(*stack_n)->use = 0;
			return (save_add);
		}
		(*stack_n)->next = malloc(sizeof(t_list));
		if ((*stack_n)->next == NULL)
			exit(1);
		(*stack_n)->val = ft_input_number_index(arr, argv, len, i);
		(*stack_n)->use = 0;
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
	while ((*stack)->before != NULL)
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
	if (stack == NULL)
	{
		printf("NULL");
		return ;
	}
	while (stack->next != NULL)
	{
		printf("%d\n", stack->val);
		stack = stack->next;
	}
	printf("%d\n", stack->val);
}

void	ft_make_stack(t_stack_list **stack, int size)
{
	*stack = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (!(*stack))
		exit(1);
	(*stack)->stack_a = (t_list *)malloc(sizeof(t_list));
	if (!((*stack)->stack_a))
		exit(1);
	(*stack)->head_a = (*stack)->stack_a;
	((*stack)->stack_a)->next = NULL;
	((*stack)->stack_a)->before = NULL;
	(*stack)->size_a = size;
	(*stack)->size_b = 0;
	(*stack)->stack_b = NULL;
}

void	ft_stack_a_remain_max(t_list *stack_a, int *remain_size, int *remain_val, t_stack_list *stack)
{
	int		val_n;
	t_list	*save_list;
	int		size_i;

	val_n = 0;
	save_list = stack_a;
	size_i = 0;
	while (val_n == 0 || stack_a->val != save_list->val)
	{
		if(val_n < (stack_a->val))
		{
			size_i++;
			if (size_i > *remain_size)
			{
				*remain_size = size_i;
				*remain_val = save_list->val;
			}
			val_n = stack_a->val;
		}
		if (stack_a->next == NULL)
			stack_a = stack->head_a;
		else
			stack_a = stack_a->next;
	}
}

void	ft_stack_init_use(t_stack_list *stack, int val_pa)
{
	t_list	*list_add;
	int		a;

	a = 0;
	list_add = stack->stack_a; 
	while (list_add->val != val_pa)
		list_add = list_add->next;
	list_add->use = 1;
	while (list_add->val != val_pa || a == 0)
	{
		if (a < list_add->val)
		{
			list_add->use = 1;
			a = list_add->val;
		}
		if (list_add->next == NULL)
			list_add = stack->head_a;
		else
			list_add = list_add->next;
	}
}

void	ft_stack_use_init(t_list *stack_a, int val_pa, t_stack_list *stack)
{
	while (stack_a->next != NULL)
	{
		stack_a->use = 0;
		stack_a = stack_a->next;
	}
	stack_a->use = 0;
	ft_stack_init_use(stack, val_pa);
}

void	ft_stack_a_remain(t_list *stack_a, int size, t_stack_list *stack)
{
	int	remain_size;
	int	remain_val;

	remain_size = 0;
	remain_val = 0;
	while (remain_val == 0 || stack_a->val != (stack->head_a)->val)
	{
		if (stack_a->use == 0)
		{
			stack_a->use = 1;
			ft_stack_a_remain_max(stack_a, &remain_size, &remain_val, stack);
		}
		if (stack_a->next ==NULL)
			stack_a = stack->head_a;
		else
			stack_a = stack_a->next;
	}
	ft_stack_use_init(stack_a, remain_val, stack);
	
}

void	ft_push_b(t_stack_list *stack)
{
	t_list	*save_stack;
	
	save_stack = stack->stack_a;
	if ((stack->stack_a)->next != NULL)
		((stack->stack_a)->next)->before = NULL;
	stack->stack_a = (stack->stack_a)->next;
	save_stack->next = stack->stack_b;
	if (stack->stack_b != NULL)
		(save_stack->next)->before = save_stack;
	stack->stack_b = save_stack;
}

void	ft_push_a(t_stack_list *stack)
{
	t_list	*save_stack;

	save_stack = stack->stack_b;
	if ((stack->stack_b)->next != NULL)
		((stack->stack_b)->next)->before = NULL;
	stack->stack_b = (stack->stack_b)->next;
	save_stack->next = stack->stack_a;
	if (save_stack->next != NULL)
		(save_stack->next)->before = save_stack;
	stack->stack_a = save_stack;
}

void	ft_push_n(t_stack_list *stack, int a)
{
	if (a == 0)
		ft_push_a(stack);
	else
		ft_push_b(stack);
}

void	ft_printf_use(t_list *stack)
{
	while (stack->next != NULL)
	{
		printf("%d", stack->use);
		stack = stack->next;
	}
	printf("%d\n", stack->use);
}

int	main(int argc, char **argv)
{
	int	*sort_arr;
	t_stack_list	*ps_stack;

	if (argc < 3)
		return (-1);
	if (ft_input_number_push(argc, argv, &sort_arr) == -1)
		return (-1);
	ft_quicksort(sort_arr, 0, argc - 2);
	ft_make_stack(&ps_stack, argc - 1);
	ps_stack->stack_a = ft_make_num_stack(&(ps_stack->stack_a), sort_arr, argv, argc - 1);
	// ft_stack_a_remain(ps_stack->stack_a, argc - 1, ps_stack);
	// ft_printf_use(ps_stack->stack_a);
	printf("start\n");
	ft_printf_list(ps_stack->stack_a);
	printf("\npa\n");	
	printf("a\n\n");
	ft_printf_list(ps_stack->stack_a);
	printf("\n\nb\n\n");
	ft_printf_list(ps_stack->stack_b);
}
