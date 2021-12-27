# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 14:44:15 by chaepark          #+#    #+#              #
#    Updated: 2021/12/27 14:47:10 by chaepark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =

OBJS =

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

.c.o:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJECTS)
					ar rcs $(NAME) $(OBJECTS)

all:	$(NAME)

bonus:	all

clean:
					rm -f ${OBJS} ${BO_OBJS}

fclean:	clean
					rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus
