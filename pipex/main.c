/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:36:42 by youhan            #+#    #+#             */
/*   Updated: 2022/06/08 02:36:57 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_list	data;

	data.status = 0;
	inputdata_check(argc, argv, &data);
	find_cmd_local(env, &data);
	find_shell(env, &data);
	malloc_pfd_pid(&data);
	make_process(&data);
	contral_pipe_pid(&data, env);
	exit(data.status);
}
