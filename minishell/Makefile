# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 19:18:22 by youhan            #+#    #+#              #
#    Updated: 2022/06/27 20:29:48 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
TARGET = minishell
CFLAGS = -L/Users/youhan/.brew/opt/readline/lib  -I/Users/youhan/.brew/opt/readline/include -lreadline
SRCS = test.c
OBJS = ${SRCS:.c=.o}

.o : .c
	${CC} ${CFLAGS} -c $< -o $@

${TARGET} :	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${TARGET} 

all : ${TARGET} 

clean : 
	rm -f ${OBJS}

fclean: clean
	rm -f ${TARGET}

re: fclean all

.PHONY : all clean fclean re bonus
