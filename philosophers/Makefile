CC = cc
TARGET = philo
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c creat_thread.c destroy_thread_mutex.c execution_thread.c ft_atoi.c input_init.c make_philos.c mutex_init.c philo_action.c philo_eat.c tools.c wait_thread.c
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
