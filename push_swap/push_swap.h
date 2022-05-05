/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:58:31 by youhan            #+#    #+#             */
/*   Updated: 2022/05/05 21:54:36 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_list
{
	int				val;
	struct s_list	*before;
	struct s_list	*next;
}	t_list;

typedef struct s_list_big
{
	int		size_a;
	int		size_b;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack_list;

void		ft_swap(int *a, int *b);
void		ft_quicksort(int *arr, int L, int R);
long long	ft_atoi(char *str);
int			ft_check_input_number(int argc, char **argv);
int			ft_input_unique(int *arr, int argc);
int			ft_input_number_push(int argc, char **argv, int **sort_arr);
int			ft_input_number_index(int *arr, char **argv, int len, int i);
t_list		*ft_make_num_stack(t_list **stack_n, int *arr, char **argv,
				int len);
void		ft_free_list(t_list **stack);
void		ft_make_stack(t_stack_list **stack, int size);
void		ft_push_b(t_stack_list *stack);
void		ft_push_a(t_stack_list *stack);
void		ft_push_n(t_stack_list *stack, int mod);
void		ft_swap_a(t_stack_list *stack);
void		ft_swap_b(t_stack_list *stack);
void		ft_swap_n(t_stack_list *stack, int mod);
void		ft_rotate_a(t_stack_list *stack);
void		ft_rotate_b(t_stack_list *stack);
void		ft_rotate_n(t_stack_list *stack, int mod);
void		ft_r_rotate_a(t_stack_list *stack);
void		ft_r_rotate_b(t_stack_list *stack);
int			ft_find_all_min_b(int a_val, t_stack_list stack);
void		ft_find_min_count_b_while(int a_val, t_stack_list stack,
				int *count_b, int *diff);
int			ft_find_min_count_b(int a_val, t_stack_list stack);
int			ft_abs_n(int a);
int			ft_a_b_set_count(int a, int b);
void		ft_find_min_count(t_stack_list stack, int *count_a, int *count_b);
void		ft_r_rotate_n(t_stack_list *stack, int mod);
void		ft_rotate_n_loop(t_stack_list *stack, int loop, int mod);
void		ft_r_rotate_n_loop(t_stack_list *stack, int loop, int mod);
void		ft_rotate_pa_pb(t_stack_list *stack, int *count_a, int *count_b);
void		ft_rotate_pa_mb(t_stack_list *stack, int *count_a, int *count_b);
void		ft_rotate_ma_pb(t_stack_list *stack, int *count_a, int *count_b);
void		ft_rotate_ma_mb(t_stack_list *stack, int *count_a, int *count_b);
void		ft_a_b_rotate(t_stack_list *stack, int *count_a, int *count_b);
int			ft_sort_a(t_stack_list stack);
void		ft_rough_sort(t_stack_list *stack);
void		ft_greedy_a_to_b(t_stack_list *stack);

#endif