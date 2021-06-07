#include "push_swap.h"

static void	ft_order_3(t_stack *stack)
{
	if (stack->stack[1] > stack->stack[2])
	{
		if (stack->stack[0] < stack->stack[1]
			&& stack->stack[0] > stack->stack[2])
			ft_m_rra(stack);
		else
		{
			ft_m_sa(stack);
			if (stack->stack[0] > stack->stack[1])
				ft_m_ra(stack);
			else
				ft_m_rra(stack);
		}
	}
	else if (stack->stack[0] > stack->stack[2])
		ft_m_ra(stack);
	else if (stack->stack[0] < stack->stack[2]
		&& stack->stack[1] < stack->stack[0])
		ft_m_sa(stack);
}

static void	ft_order_5(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = ft_reserve_stack(2);
	while (stack_a->tam > 3)
		ft_m_pb(stack_a, stack_b);
	ft_order_3(stack_a);
	while (stack_b->tam > 0)
		ft_incrust_b_i_a(stack_a, stack_b);
	free(stack_b->stack);
	free(stack_b);
}

void	ft_core(t_stack *stack_a)
{
	if (2 == stack_a->tam && stack_a->stack[0] > stack_a->stack[1])
		ft_m_sa(stack_a);
	else if (3 == stack_a->tam)
		ft_order_3(stack_a);
	else if (6 > stack_a->tam && 3 < stack_a->tam)
		ft_order_5(stack_a);
	else if (5 < stack_a->tam)
		ft_order_100(stack_a);
	ft_putstack(stack_a, 'a');//debug
}
