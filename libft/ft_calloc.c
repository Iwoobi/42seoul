/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:17:21 by youhan            #+#    #+#             */
/*   Updated: 2021/12/10 18:20:29 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	unsigned char	*mem_savepoint;
	size_t			size_num;
	size_t			count_num;

	mem = (unsigned char *)malloc(count * size);
	if (mem == NULL)
	{
		return (NULL);
	}
	mem_savepoint = mem;
	count_num = 0;
	while (count_num < count)
	{
		size_num = 0;
		while (size_num < size)
		{
			*mem = 0;
			mem++;
			size_num++;
		}
		count_num++;
	}
	return (mem_savepoint);
}

//int main()
//{
//	char *a;
//
//	a= ft_calloc(0,0);
//	for (int i = 0; i < 1024; i++)
//	{
//		a[i] = 'a';
//	}
//	printf("%s\n", a);
//}

int	main(void)
{
	char	nums[10];

	nums[10] = 'a';
	printf("%d\n", nums[10]);
	return (0);
}
