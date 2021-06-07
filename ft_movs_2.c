#include "push_swap.h"

void	ft_m_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_m_sa(stack_a);
	ft_m_sb(stack_b);
}

void	ft_m_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_m_ra(stack_a);
	ft_m_rb(stack_b);
}

void	ft_m_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_m_rra(stack_a);
	ft_m_rrb(stack_b);
}
