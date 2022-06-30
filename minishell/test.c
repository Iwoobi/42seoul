/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:42:19 by youhan            #+#    #+#             */
/*   Updated: 2022/06/30 17:02:05 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_str(char *str, char start)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == start)
			return (i);
		i++;	
	}
	return (-1);
}

int	count_str(char *str)
{
	int	i;
	int	len;
	int diff;

	i = 0;
	diff = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			if (skip_str(&str[i + 1], str[i]) == -1)
				return (-1);
			i += skip_str(&str[i + 1], str[i]) + 2;
			diff++;
		}
		else
		{
			i++;
		}
	}
	return (i - (2 * diff));
}

int	skip_push_str(char *str, char fin, t_cmd *cmd, int *start)
{
	int i;
	int	j;

	j = *start;
	i = 0;
	while (str[i])
	{
		if (str[i] == fin)
			return (i);
		cmd->cmd_mod[*start] = str[i];
		cmd->status[*start] = j;
		*start += 1;
		i++;
	}
	return (-1);
}

void	change_str(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd->cmd[i])
	{
		if (cmd->cmd[i] == '\"' || cmd->cmd[i] == '\'')
			i += skip_push_str(&cmd->cmd[i + 1], cmd->cmd[i], cmd, &j) + 2;
		else
		{
			cmd->cmd_mod[j] = cmd->cmd[i];
			cmd->status[j] = -1;
			i++;
			j++;
		}
	}
}

void	printf_data(t_cmd *cmd, int max)
{
	int	i;

	i = 0;
	printf("%s\n",cmd->cmd_mod);
	while (i < max)
	{
		printf("%d ",cmd->status[i]);
		i++;
	}
	printf("\n");
}

int	test(t_cmd *cmd)
{
	if (count_str(cmd->cmd) == -1)
		return (-1);
	cmd->cmd_mod = (char *)malloc(sizeof(char) * count_str(cmd->cmd) + 1);
	cmd->status = (int *)malloc(sizeof(int) * count_str(cmd->cmd));
	if (cmd->cmd_mod == NULL || cmd->status == NULL)
		exit(-1);
	cmd->cmd_mod[count_str(cmd->cmd)] = 0;
	change_str(cmd);
	printf_data(cmd, count_str(cmd->cmd));
	return (1);
}

int main()
{
	t_cmd	cmd;
	while (1)
	{
		cmd.cmd = readline("tset : ");
		test(&cmd);
	}
}
