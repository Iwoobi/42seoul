/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 05:13:53 by youhan            #+#    #+#             */
/*   Updated: 2021/12/19 05:13:53 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
void asd(int a)
{
	char	buff[BUFF_SIZE + 1];
	int i=read(a, buff, BUFF_SIZE);
	printf("%d",i);
}
int main(int a, char **b)
{
	int buff;

	printf("%d",atoi(b[1]));

}