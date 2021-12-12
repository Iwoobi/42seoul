# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 03:31:14 by youhan            #+#    #+#              #
#    Updated: 2021/12/13 03:31:14 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
TARGET = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_ft_strncmp.c  ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.c : .o
	${CC} ${CFLAGS} -c $< -o ${OBJ} 

${TARGET}:	${OBJ}
	ar -rcs ${TARGET} ${OBJ}

ifdef FLAG_BONUS
	OBJ = ${OBJ} ${BONUS_OBJS}
else
	OBJ = ${OBJ}
endif

all :	${TARGET}

bonns :
	make FLAG_BONUS=1 all

re:	fclean all

clean : 
	rm -f ${OBJS}

fclean: clean 
	rm -f ${TARGET}

re:	fclean all

.PHONY : all clean fclean re