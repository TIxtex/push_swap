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
NAME2 = checker
PSMAIN = obligatoria/main.c
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = *.c
SOURCES2 = bonificacion/*.c
LIBFT = libft/libft.a
OBJECTS = *.o

.PHONY: all clean fclean f re library mchek

$(NAME): $(SOURCES)
	cd libft && make
	cd ..
	$(COMPILER) $(FLAGS) $(SOURCES) $(PSMAIN) $(LIBFT) -o $(NAME)

all: library $(NAME) mchek
library:
	cd libft && make
	cd ..
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(NAME2)
	/bin/rm -rf $(LIBFT)
f: fclean
re: fclean all
mchek: $(SOURCES2)
	$(COMPILER) $(FLAGS) $(SOURCES) $(SOURCES2) $(LIBFT) -o $(NAME2)