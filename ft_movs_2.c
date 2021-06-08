#include "push_swap.h"

void	ft_m_ss(t_sol *solution, t_stack *stack_a, t_stack *stack_b)
{
	ft_m_sa(solution, stack_a);
	ft_m_sb(solution, stack_b);
}

void	ft_m_rr(t_sol *solution, t_stack *stack_a, t_stack *stack_b)
{
	ft_m_ra(solution, stack_a);
	ft_m_rb(solution, stack_b);
}

void	ft_m_rrr(t_sol *solution, t_stack *stack_a, t_stack *stack_b)
{
	ft_m_rra(solution, stack_a);
	ft_m_rrb(solution, stack_b);
}
