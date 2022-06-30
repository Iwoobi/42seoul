/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:41:44 by youhan            #+#    #+#             */
/*   Updated: 2022/06/30 16:47:21 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINISHELL_H
# define MINISHELL_H


#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_cmd
{
	char	*cmd;
	char	*cmd_mod;
	int		*status;
}	t_cmd;


#endif