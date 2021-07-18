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
PSMAIN = mandatory/main.c
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = ft_core.c ft_movs_0.c ft_movs_1.c ft_movs_2.c\
	ft_order_0.c ft_order_1.c ft_solution_opt_0.c ft_solution_opt_1.c\
	ft_solution.c ft_tools.c
SOURCESB = bonus/main.c bonus/ft_movsc_0.c\
	bonus/ft_movsc_1.c
LIBFT = libft/libft.a

.PHONY: all clean fclean f re library mchek

$(NAME): $(SOURCES)
	cd libft && make
	cd ..
	$(COMPILER) $(FLAGS) $(SOURCES) $(PSMAIN) $(LIBFT) -o $(NAME)
	
$(NAME2): $(SOURCESB)
	$(COMPILER) $(FLAGS) $(SOURCESB) $(SOURCES) $(LIBFT) -o $(NAME2)

all: $(NAME) $(NAME2)
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(NAME2)
	/bin/rm -rf $(LIBFT)
f: fclean
re: fclean all
bonus: $(NAME2)
	