# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 19:03:58 by youhan            #+#    #+#              #
#    Updated: 2022/05/04 19:23:21 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
TARGET = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c
OBJS = ${SRCS:.c=.o}
OBJ = ${OBJS}

.o : .c
	${CC} ${CFLAGS} -c $< -o ${OBJ} 

${TARGET}:	${OBJ}
	${CC} ${CFLAGS} -o ${TARGET} ${OBJ}


all :	${TARGET}

clean : 
	rm -f ${OBJS} 

fclean: clean 
	rm -f ${TARGET}

re: fclean all

.PHONY : all clean fclean re
