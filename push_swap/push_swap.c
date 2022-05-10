/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:45:15 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 12:08:06 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = ft_strlen(*s1);
	j = ft_strlen(s2);
	str = malloc((i + j) * sizeof(char) + 2);
	if (!str)
		return (NULL);
	k = 0;
	while (k < i + j)
	{
		if (k < i)
			str[k] = (*s1)[k];
		if (k < j)
			str[k + i] = s2[k];
		k++;
	}
	str[i + j] = ' ';
	str[i + j + 1] = '\0';
	if ((*s1) != NULL)
		free(*s1);
	return (str);
}

void	ft_make_arg(int *argc, char ***argv)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = 0;
	while (i < *argc)
	{
		tmp = ft_strjoin(&tmp, (*argv)[i]);
		i++;
	}
	*argv = ft_split(tmp, ' ');
	free(tmp);
	i = 1;
	while ((*argv)[i])
		i++;
	*argc = i;
}

int	main(int argc, char **argv)
{
	int				*sort_arr;
	t_stack_list	*ps_stack;

	ft_make_arg(&argc, &argv);
	if (argc < 3)
		exit(1);
	if (ft_input_number_push(argc, argv, &sort_arr) == -1)
		exit(1);
	ft_quicksort(sort_arr, 0, argc - 2);
	ft_make_stack(&ps_stack, argc - 1);
	ps_stack->stack_a
		= ft_make_num_stack(&(ps_stack->stack_a), sort_arr, argv, argc - 1);
	if (ft_input_sort(ps_stack->stack_a, argc) == -1)
		exit(1);
	if (argc == 4 || argc == 6)
		ft_hard_code_sort(ps_stack);
	else
		ft_greedy_a_to_b(ps_stack);
	ft_free(&ps_stack, &sort_arr, &argv);

}