#include "push_swap.h"

t_stack	*ft_reserve_stack(int tam)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (NULL == stack)
		ft_error("Error, fallo en reserva de memoria.\n");
	stack->stack = (int *)ft_calloc(tam, sizeof(int));
	if (NULL == stack->stack)
		ft_error("Error, fallo en reserva de memoria.\n");
	return (stack);
}

void	ft_have_dup(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->tam)
	{
		j = i;
		while (++j < stack->tam)
			if (stack->stack[i] == stack->stack[j])
				ft_error("Error, numeros duplicados.\n");
	}
}

void	ft_isordered(t_stack *stack)
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (++i < stack->tam - 1 && flag)
		if (stack->stack[i] > stack->stack[i + 1])
			flag = 0;
	if (flag)
		ft_error("Stack ordenado\n");
}

void	ft_putstack(t_stack *stack, char s)
{
	int		i;

	i = -1;
	ft_putstr_fd("\n||Stack -> ", 1);
	ft_putchar_fd(s, 1);
	ft_putstr_fd("\n||_ _ _ _ _ _ _ _ _ _ _ ||\n", 1);
	while (++i < stack->tam)
	{
		ft_putstr_fd("||\t", 1);
		ft_putnbr_fd(stack->stack[i], 1);
		ft_putstr_fd("\t\t||\n", 1);
	}
	ft_putstr_fd("||_ _ _ _ _ _ _ _ _ _ _ ||\n\n", 1);
}
