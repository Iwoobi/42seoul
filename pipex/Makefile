# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 19:06:10 by youhan            #+#    #+#              #
#    Updated: 2022/06/07 21:02:47 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
TARGET = pipex
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_split_2.c ft_split.c get_next_line.c get_next_line_utils.c main.c close_fd.c contral_first_process.c contral_pipe_pid.c exist_cmd.c find_cmd_local.c find_shell.c inputdata_check.c make_process.c malloc_pfd_pid.c print_error.c process_num.c bonus/contral_first_process.c bonus/contral_pipe_pid_bonus.c bonus/diif_str.c
OBJS = ${SRCS:.c=.o}

.o : .c
	${CC} ${CFLAGS} -c $< -o $@

${TARGET} :	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${TARGET}

all : ${TARGET} 


bonus : ${TARGET}
	${CC} ${CFLAGS} ${OBJS} -o ${TARGET}
	
clean : 
	rm -f ${OBJS}

fclean: clean 
	rm -f ${TARGET}

re: fclean all

.PHONY : all clean fclean re bonus 
