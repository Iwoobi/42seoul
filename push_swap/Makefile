# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 19:03:58 by youhan            #+#    #+#              #
#    Updated: 2022/05/12 17:15:09 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
TARGET = push_swap
LEAK_FLAG = -fsanitize=address 
BONUS_TARGET = checker
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c greedy.c ft_split_2.c greedy_2.c input_data_check.c loop_rotate.c malloc_data.c math.c push.c quick_sort.c r_rotate.c rotate.c rotate_sign_a_b.c sort_init_a_to_b.c swap.c hard_code_sort.c ft_split.c free.c argv_change.c error_printf.c 
BOUNS_NEED_SRCS = ft_split_2.c greedy.c greedy_2.c input_data_check.c loop_rotate.c malloc_data.c math.c push.c quick_sort.c r_rotate.c rotate.c rotate_sign_a_b.c sort_init_a_to_b.c swap.c hard_code_sort.c ft_split.c free.c argv_change.c error_printf.c 
BOUNS_NEED_OBJS = ${BOUNS_NEED_SRCS:.c=.o}
BOUNS_SRCS = push_swap_bonus.c check_bonus.c get_next_line.c get_next_line_utils.c
BONUS_OBJS = ${addprefix bonus/, ${BOUNS_SRCS:.c=.o}}
OBJS = ${SRCS:.c=.o}

.o : .c
	${CC} ${CFLAGS} -c $< -o $@

${TARGET} :	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${TARGET}

all : ${TARGET} ${BONUS_TARGET}

${BONUS_TARGET} : ${BONUS_OBJS} ${BOUNS_NEED_OBJS}
	${CC} ${CFLAGS} ${BONUS_OBJS} ${BOUNS_NEED_OBJS} -o ${BONUS_TARGET}

bonus : ${BONUS_OBJS} ${OBJS}
	${CC} ${CFLAGS} ${BONUS_OBJS} ${BOUNS_NEED_OBJS} -o ${BONUS_TARGET}
	
clean : 
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean 
	rm -f ${TARGET} ${BOUNS_TARGET}

re: fclean all

.PHONY : all clean fclean re bonus 
