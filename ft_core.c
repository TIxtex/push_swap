#include "push_swap.h"

static void	ft_incrust_b_i_a(t_smart_str *solution,
			t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack_a->tam > i && stack_b->stack[0] > stack_a->stack[i])
		i++;
	while (stack_a->tam > j
		&& stack_b->stack[0] < stack_a->stack[(stack_a->tam - 1) - j])
		j++;
	if (i <= j + 1)
		ft_incrust_top_pa(solution, stack_a, stack_b, i);
	else
		ft_incrust_button_pa(solution, stack_a, stack_b, j);
}

static void	ft_order_3(t_smart_str *solution, t_stack *stack)
{
	if (stack->stack[1] > stack->stack[2])
	{
		if (stack->stack[0] < stack->stack[1]
			&& stack->stack[0] > stack->stack[2])
			ft_m_rr(solution, stack, "rra\n");
		else
		{
			ft_m_s(solution, stack, "sa\n");
			if (stack->stack[0] > stack->stack[1])
				ft_m_r(solution, stack, "ra\n");
			else
				ft_m_rr(solution, stack, "rra\n");
		}
	}
	else if (stack->stack[0] > stack->stack[2])
		ft_m_r(solution, stack, "ra\n");
	else if (stack->stack[0] < stack->stack[2]
		&& stack->stack[1] < stack->stack[0])
		ft_m_s(solution, stack, "sa\n");
}

static void	ft_order_5(t_smart_str *solution, t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = ft_reserve_stack(2);
	while (stack_a->tam > 3)
		ft_m_p1(solution, stack_b, stack_a, "pb\n");
	ft_order_3(solution, stack_a);
	while (stack_b->tam > 0)
		ft_incrust_b_i_a(solution, stack_a, stack_b);
	free(stack_b->stack);
	free(stack_b);
	while (stack_a->stack[0] > stack_a->stack[stack_a->tam - 1])
		ft_m_rr(solution, stack_a, "rra\n");
}

void	ft_core(t_stack *stack_a, t_smart_str *solution)
{
	if (ft_isordered(stack_a) == 0)
	{
		if (2 == stack_a->tam && stack_a->stack[0] > stack_a->stack[1])
			ft_m_s(solution, stack_a, "sa\n");
		else if (3 == stack_a->tam)
			ft_order_3(solution, stack_a);
		else if (6 > stack_a->tam && 3 < stack_a->tam)
			ft_order_5(solution, stack_a);
		else if (5 < stack_a->tam)
			ft_order_100(solution, stack_a);
		ft_optimice_sol(solution);
		write(STDOUT_FILENO, solution->start, solution->tam);
	}
}
