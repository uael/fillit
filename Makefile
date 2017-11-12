# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2017/11/12 12:05:24 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror -O3 -Iinclude -Ivendor/libft -Lvendor/libft -lft
CC = gcc
SRCS = \
	src/fillit.c \
	src/parse.c

all: $(NAME)

libft:
	$(MAKE) -C vendor/libft

$(NAME): libft
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	$(MAKE) -C vendor/libft clean

fclean: clean
	$(MAKE) -C vendor/libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
