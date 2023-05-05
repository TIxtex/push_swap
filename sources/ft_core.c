#include "../push_swap.h"

static void	ft_incrust_b_i_a(t_sol *solution, t_st *a, t_st *b)
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

static void	ft_order_3(t_sol *solution, t_st *stack)
{
	int	*x;

	x = stack->stack;
	if (x[1] > x[2])
	{
		if (x[0] < x[1] && x[0] > x[2])
			ft_m_rr(solution, stack, RRA);
		else
		{
			ft_m_s(solution, stack, SA);
			if (x[0] > x[1])
				ft_m_r(solution, stack, RA);
			else
				ft_m_rr(solution, stack, RRA);
		}
	}
	else if (x[0] > x[2])
		ft_m_r(solution, stack, RA);
	else if (x[0] < x[2] && x[1] < x[0])
		ft_m_s(solution, stack, SA);
}

static void	ft_order_5(t_sol *solution, t_st *st_a)
{
	t_st	*st_b;

	st_b = ft_reserve_stack(2);
	while (st_a->tam > 3)
		ft_m_p1(solution, st_b, st_a, PB);
	ft_order_3(solution, st_a);
	while (st_b->tam > ZERO)
		ft_incrust_b_i_a(solution, st_a, st_b);
	free(st_b->stack);
	free(st_b);
	while (st_a->stack[0] > st_a->stack[st_a->tam - 1])
		ft_m_rr(solution, st_a, RRA);
}

void	ft_core(t_st *st_a, t_sol *solution)
{
	if (ZERO == ft_isordered(st_a))
	{
		if (2 == st_a->tam && st_a->stack[0] > st_a->stack[1])
			ft_m_s(solution, st_a, SA);
		else if (3 == st_a->tam)
			ft_order_3(solution, st_a);
		else if (6 > st_a->tam && 3 < st_a->tam)
			ft_order_5(solution, st_a);
		else if (5 < st_a->tam)
		{
			ft_order_100(solution, st_a);
/*			ft_optimice_sol(solution);*/
		}
		while (NULL != solution)
		{
			write(STDOUT_FILENO, (char *) solution->content, ft_strlen((char *) solution->content));
			solution = solution->next;
		}
	}
}
