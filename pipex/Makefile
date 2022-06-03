# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 19:06:10 by youhan            #+#    #+#              #
#    Updated: 2022/06/03 06:14:42 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
TARGET = pipex
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_split_2.c ft_split.c get_next_line.c get_next_line_utils.c pipex.c
OBJS = ${SRCS:.c=.o}

.o : .c
	${CC} ${CFLAGS} -c $< -o $@ -g

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
