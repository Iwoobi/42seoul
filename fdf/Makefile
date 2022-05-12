# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 17:13:58 by youhan            #+#    #+#              #
#    Updated: 2022/05/13 05:09:16 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc
TARGET = fdf
CFLAGS = 
SRCS = ft_fdf.c get_next_line_utils.c get_next_line.c ft_split_2.c ft_split.c
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