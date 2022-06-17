CC = cc
TARGET = philo
BONUS_TARGET = philo_bonus
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c creat_thread.c destroy_thread_mutex.c execution_thread.c ft_atoi.c input_init.c make_philos.c mutex_init.c philo_action.c philo_eat.c tools.c wait_thread.c
# BONUS_SRCS = 
# BONUS_OBJS = ${BONUS_SRCS:.c=.o}
OBJS = ${SRCS:.c=.o}


.o : .c
	${CC} ${CFLAGS} -c $< -o $@

${TARGET} :	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${TARGET}

# ${BONUS_TARGET} : ${BONUS_OBJS}
# 	${cc} ${CFLAGS} ${OBJS} -o ${BONUS_TARGET}

all : ${TARGET} 

# bonus : ${BONUS_TARGET}
	
clean : 
	rm -f ${OBJS} 
	#${BONUS_OBJS}

fclean: clean
	rm -f ${TARGET} 
	#${BONUS_TARGET}

re: fclean all

.PHONY : all clean fclean re 
