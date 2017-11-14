# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2017/11/12 13:54:57 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror -O3 -Iinclude -Ilib -Llib -lft
CC = gcc
SRCS = \
	src/fillit.c \
	src/parse.c \
	src/solve.c

all: $(NAME)

libft:
	$(MAKE) -C lib

$(NAME): libft
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	$(MAKE) -C lib clean
	/bin/rm -f *.o

fclean: clean
	$(MAKE) -C lib fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
