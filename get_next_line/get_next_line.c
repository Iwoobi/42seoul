/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:44:07 by youhan            #+#    #+#             */
/*   Updated: 2021/12/16 23:44:07 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
char	*get_next_line(int fd)
{
	static char	*str;
	char	buff[BUFF_SIZE];
	while (read(fd, buff, BUFF_SIZE) != 0)
	{
		while(*buff != '\n')
		{
			*str = *buff; 
			buff++;
			*str++;
		}
		if (buff == '\n')
			return (str);
	} 

}
int main(int a, char **b)
{
	int	fd;
	fd = open("asd.txt", O_RDONLY);
	while (1)
	{
		if (get_next_line(fd) == NULL)
			break;
	}
	close(fd);
}