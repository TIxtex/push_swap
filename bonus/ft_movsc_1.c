#include "checker.h"

void	ft_mc_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_mc_s(stack_a);
	ft_mc_s(stack_b);
}

void	ft_mc_rr2(t_stack *stack_a, t_stack *stack_b)
{
	ft_mc_r(stack_a);
	ft_mc_r(stack_b);
}

void	ft_mc_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_mc_rr(stack_a);
	ft_mc_rr(stack_b);
}

void	ft_c_up(t_stack *stack, int num)
{
	if (num > (int) stack->tam / 2)
		while (num++ < (int) stack->tam)
			ft_mc_rr(stack);
	else
		while (num-- > 0)
			ft_mc_r(stack);
}
