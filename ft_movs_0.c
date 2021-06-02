#include "push_swap.h"

void	ft_m_sa(t_stack *stack_a)
{
	int	aux;

	aux = stack_a->stack[0];
	stack_a->stack[0] = stack_a->stack[1];
	stack_a->stack[1] = aux;
	ft_putstr_fd("sa\n", 1);
}

void	ft_m_ra(t_stack *stack_a)
{
	int	aux;
	int	i;

	aux = stack_a->stack[0];
	i = -1;
	while (++i < stack_a->tam - 1)
		stack_a->stack[i] = stack_a->stack[i + 1];
	stack_a->stack[stack_a->tam - 1] = aux;
	ft_putstr_fd("ra\n", 1);
}

void	ft_m_rra(t_stack *stack_a)
{
	int	aux;
	int	i;

	aux = stack_a->stack[stack_a->tam - 1];
	i = stack_a->tam - 1;
	while (--i >= 0)
		stack_a->stack[i + 1] = stack_a->stack[i];
	stack_a->stack[0] = aux;
	ft_putstr_fd("rra\n", 1);
}

void	ft_m_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->tam;
	while (--i >= 0)
		stack_a->stack[i + 1] = stack_a->stack[i];
	stack_a->stack[0] = stack_b->stack[0];
	i = -1;
	while (++i < stack_b->tam - 1)
		stack_b->stack[i] = stack_b->stack[i + 1];
	ft_putstr_fd("pa\n", 1);
	stack_a->tam++;
	stack_b->tam--;
}

void	ft_m_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->tam;
	while (--i >= 0)
		stack_b->stack[i + 1] = stack_b->stack[i];
	stack_b->stack[0] = stack_a->stack[0];
	i = -1;
	while (++i < stack_a->tam - 1)
		stack_a->stack[i] = stack_a->stack[i + 1];
	ft_putstr_fd("pb\n", 1);
	stack_a->tam--;
	stack_b->tam++;
}
