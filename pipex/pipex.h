/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:08:53 by youhan            #+#    #+#             */
/*   Updated: 2022/06/07 21:10:34 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_fd
{
	int	r_fd;
	int	w_fd;
}	t_fd;

typedef struct s_list
{
	t_fd	fd;
	int		pipe_num;
	int		**p_fd;
	pid_t	*pid;
	int		bonus_mod;
	char	**path;
	char	*shell;
	char	***cmd;
	char	*limmit;
	char	*in_file;
	int		status;
	int		in_file_fd[2];
}	t_list;

int		diff_str(char *s1, char *s2, int mod);
void	error_code(int mod);
void	error_file(t_list *data);
void	error_cmd(t_list *data, char *cmd);
void	count_str_2(int *count, int *a);
char	**ft_split(const char *s, char c);
void	inputdata_check(int argc, char **argv, t_list *data);
void	find_cmd_local(char **env, t_list *data);
void	find_shell(char **env, t_list *data);
void	malloc_pfd_pid(t_list *data);
void	make_process(t_list *data);
int		process_num(t_list data, int pid);
void	all_close_write_pipe_fd(t_list *data);
void	all_close_read_pipe_fd(t_list *data);
void	close_fd(t_list *data);
void	push_infile_data(t_list *data);
void	exist_cmd(t_list *data, int process, char **dir_cmd);
void	contral_first_process(t_list *data);
void	contral_first_cmd_process(t_list *data, char **env);
void	contral_last_process(t_list *data, char **env);
void	contral_mid_process(t_list *data, int process, char **env);
void	contral_pipe_pid(t_list *data, char **env);
void	contral_pipe_pid_bonus(t_list *data, char **env);
void	contral_mul_pipe_pid(t_list *data, char **env);
void	join_infile_data(char **data, char **back_data);

#endif