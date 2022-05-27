# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 17:13:58 by youhan            #+#    #+#              #
#    Updated: 2022/05/27 19:20:30 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc
TARGET = fdf
CFLAG = -Wall -Werror -Wextra
CFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = arr_change.c data_check_push.c data_init_z.c draw_line.c fdf_init.c fdf.c ft_atoi.c 
OBJS = ${SRCS:.c=.o}

${TARGET} :	${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} ${OBJS} 

all : ${TARGET}

clean : 
	rm -f ${OBJS}

fclean: clean 
	rm -f ${TARGET}

re: fclean all

.PHONY : all clean fclean re bonus 