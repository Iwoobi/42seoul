/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:53:59 by youhan            #+#    #+#             */
/*   Updated: 2021/12/08 20:33:17 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_check_set(char const s1, char const *set)
{
	while (*set != '\0')
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}
static void	ft_point(int *k, int *j, char const *s1, char const *set)
{
	int	i;
	int	a;

	a = 1;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_check_set(s1[i],set) && a == 1)
			*k = i;
		else
			a = 0;
		i++;
	}
	a = 1;
	while (i > 0 && *k < i)
	{
		
		if (ft_check_set(s1[i - 1], set) && a == 1)
		{
			printf(":%d\n",i);
			*j = i;
		}
		else
			a = 0;
		i--;
	}
}
char	*ft_strtrim(char const *s1, char const *set)
{
	int	k;
	int j;

	k = 1;
	j = 1;
	ft_point(&k, &j, s1, set);
	printf("%d, %d", k, j);
	return (NULL);
}
int main()
{
	char a[100]="1111111111";
	char b[100]= "123";
	ft_strtrim(a,b);
}