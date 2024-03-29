/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:45:28 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 20:51:54 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_check_input_number_2(char **argv, int i, int *j, int *check)
{
	if (!(argv[i][*j] >= '0' && argv[i][*j] <= '9'))
		ft_error_printf();
	else
		*check = 1;
	*j = *j + 1;
}

int	ft_check_input_number(int argc, char **argv)
{
	int	i;
	int	j;
	int	check;

	i = 1;
	check = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
			ft_check_input_number_2(argv, i, &j, &check);
		if (check == 0)
			return (-1);
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

int	ft_input_sort(t_list *stack, int size)
{
	int		top_val;
	int		i;

	top_val = stack->val;
	i = 0;
	while (i < size)
	{
		if (i == 0 || top_val + i == stack->val)
			stack = stack->next;
		else
			return (1);
		i++;
	}
	return (-1);
}
