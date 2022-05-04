/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:45:15 by youhan            #+#    #+#             */
/*   Updated: 2022/05/04 21:08:23 by youhan           ###   ########.fr       */
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
		(*stack_n)->next = (t_list *)malloc(sizeof(t_list));
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

void	ft_stack_a_remain(t_list *stack_a, t_stack_list *stack)
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
	(stack->size_b)++;
	(stack->size_a)--;
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
	(stack->size_a)++;
	(stack->size_b)--;
}

void	ft_push_n(t_stack_list *stack, int mod)
{
	if (mod == 1)
	{
		write(1,"pa\n",3);
		ft_push_a(stack);
	}
	if (mod == 2)
	{
		ft_push_b(stack);
		write(1,"pb\n",3);
	}
}

void	ft_swap_a(t_stack_list *stack)
{
	int	tmp;
	
	if (stack->stack_a == NULL)
	{
		printf("error swap a\n");
		exit(0);
	}

	if ((stack->stack_a)->next == NULL)
	{
		printf("error swap a\n");
		exit(0);
	}
	tmp = (stack->stack_a)->val;
	(stack->stack_a)->val = ((stack->stack_a)->next)->val;
	((stack->stack_a)->next)->val = tmp;
}

void	ft_swap_b(t_stack_list *stack)
{
	int	tmp;
	
	if (stack->stack_b == NULL)
	{
		printf("error swap b\n");
		exit(0);
	}

	if ((stack->stack_b)->next == NULL)
	{
		printf("error swap b\n");
		exit(0);
	}
	tmp = (stack->stack_b)->val;
	(stack->stack_b)->val = ((stack->stack_b)->next)->val;
	((stack->stack_b)->next)->val = tmp;
}

void	ft_swap_n(t_stack_list *stack, int mod)
{
	if (mod == 0)
	{
		write(1,"ss\n",3);
		ft_swap_a(stack);
		ft_swap_b(stack);
	}
	else if (mod == 1)
	{
		ft_swap_a(stack);
		write(1,"sa\n",3);
	}
	else if (mod == 2)
	{
		ft_swap_b(stack);
		write(1,"sb\n",3);
	}
}

void	ft_rotate_a(t_stack_list *stack)
{
	t_list	*save;

	if (stack->stack_a == NULL)
	{
		printf("error rotate_a");
		exit(0);
	}
	if ((stack->stack_a)->next == NULL)
	{
		printf("error rotate_a next");
		exit(0);
	}
	save = stack->stack_a;
	((stack->stack_a)->next)->before = NULL;
	stack->stack_a = (stack->stack_a)->next;
	while ((stack->stack_a)->next != NULL)
		stack->stack_a = (stack->stack_a)->next;
	save->before = (stack->stack_a);
	save->next = NULL;
	(stack->stack_a)->next = save;
	while ((stack->stack_a)->before != NULL)
		stack->stack_a = (stack->stack_a)->before;
}

void	ft_rotate_b(t_stack_list *stack)
{
	t_list	*save;
	
	if (stack->stack_b == NULL)
	{
		printf("error rotate_b");
		exit(0);
	}
	if ((stack->stack_b)->next == NULL)
	{
		printf("error rotate_b next");
		exit(0);
	}
	save = stack->stack_b;
	((stack->stack_b)->next)->before = NULL;
	stack->stack_b = (stack->stack_b)->next;
	while ((stack->stack_b)->next != NULL)
		stack->stack_b = (stack->stack_b)->next;
	save->before = (stack->stack_b);
	save->next = NULL;
	(stack->stack_b)->next = save;
	while ((stack->stack_b)->before != NULL)
		stack->stack_b = (stack->stack_b)->before;
}

void	ft_rotate_n(t_stack_list *stack, int mod)
{
	if (mod == 0)
	{
		write(1,"rr\n",3);
		ft_rotate_a(stack);
		ft_rotate_b(stack);
	}
	if (mod == 1)
	{
		write(1,"ra\n",3);
		ft_rotate_a(stack);
	}
	if (mod == 2)
	{
		write(1,"rb\n",3);
		ft_rotate_b(stack);
	}
}

void	ft_r_rotate_a(t_stack_list *stack)
{
	t_list	*save;

	if (stack->stack_a == NULL)
	{
		printf("error rotate_a");
		exit(0);
	}
	if ((stack->stack_a)->next == NULL)
	{
		printf("error rotate_a next");
		exit(0);
	}

	save = stack->stack_a;
	while ((stack->stack_a)->next != NULL)
		stack->stack_a = (stack->stack_a)->next;
	((stack->stack_a)->before)->next = NULL;
	(stack->stack_a)->before = NULL;
	save->before = stack->stack_a;
	(stack->stack_a)->next = save;
}

