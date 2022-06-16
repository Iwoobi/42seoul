CC = cc
TARGET = philo
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
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

.PHONY : all clean fclean re 
