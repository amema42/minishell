# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amema <amema@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 16:54:23 by amema             #+#    #+#              #
#    Updated: 2024/03/15 16:54:24 by amema            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = libftprintf.a

SRCS =	ft_char.c\
		ft_exa.c\
		ft_number.c\
		ft_putptr.c\
		ft_printf.c\

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJECT = ${SRCS:.c=.o}

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

all : ${NAME}

$(NAME) : ${OBJECT}
	ar rcs ${NAME} ${OBJECT}

clean :
	${RM} ${OBJECT}

fclean : clean
	${RM} ${NAME}

re : fclean all
