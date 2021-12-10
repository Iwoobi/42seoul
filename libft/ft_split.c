/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:46:41 by youhan            #+#    #+#             */
/*   Updated: 2021/12/10 18:54:05 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
void	ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	a;
	
	a = 0;
	while (src[a] && a < n)
	{
//		printf("src%d:",a);
//		printf("%c\n",src[a]);
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return ;
}

int	set_check(char a, char *set)
{
	while (*set)
	{
		if (a == *set)
			return (0);
		set++;
	}
	return (1);
}

int	count_str(char *str, char *set, int q, int a)
{
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	while (*str)
	{
		if (set_check(*str, set))
		{
			if (a == 0)
				count[0] += 1;
			else
				count[1] += 1;
			a = 1;
		}
		else
		{
			if (q == 1 && a == 1)
				return (count[1]);
			a = 0;
		}
		str++;
	}
	if (q == 1 && *str == '\0' && a == 1)
		return (count[1]);
	return (count[0]);
}

char	*ft_skipstr(char *str, char *charset)
{
	while (*str)
	{
		if (set_check(*str, charset) == 0)
			str++;
		else
			return (str);
		
	}
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		a;
	int		b;
	int		c;

	b = -1;
	c = 0;
	a = count_str(str, charset, 0, 0);
	printf("malloc a:%d\n",a);
	arr = (char **)malloc(sizeof(char *) * a + 1);
	while (b++ < a)
	{
		str = ft_skipstr(str, charset);
		printf("str: %c\n",*str);
		c = count_str(str, charset, 1, 1);
		printf("mallo c:%d\n",c);
		arr[b] = (char *)malloc(sizeof(char) * c + 1);
//		printf("%c",*str);
//		printf("%d",c);

		ft_strncpy(arr[b], str, c);
		str = str + c ;
	}
	arr[b] = 0;
	return (arr);
}
int main()
{
	char a[100] = "123 123 1 12 3123 1";
	char c = ' ';
	char **b;
	b = ft_split(a,&c);
	while(*b != NULL)
	{
		printf("%s\n",*b);
		b++;
	}

}
