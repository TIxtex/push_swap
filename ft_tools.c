#include "push_swap.h"

void	ft_have_dup(int *stack_a, int tam)
{
	int	i;
	int j;

	i = -1;
	while (++i < tam)
	{
		j = i;
		while (++j < tam)
			if (stack_a[i] == stack_a[j])
				ft_error("Error, numeros duplicados.\n");
	}
}

void	ft_putstack(int *stack_a, int tam)
{
	int	i;
	char a;

	a = 'A';
	if (tam <= 2)
		a = 'B';
	i = 0;
	ft_putstr_fd("\n||Stack -> ", 1);
	ft_putstr_fd(&a, 1);

	ft_putstr_fd("\n||_ _ _ _ _ _ _ _ _ _ _ ||\n", 1);
	while(i < tam)
	{
		ft_putstr_fd("||\t", 1);
		ft_putnbr_fd(stack_a[i], 1);
		ft_putstr_fd("\t\t||\n", 1);
		i++;
	}
	ft_putstr_fd("||_ _ _ _ _ _ _ _ _ _ _ ||\n\n", 1);
}

void	ft_error(char *error)
{
	ft_putstr_fd(error, 1);
	exit(-1);
}