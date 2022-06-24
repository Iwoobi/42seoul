CC = cc
TARGET = philo_bonus
CFLAGS = -Wall -Wextra -Werror
SRCS = main_bonus.c close_bonus.c wait_process_bonus.c semaphore_init_bonus.c make_process_bonus.c tools_bonus.c execution_thread_bonus.c philo_action_bonus.c philo_eat_bonus.c input_init_bonus.c make_philos_bonus.c ../ft_atoi.c
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
