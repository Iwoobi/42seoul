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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_join(char **str, char *back, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (flag != 0)
	{
		while ((*str)[i] != '\0')
			i++;
	}
	while (back[j] != '\0')
	{
		(*str)[i + j] = back[j];
		j++;
	}
	(*str)[i + j] = '\0';
}

int	ft_move_str(char **str, int a)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(&((*str)[a])) + 1);
	if (!tmp)
		return (-1);
	while ((*str)[a + i] != '\0')
	{
		tmp[i] = (*str)[a + i];
		i++;
	}
	tmp[i] = '\0';
	free((*str));
	(*str) = malloc(sizeof(char) * i + 1);
	if (!(*str))
		return (-1);
	ft_join(str, tmp, 0);
	free(tmp);
	return (1);
}

char	*ft_str_return(char **str, int *k)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	*k = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
		{
			j = i;
			tmp = malloc(sizeof(char) * i + 1);
			if (!tmp)
				return (NULL);
			tmp[i] = '\0';
			while (i-- > 0)
				tmp[i] = (*str)[i];
			if (ft_move_str(str, j + 1) == -1)
				return (NULL);
			return (tmp);
		}
		i++;
	}
	*k = -2;
	return (NULL);
}

int	ft_read(int fd, char **str, char *buff, int size)
{
	int		i;
	char	*tmp;

	i = read(fd, buff, size);
	if (i == 0)
		return (-1);
	buff[i] = '\0';
	if (*str == NULL)
	{
		*str = malloc(sizeof(char) * i + 1);
		if (!(*str))
			return (-2);
		ft_join(str, buff, 0);
		return (i);
	}
	tmp = malloc(sizeof(char) * ft_strlen(*str) + 1);
	if (!tmp)
		return (-2);
	ft_join(&tmp,*str, 0);
	free(*str);
	*str = malloc(sizeof(char) * i + ft_strlen(tmp));
	if (!tmp)
		return (-2);
	ft_join(str, tmp, 0);
	ft_join(str, buff, 1);
	free(tmp);
	return (i);
}

char	*get_next_line(int fd)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str_backup;
	char		*str_return;
	int			i[2];

	i[0] = 0;
	if (str_backup == NULL)
		i[1] = ft_read(fd, &str_backup, buff, BUFF_SIZE);
	while (1)
	{
		str_return = ft_str_return(&str_backup, &i[0]);
		if (str_return != NULL)
			return (str_return);
		if (i[0] != -2)
			return (NULL);
		if (i[0] == -2)
			i[1] = ft_read(fd, &str_backup, buff, BUFF_SIZE);
		if (i[1] == -2)
			return (NULL);
		if (i[1] == -1)
			return (str_backup);

	}

}
int main(int a, char **b)
{
	int	fd;
	int BUFF;
	BUFF = atoi(b[1]);

	fd = open("asd.txt", O_RDONLY);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	printf("==%s\n",get_next_line(fd));
	printf("==%s\n",get_next_line(fd));
	printf("==%s\n",get_next_line(fd));
	printf("==%s\n",get_next_line(fd));
	printf("==%s\n",get_next_line(fd));
	close(fd);
}