# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uherrero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 19:37:36 by uherrero          #+#    #+#              #
#    Updated: 2019/11/17 20:05:10 by uherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = *.c
LIBFT = libft/libft.a
OBJECTS = *.o

.PHONY: all clean fclean f re library

$(NAME): $(SOURCES)
	cd libft && make
	cd ..
	$(COMPILER) $(FLAGS) $(SOURCES) $(LIBFT) -o $(NAME)

all: library $(NAME)
library:
	cd libft && make
	cd ..
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(LIBFT)
f: fclean
re: fclean $(NAME)
