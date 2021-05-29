#include "push_swap.h"

void	ft_have_dup(t_stack *stack)
{
	int	i;
	int j;

	i = -1;
	while (++i < stack->tam)
	{
		j = i;
		while (++j < stack->tam)
			if (stack->stack[i] == stack->stack[j])
				ft_error("Error, numeros duplicados.\n");
	}
}

void		ft_putstack(t_stack *stack, char s)
{
	int		i;

	i = -1;
	ft_putstr_fd("\n||Stack -> ", 1);
	ft_putchar_fd(s, 1);

	ft_putstr_fd("\n||_ _ _ _ _ _ _ _ _ _ _ ||\n", 1);
	while(++i < stack->tam)
	{
		ft_putstr_fd("||\t", 1);
		ft_putnbr_fd(stack->stack[i], 1);
		ft_putstr_fd("\t\t||\n", 1);
	}
	ft_putstr_fd("||_ _ _ _ _ _ _ _ _ _ _ ||\n\n", 1);
}

void	ft_error(char *error)
{
	ft_putstr_fd(error, 1);
	exit(-1);
}