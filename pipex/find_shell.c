/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:13:07 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:07:30 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_shell(char ***tmp, t_list *data)
{
	int	i;

	i = 0;
	while ((*tmp)[i])
		i++;
	i -= 1;
	data->shell = (*tmp)[i];
	if (i > 0)
		i -= 1;
	while (i >= 0)
	{
		free((*tmp)[i]);
		i--;
	}
	free(*tmp);
}

void	find_shell(char **env, t_list *data)
{
	int		i;
	int		local;
	char	**tmp;

	i = 0;
	local = -1;
	while (env[i] != NULL)
	{
		if (env[i][5] != '\0')
		{
			if (env[i][0] == 'S' && env[i][1] == 'H' && env[i][2] == 'E'
				&& env[i][3] == 'L' && env[i][4] == 'L' && env[i][5])
				local = i;
		}
		i++;
	}
	if (local == -1)
		error_code(1);
	tmp = ft_split(env[local], '/');
	if (tmp == NULL)
		error_code(2);
	input_shell(&tmp, data);
}