void	ft_r_rotate_b(t_stack_list *stack)
{
	t_list *save;

	if (stack->stack_b == NULL)
	{
		printf("error rotate_b");
		exit(0);
	}
	if ((stack->stack_b)->next == NULL)
	{
		printf("error rotate_b next");
		exit(0);
	}
	save = stack->stack_b;
	while ((stack->stack_b)->next != NULL)
		stack->stack_b = (stack->stack_b)->next;
	((stack->stack_b)->before)->next = NULL;
	(stack->stack_b)->before = NULL;
	save->before = stack->stack_b;
	(stack->stack_b)->next = save;
}
int	ft_find_all_min_b(int a_val, t_stack_list stack)
{
	int	diff;
	int	i;
	int count_b;
	
	diff = 0;
	i = 0;
	while (stack.size_b > i)
	{
		if (diff < stack.stack_b->val - a_val)
		{
			diff = stack.stack_b->val - a_val;
			count_b = i;
		}
		i++;
		stack.stack_b = stack.stack_b->next;
	}
	if (count_b > stack.size_b / 2)
		return ((stack.size_b - count_b) * -1);
	else
		return (count_b);
}

int	ft_find_min_count_b(int a_val, t_stack_list stack)
{
	int	diff;
	int	i;
	int	count_b;
	t_stack_list save;

	save = stack;
	diff = stack.size_a + stack.size_b;
	i = 0;
	if (stack.stack_b == NULL)
		return (0);
	while (stack.size_b > i)
	{
		if (a_val - stack.stack_b->val > 0 && diff > a_val - stack.stack_b->val)
		{
			diff = a_val - stack.stack_b->val;
			count_b = i;
		}
		i++;
		stack.stack_b = stack.stack_b->next;
	}
	if (diff == stack.size_a + stack.size_b)
		return (ft_find_all_min_b(a_val, save));
	if (count_b > stack.size_b / 2)
		return ((stack.size_b - count_b) * -1);
	else
		return (count_b);
}
int	ft_abs_n(int a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}
int	ft_a_b_set_count(int a, int b)
{
	if (a * b < 0)
	{
		return (ft_abs_n(a) + ft_abs_n(b));
	}
	else
	{
		if (ft_abs_n(a) > ft_abs_n(b))
			return (ft_abs_n(a));
		return (ft_abs_n(b));
	}

}

int	ft_use_init_count(t_stack_list stack)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (stack.size_a > i)
	{
		if ((stack.stack_a)->use == 0)
			count++;
		i++;
		stack.stack_a = stack.stack_a->next;
	}
	return (count);

}

int	ft_use_init_val(t_stack_list stack, int n)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (stack.size_a > i)
	{
		if ((stack.stack_a)->use == 0)
		{
			if (count == n)
				return (stack.stack_a->val);
			count++;
		}
		i++;
		stack.stack_a = stack.stack_a->next;
	}
	return (-1);
}

int	ft_use_init_index(t_stack_list stack, int n)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (stack.size_a > i)
	{
		if ((stack.stack_a)->use == 0)
		{
			if (count == n)
				return (i);
			count++;
		}
		i++;
		stack.stack_a = stack.stack_a->next;
	}
	return (-1);
}

void	ft_find_min_count(t_stack_list stack, int *count_a, int *count_b)
{
	int	i;
	int	now_a;
	int	now_b;
	int	loop_n;

	i = 0;
	loop_n = ft_use_init_count(stack);
	printf("\n\nloop_n:%d\n\n", loop_n);
	while (loop_n > i)
	{
		if (i > stack.size_a / 2)
			now_a = (stack.size_a - i - ft_use_init_index(stack, i)) * -1;
		else
			now_a = i + ft_use_init_index(stack, i);
		printf("\nnow_a:%d\n\n",now_a);
		now_b = ft_find_min_count_b(ft_use_init_val(stack, i), stack);
		if (ft_a_b_set_count(now_b, now_b) < ft_a_b_set_count(*count_a, *count_b) || i == 0)
		{
			*count_a = now_a;
			*count_b = now_b;
		}
		stack.stack_a = stack.stack_a->next;
		i++;
	}
}

