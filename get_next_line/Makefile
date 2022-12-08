# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: secker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 12:13:06 by secker            #+#    #+#              #
#    Updated: 2022/12/01 12:30:37 by secker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		cc $(CFLAGS) -c $(SRC)
		ar -rc $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: make fclean clean all

re: fclean all