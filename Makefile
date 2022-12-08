# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: secker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 11:59:36 by secker            #+#    #+#              #
#    Updated: 2022/12/07 17:26:11 by secker           ###   ########.fr        #
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
		(cd get_next_line && make)
		cp get_next_line/get_next_line.a get_next_line.a
		(cd minilibx-linux && make)
		cp minilibx-linux/libmlx.a libmlx.a
		gcc -g $(CFLAGS) -o $(NAME) $(SRC) libft.a get_next_line.a libmlx.a -lXext -lX11

play: $(NAME)
		./$(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a get_next_line.a libmlx.a
	(cd libft && make fclean)
	(cd get_next_line && make fclean)

clean:
	rm -f $(OBJ)
	(cd libft && make clean)
	(cd get_next_line && make clean)
	(cd minilibx-linux && make clean)

re: fclean all

.PHONY: make fclean clean all