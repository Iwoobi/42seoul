# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 17:13:58 by youhan            #+#    #+#              #
#    Updated: 2022/05/27 21:10:55 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc
NAME = fdf
TARGET_BONUS = fdf_bonus
CFLAGS = -Wall -Werror -Wextra
CFLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = arr_change.c data_check_push.c data_init_z.c copy_data.c draw_line.c fdf_init.c fdf.c ft_atoi.c ft_math.c ft_split.c ft_strlen.c ft_split_2.c get_next_line_utils.c get_next_line.c main.c mlx_init.c mlx_key_loop.c open_file.c print_error.c loop.c
BONUS_SRCS = arr_change.c data_check_push.c data_init_z.c copy_data.c draw_line.c fdf_init.c fdf.c ft_atoi.c ft_math.c ft_split.c ft_strlen.c ft_split_2.c get_next_line_utils.c get_next_line.c main_bonus.c mlx_init.c mlx_key_loop.c open_file.c print_error.c loop.c
MLX = libmlx.a
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o} 

.o : .c
	${CC} ${CFLAGS} -c $< -o $@
	
${NAME} : ${OBJS} ${MLX}
	${CC} ${CFLAG} ${CFLAGS} -o ${NAME} ${OBJS} ${MLX}

${TARGET_BONUS} : ${BONUS_OBJS} ${MLX}
	${CC} ${CFLAG} ${CFLAGS} -o ${TARGET_BONUS} ${BONUS_OBJS} ${MLX}
${MLX} : 
	make -C mlx
	cp mlx/${MLX} ./

all : ${NAME}

clean :
	rm -f ${OBJS} ${BONUS_OBJS} ${MLX}
	make clean -C mlx
fclean: clean
	rm -f ${NAME} ${TARGET_BONUS}

bonus : ${TARGET_BONUS}
	

re: fclean all

.PHONY : all clean fclean re bonus 