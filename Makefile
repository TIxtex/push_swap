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

NAME = $(NAMEM) $(NAMEB)
NAMEM = push_swap
NAMEB = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -fsanitize=address
LIBFT = libft/libft.a
INCLUDE = push_swap.h
MAINM = mandatory/main.c
MAINB = bonus/main.c
SOURCES = $(SOURCESM) $(SOURCESB)
SOURCESM = \
	ft_check_args.c \
	ft_core.c \
	ft_movements.c \
	ft_order.c ft_order_aux.c \
	ft_solution.c ft_solution_optimice.c \
	ft_tools.c
SOURCESB = \
	bonus/ft_movsc_0.c bonus/ft_movsc_1.c
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(INCLUDE) $(LIBFT) $(OBJECTS)

$(NAMEM): $(INCLUDE) $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) $(MAINM) -o $(NAMEM)
	
$(NAMEB): $(INCLUDE) $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) $(MAINB) -o $(NAMEB)

$(LIBFT):
	make -C libft/
	
.PHONY: all clean fclean f re

all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
	/bin/rm -rf $(OBJECTSB)
	make clean -C libft/
fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(NAME2)
	/bin/rm -rf $(LIBFT)
re: fclean all
f: fclean
	