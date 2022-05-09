# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 19:03:58 by youhan            #+#    #+#              #
#    Updated: 2022/05/09 22:33:02 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
TARGET = push_swap
BOUNOS = checker
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c greedy.c greedy_2.c input_data_check.c loop_rotate.c malloc_data.c math.c push.c quick_sort.c r_rotate.c rotate.c rotate_sign_a_b.c sort_init_a_to_b.c swap.c hard_code_sort.c ft_split.c
BOUNS_SRCS = 
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
OBJS = ${SRCS:.c=.o}

.o : .c
	${CC} ${CFLAGS} -c $< -o ${OBJS}

${TARGET} :	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${TARGET} 

${BONUS_OBJS} : 


all :	${TARGET}

bonus : ${BONUS_OBJS}
	${CC} ${CFLAGS} -o ${BONUS} ${BONUS_OBJS}

clean : 
	rm -f ${OBJS} 

fclean: clean 
	rm -f ${TARGET}

re: fclean all

.PHONY : all clean fclean re bonus
