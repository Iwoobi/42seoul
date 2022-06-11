/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_local.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:12:24 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 03:07:57 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_cmd_local(char **env, t_list *data)
{
	int	i;
	int	local;

	i = 0;
	local = -1;
	while (env[i] != NULL)
	{
		if (env[i][4] != '\0')
		{
			if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
				&& env[i][3] == 'H' && env[i][4] == '=')
				local = i;
		}
		i++;
	}
	if (local == -1)
		error_code(1);
	data->path = ft_split(&(env[local][5]), ':');
	if (data->path == NULL)
		error_code(2);
}
