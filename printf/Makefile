# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: secker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 15:28:14 by secker            #+#    #+#              #
#    Updated: 2022/10/27 13:24:39 by secker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_hexa_low.c ft_hexa_up.c \
	ft_pointer.c ft_putstr.c ft_putnbr.c ft_putnbr_long.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME):
	cc $(CFLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all