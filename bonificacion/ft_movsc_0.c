#include "checker.h"

void	ft_mc_s(t_stack *stack)
{
	int	aux;

	aux = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = aux;
}

void	ft_mc_r(t_stack *stack)
{
	int	aux;
	int	i;

	aux = stack->stack[0];
	i = -1;
	while (++i < stack->tam - 1)
		stack->stack[i] = stack->stack[i + 1];
	stack->stack[stack->tam - 1] = aux;
}

void	ft_mc_rr(t_stack *stack)
{
	int	aux;
	int	i;

	aux = stack->stack[stack->tam - 1];
	i = stack->tam - 1;
	while (--i >= 0)
		stack->stack[i + 1] = stack->stack[i];
	stack->stack[0] = aux;
}

void	ft_mc_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->tam;
	while (--i >= 0)
		stack_a->stack[i + 1] = stack_a->stack[i];
	stack_a->stack[0] = stack_b->stack[0];
	i = -1;
	while (++i < stack_b->tam - 1)
		stack_b->stack[i] = stack_b->stack[i + 1];
	stack_a->tam++;
	stack_b->tam--;
}

void	ft_mc_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->tam;
	while (--i >= 0)
		stack_b->stack[i + 1] = stack_b->stack[i];
	stack_b->stack[0] = stack_a->stack[0];
	i = -1;
	while (++i < stack_a->tam - 1)
		stack_a->stack[i] = stack_a->stack[i + 1];
	stack_a->tam--;
	stack_b->tam++;
}
