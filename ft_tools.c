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

int	ft_isordered(t_stack *stack)
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (++i < stack->tam - 1 && flag)
		if (stack->stack[i] > stack->stack[i + 1])
			flag = 0;
	if (flag)
		return (1);
	return (0);
}

int	ft_condition(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (0 == i && stack_a->stack[0] > stack_b->stack[0]
		&& stack_a->stack[0] < stack_b->stack[stack_b->tam - 1])
		return (0);
	else if (stack_b->tam == i)
		return (0);
	else if (0 != i && stack_a->stack[0] > stack_b->stack[i]
		&& stack_a->stack[0] < stack_b->stack[i - 1])
		return (0);
	else if (0 != i && stack_b->stack[i] > stack_b->stack[i - 1])
		if ((stack_a->stack[0] > stack_b->stack[i]
				&& stack_a->stack[0] > stack_b->stack[i - 1])
			|| (stack_a->stack[0] < stack_b->stack[i]
				&& stack_a->stack[0] < stack_b->stack[i - 1]))
			return (0);
	return (1);
}

void	ft_colocate(t_sol *solution, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->tam - 1 && stack->stack[i] > stack->stack[i + 1])
		i++;
	if (i != stack->tam - 1)
	{
		if (i < stack->tam / 2)
			while (i-- > 0)
				ft_m_r(solution, stack, "rb\n");
		else
			while (i++ < stack->tam - 1)
				ft_m_rr(solution, stack, "rrb\n");
	}
}

/*
void	ft_putstack(t_stack *stack, char s)
{
	int		i;

	i = -1;
	ft_putstr_fd("\n||Stack -> ", 1);
	ft_putchar_fd(s, 1);
	ft_putstr_fd("\n||_ _ _ _ ||\n", 1);
	while (++i < stack->tam)
	{
		ft_putstr_fd("||\t", 1);
		ft_putnbr_fd(stack->stack[i], 1);
		ft_putstr_fd("\t||\n", 1);
	}
	ft_putstr_fd("||_ _ _ _ ||\n\n", 1);
}*/