void	ft_r_rotate_n(t_stack_list *stack, int mod)
{
	if (mod == 0)
	{
		write(1,"rrr\n",4);
		ft_r_rotate_a(stack);
		ft_r_rotate_b(stack);
	}
	if (mod == 1)
	{
		ft_r_rotate_a(stack);
		write(1,"rra\n", 4);
	}
	if (mod == 2)
	{
		ft_r_rotate_b(stack);
		write(1,"rrb\n",4);
	}
}


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

void	ft_rotate_pa_pb(t_stack_list *stack, int *count_a, int *count_b)
{
	if (*count_a > *count_b)
	{
		ft_rotate_n_loop(stack, *count_b, 0);
		ft_rotate_n_loop(stack, *count_a - *count_b, 1);
	}
	else
	{
		ft_rotate_n_loop(stack, *count_a, 0);
		ft_rotate_n_loop(stack, *count_b - *count_a, 2);
	}
}

void	ft_rotate_pa_mb(t_stack_list *stack, int *count_a, int *count_b)
{
	ft_rotate_n_loop(stack, *count_a, 1);
	ft_r_rotate_n_loop(stack, ft_abs_n(*count_b), 2);
}

void	ft_rotate_ma_pb(t_stack_list *stack, int *count_a, int *count_b)
{
	ft_rotate_n_loop(stack, *count_b, 2);
	ft_r_rotate_n_loop(stack, ft_abs_n(*count_a), 1);
}

void	ft_rotate_ma_mb(t_stack_list *stack, int *count_a, int *count_b)
{
{
	if (ft_abs_n(*count_a) > ft_abs_n(*count_b))
	{
		ft_r_rotate_n_loop(stack, ft_abs_n(*count_b), 0);
		ft_r_rotate_n_loop(stack, *count_b - *count_a, 1);
	}
	else
	{
		ft_r_rotate_n_loop(stack, ft_abs_n(*count_a), 0);
		ft_r_rotate_n_loop(stack, *count_a - *count_b, 2);
	}
}
}

void	ft_a_b_rotate(t_stack_list *stack, int *count_a, int *count_b)
{
	if (*count_a > 0)
	{
		if (*count_b > 0)
			ft_rotate_pa_pb(stack, count_a, count_b);
		else
			ft_rotate_pa_mb(stack, count_a, count_b);
	}
	else
	{
		if (*count_b > 0)
			ft_rotate_ma_pb(stack, count_a, count_b);
		else
			ft_rotate_ma_mb(stack, count_a, count_b);
	}
}

int	ft_sort_b(t_stack_list stack)
{
	int	i;

	i = 0;
	while (stack.size_b > i)
	{
		if ((stack.stack_b)->val == stack.size_b)
		{
			if (i > (stack.size_b) / 2)
				return (((stack.size_b) - i) * -1);
			else
				return (i);
		}
		stack.stack_b = (stack.stack_b)->next;
		i++;
	}
	return (i);
}

void	ft_greedy_a_to_b(t_stack_list *stack)
{
	int	count_a;
	int	count_b;
	
	printf("\n\ninit :%d\n\n",ft_use_init_count(*stack));
	while (ft_use_init_count(*stack))
	{
		count_a = 0;
		count_b = 0;
		ft_find_min_count(*stack, &count_a, &count_b);
		ft_a_b_rotate(stack, &count_a, &count_b);
		ft_push_n(stack, 2);
	}
	// if (ft_sort_b(*stack) > 0)
	// 	ft_rotate_n_loop(stack, ft_sort_b(*stack), 2);
	// else
	// 	ft_r_rotate_n_loop(stack, ft_abs_n(ft_sort_b(*stack)), 2);
	// while (stack->size_b)
	// 	ft_push_n(stack, 1);
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


	
	ft_stack_a_remain(ps_stack->stack_a, ps_stack);
	ft_printf_use(ps_stack->stack_a);
	// ft_push_n(ps_stack, 2);
	// ft_push_n(ps_stack, 2);
	// ft_push_n(ps_stack, 2);
	// // ft_push_n(ps_stack, 2);
	printf("start\n");
	ft_printf_list(ps_stack->stack_a);
	
	printf("\n\nb\n");
	ft_printf_list(ps_stack->stack_b);

	ft_greedy_a_to_b(ps_stack);
	
	printf("\n\n\ntest\n");
	printf("a\n");
	ft_printf_list(ps_stack->stack_a);
	printf("\n\nb\n\n");
	ft_printf_list(ps_stack->stack_b);
}
