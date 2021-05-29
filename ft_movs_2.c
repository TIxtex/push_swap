#include "push_swap.h"

void	ft_m_rb(t_stack *stack_b)
{
	int	i;
	int	aux;

	aux = stack_b->stack[0];
	i = -1;
	while (++i < stack_b->tam - 1)
		stack_b->stack[i] = stack_b->stack[i + 1];
	stack_b->stack[stack_b->tam - 1] = aux;
	ft_putstr_fd("rb\n", 1);
}

void	ft_m_rrb(t_stack *stack_b)
{
	int	i;
	int	aux;

	aux = stack_b->stack[stack_b->tam - 1];
	i = stack_b->tam - 1;
	while(--i >= 0)
		stack_b->stack[i + 1] = stack_b->stack[i];
	stack_b->stack[0] = aux;
	ft_putstr_fd("rrb\n", 1);
}

void		ft_up(t_stack *stack, int num)
{
	if (num > stack->tam / 2)
		while (num++ < stack->tam)
			ft_m_rra(stack);
	else
		while (num-- > 0)
			ft_m_ra(stack);
}