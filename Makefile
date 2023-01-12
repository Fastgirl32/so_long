# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: secker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 11:59:36 by secker            #+#    #+#              #
#    Updated: 2023/01/10 16:24:17 by secker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = make_map.c valid_path.c map_test.c so_long.c create_map.c commands.c create_images.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		(cd libft && make)
		cp libft/libft.a libft.a
		(cd printf && make)
		cp printf/libftprintf.a libftprintf.a
		(cd get_next_line && make)
		cp get_next_line/get_next_line.a get_next_line.a
		cc -g $(CFLAGS) -o $(NAME) $(SRC) libft.a libmlx.a get_next_line.a libftprintf.a -lXext -lX11

play: $(NAME)
		./$(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a get_next_line.a libftprintf.a
	(cd libft && make fclean)
	(cd printf && make fclean)
	(cd get_next_line && make fclean)

clean:
	rm -f $(OBJ)
	(cd libft && make clean)
	(cd printf && make clean)
	(cd get_next_line && make clean)

re: fclean all

.PHONY: make fclean clean all