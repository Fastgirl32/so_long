# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: secker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 10:20:47 by secker            #+#    #+#              #
#    Updated: 2022/10/20 11:56:30 by secker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c\
	ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c\
	ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalnum.c\
	ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memmove.c\
	ft_strdup.c ft_strnstr.c ft_isascii.c ft_memset.c ft_striteri.c\
	ft_strrchr.c ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_substr.c\
	ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_strtrim.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBJB = $(BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		cc $(CFLAGS) -c $(SRC)
		ar -rc $(NAME) $(OBJ)

bonus: $(NAME)
	cc $(CFLAGS) -c $(BONUS)
	ar -rc $(NAME) $(OBJB)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJB)

re: fclean all
