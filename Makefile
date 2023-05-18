# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 19:37:36 by uherrero          #+#    #+#              #
#    Updated: 2023/05/06 18:10:59 by uliherre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(NAMEM) $(NAMEB)
NAMEM = push_swap
NAMEB = checker
CC = gcc -std=c89
CFLAGS = -Wall -Wextra -Werror -pedantic
DEBUG = -fsanitize=address
LIBFT = libft/libft_b.a
INCLUDE = push_swap.h libft/libft.h bonus/checker.h
MAINM = mandatory/main.c
MAINB = bonus/main.c
SOURCES = $(SOURCESM) $(SOURCESB)
SOURCESM = \
	sources/ft_check_args.c \
	sources/ft_core.c \
	sources/ft_movements.c \
	sources/ft_order.c sources/ft_order_aux.c \
	sources/ft_tools.c sources/get_next_line.c \
	sources/ft_solution.c
SOURCESB = \
	bonus/ft_movsc_0.c bonus/ft_movsc_1.c
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(INCLUDE) $(LIBFT) $(OBJECTS)

$(NAMEM): $(INCLUDE) $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MAINM) $(LIBFT) -o $(NAMEM)
	
$(NAMEB): $(INCLUDE) $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MAINB) $(LIBFT) -o $(NAMEB)

$(LIBFT):
	make bonus -C libft/
	
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
