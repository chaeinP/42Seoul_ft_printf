# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 14:44:15 by chaepark          #+#    #+#              #
#    Updated: 2022/01/18 10:38:34 by chaepark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_initialize.c ft_add.c ft_conversion.c ft_format.c\
		ft_convert_s.c ft_convert_c.c ft_convert_di.c ft_convert_p.c\
		ft_convert_lux.c ft_convert_pct.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft

LIBFT = ${LIBFTDIR}/libft.a

.c.o:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(LIBFT)
					ar rcs $(NAME) $(OBJS)

$(LIBFT):
					make -C ${LIBFTDIR}
					cp $(LIBFT) $(NAME)

all:	$(NAME)

bonus:	all

clean:
					make clean -C ${LIBFTDIR}
					rm -f ${OBJS}

fclean:	clean
					make fclean -C ${LIBFTDIR}
					rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus
