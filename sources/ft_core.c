#include "../push_swap.h"

static void	ft_incrust_b_i_a(t_sol *solution, t_stack *a, t_stack *b)
{
	size_t	x;
	size_t	y;

	x = ZERO;
	y = ZERO;
	while (a->tam > x && b->stack[0] > a->stack[x])
		x++;
	while (a->tam > y && b->stack[0] < a->stack[(a->tam - 1) - y])
		y++;
	if (x <= y + 1)
		ft_incrust_top_pa(solution, a, b, x);
	else
		ft_incrust_button_pa(solution, a, b, y);
}

static void	ft_order_3(t_sol *solution, t_stack *stack)
{
	int	*x;

	x = stack->stack;
	if (x[1] > x[2])
	{
		if (x[0] < x[1] && x[0] > x[2])
			ft_m_rr(solution, stack, "rra\n");
		else
		{
			ft_m_s(solution, stack, "sa\n");
			if (x[0] > x[1])
				ft_m_r(solution, stack, "ra\n");
			else
				ft_m_rr(solution, stack, "rra\n");
		}
	}
	else if (x[0] > x[2])
		ft_m_r(solution, stack, "ra\n");
	else if (x[0] < x[2] && x[1] < x[0])
		ft_m_s(solution, stack, "sa\n");
}

static void	ft_order_5(t_sol *solution, t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = ft_reserve_stack(2);
	while (stack_a->tam > 3)
		ft_m_p1(solution, stack_b, stack_a, "pb\n");
	ft_order_3(solution, stack_a);
	while (stack_b->tam > ZERO)
		ft_incrust_b_i_a(solution, stack_a, stack_b);
	free(stack_b->stack);
	free(stack_b);
	while (stack_a->stack[0] > stack_a->stack[stack_a->tam - 1])
		ft_m_rr(solution, stack_a, "rra\n");
}

void	ft_core(t_stack *stack_a, t_sol *solution)
{
	if (ZERO == ft_isordered(stack_a))
	{
		if (2 == stack_a->tam && stack_a->stack[0] > stack_a->stack[1])
			ft_m_s(solution, stack_a, "sa\n");
		else if (3 == stack_a->tam)
			ft_order_3(solution, stack_a);
		else if (6 > stack_a->tam && 3 < stack_a->tam)
			ft_order_5(solution, stack_a);
		else if (5 < stack_a->tam)
		{
			ft_order_100(solution, stack_a);
/*			ft_optimice_sol(solution);*/
		}
		while (NULL != solution)
		{
			write(STDOUT_FILENO, (char *) solution->content, ft_strlen((char *) solution->content));
			solution = solution->next;
		}
	}
}
