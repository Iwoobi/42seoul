# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 19:03:58 by youhan            #+#    #+#              #
#    Updated: 2022/05/05 21:26:41 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
TARGET = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c greedy.c greedy_2.c input_data_check.c loop_rotate.c malloc_data.c math.c push.c quick_sort.c r_rotate.c rotate.c rotate_sign_a_b.c sort_init_a_to_b.c swap.c
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
