#include "push_swap.h"

static void	ft_order_3(int *stack_a)
{

	if (stack_a[1] > stack_a[2])
	{
		if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
			ft_putstr_fd("rra\n", 1);
		else if (stack_a[0] > stack_a[1])
			ft_putstr_fd("sa\nrra\n", 1);
		else
			ft_putstr_fd("sa\nra\n", 1);
	}
	else if (stack_a[0] > stack_a[2])
		ft_putstr_fd("ra\n", 1);
	else if (stack_a[0] < stack_a[2] && stack_a[1] < stack_a[0])
		ft_putstr_fd("sa\n", 1);
}

void		ft_core(int *stack_a, int tam)
{

	if (2 == tam && stack_a[0] > stack_a[1])
		ft_putstr_fd("sa\n", 1);
	else if (3 == tam)
		ft_order_3(stack_a);
	ft_putstr_fd("Stack ordenado\n", 1);
	ft_putstack(stack_a, tam);
}