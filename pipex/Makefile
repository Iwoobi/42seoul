# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 19:06:10 by youhan            #+#    #+#              #
#    Updated: 2022/06/08 03:37:46 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
TARGET = pipex
CFLAGS = -Wall -Wextra -Werror
BONUS_SRCS = ft_split_2.c ft_split.c get_next_line.c get_next_line_utils.c bonus/main_bonus.c bonus/close_fd_bonus.c bonus/contral_first_process_bonus.c contral_pipe_pid.c exist_cmd.c find_cmd_local.c find_shell.c bonus/inputdata_check_bonus.c make_process.c bonus/malloc_pfd_pid_bonus.c print_error.c process_num.c bonus/push_infile_data_bonus.c bonus/contral_pipe_pid_bonus.c bonus/diif_str_bonus.c
SRCS = ft_split_2.c ft_split.c get_next_line.c get_next_line_utils.c main.c close_fd.c contral_first_process.c contral_pipe_pid.c exist_cmd.c find_cmd_local.c find_shell.c inputdata_check.c make_process.c malloc_pfd_pid.c print_error.c process_num.c
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

ifdef FLAG_BONUS
	OBJ = ${BONUS_OBJS}
else
	OBJ = ${OBJS}
endif

.o : .c
	${CC} ${CFLAGS} -c $< -o $@

${TARGET} :	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${TARGET}

all : ${TARGET} 


bonus :
	@make FLAG_BONUS=1 all
	
clean : 
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean 
	rm -f ${TARGET}

re: fclean all

.PHONY : all clean fclean re bonus 
