#include <stdio.h>
#include <stdlib.h>
int	ft_atoi(const char *str)
{
	int	sign;
	int	n;

	n = 0;
	sign = 1;
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

void ft_dfs(int a, int b, int **sol, int **result, int *fin)
{
	int i;

	i = 0;
	if (a == b)
	{
		*fin = 0;
		while (i < a)
		{
			if (i == a - 1)
				printf("%d\n", (*sol)[i]);
			else
				printf("%d ", (*sol)[i]);
			i++;
		}
		free(*sol);
		free(*result);
	}
	while (*fin)
	{
		(*sol)[a] = i;
		i++;
		if ((*sol)[a] == (*result)[a])
		{
			a++;
			ft_dfs(a,b, sol, result, fin);
		}
	}
}


int ft_sol(int a, char **b)
{
	int *sol;
	int *result;
	int i;
	int fin;

	fin = 1;
	i = 0;
	sol = (int *)malloc(sizeof(int) * a);
	result = (int *)malloc(sizeof(int) * a);
	if(sol == NULL || result == NULL)
		return (-1);
	while (i < a)
	{
		result[i] = ft_atoi(b[i+1]);
		i++;
	}
	ft_dfs(0, a, &sol, &result, &fin);
	return (1);
}

int main(int a, char **b)
{
	if (a == 1)
		return(-1);
	if (ft_sol(a - 1,b) == -1)
	{
		printf("error");
	}
}