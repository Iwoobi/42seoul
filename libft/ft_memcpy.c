/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:50:36 by youhan            #+#    #+#             */
/*   Updated: 2021/11/18 18:50:36 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
void	ft_memcpy(void *dest, const void *source, unsigned int num)
{
	char		*dest_point;
	const char	*source_point;

	dest_point = dest;
	source_point = source;
	while (num > 0)
	{
		dest_point[num - 1] = source_point[num - 1];
		num--;
	}
}
int main()
{
	char arr[10]="1234567";
	char arr1[10]="1234567";
	ft_memcpy(arr+1,arr,12);
	memcpy(arr1+1,arr1,12);
	printf("my:%s",arr);
	printf("or:%s",arr1);
}
