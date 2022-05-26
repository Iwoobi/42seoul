# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 19:38:28 by youhan            #+#    #+#              #
#    Updated: 2022/03/24 20:13:03 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
TARGET = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = 
OBJS = ${SRCS:.c=.o}
OBJ = ${OBJS}

.c : .o
	${CC} ${CFLAGS} -c $< -o ${OBJ} 

${TARGET}:	${OBJ}
	ar -rcs ${TARGET} ${OBJ}


all :	${TARGET}

clean : 
	rm -f ${OBJS} 

fclean: clean 
	rm -f ${TARGET}

re: fclean all

.PHONY : all clean fclean re
