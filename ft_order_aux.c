#include "push_swap.h"

static void	ft_incrust_top(t_sol *solution, t_stack *stack_a, t_stack *stack_b,
			int num)
{
	int	j;

	j = num;
	while (num > 1)
	{
		ft_m_r(solution, stack_b, "rb\n");
		num--;
	}
	ft_m_p1(solution, stack_b, stack_a, "pb\n");
	if (1 == num)
		ft_m_s(solution, stack_b, "sb\n");
//	while (j-- > 1)
//		ft_m_rr(solution, stack_b, "rrb\n");
}

static void	ft_incrust_button(t_sol *solution,
			t_stack *stack_a, t_stack *stack_b, int num)
{
	int	i;

	i = num;
	while (--num >= 0)
		ft_m_rr(solution, stack_b, "rrb\n");
	ft_m_p1(solution, stack_b, stack_a, "pb\n");
//	ft_m_r(solution, stack_b, "rb\n");
//	while (i-- > 0)
//		ft_m_r(solution, stack_b, "rb\n");
}

void	ft_incrust_top_pa(t_sol *solution, t_stack *stack_a, t_stack *stack_b,
			int num)
{
	int	j;

	j = num;
	while (num > 1)
	{
		ft_m_r(solution, stack_a, "ra\n");
		num--;
	}
	ft_m_p1(solution, stack_a, stack_b, "pa\n");
	if (j > 0)
		ft_m_s(solution, stack_a, "sa\n");
	while (j > 1)
	{
		ft_m_rr(solution, stack_a, "rra\n");
		j--;
	}
}

void	ft_incrust_button_pa(t_sol *solution, t_stack *stack_a,
			t_stack *stack_b, int num)
{
	int	i;

	i = num;
	while (num > 0)
	{
		ft_m_rr(solution, stack_a, "rra\n");
		num--;
	}
	ft_m_p1(solution, stack_a, stack_b, "pa\n");
	ft_m_r(solution, stack_a, "ra\n");
	while (i > 0)
	{
		ft_m_r(solution, stack_a, "ra\n");
		i--;
	}
}

static int	ft_condition(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (0 == i && stack_a->stack[0] > stack_b->stack[0] && stack_a->stack[0] < stack_b->stack[stack_b->tam - 1])
		return (0);
	else if (stack_b->tam == i)
		return (0);
	else if (0 != i && stack_a->stack[0] > stack_b->stack[i] && stack_a->stack[0] < stack_b->stack[i - 1])
		return (0);
	else if (0 != i && stack_b->stack[i] > stack_b->stack[i - 1])
		if ((stack_a->stack[0] > stack_b->stack[i] && stack_a->stack[0] > stack_b->stack[i - 1]) || (stack_a->stack[0] < stack_b->stack[i] && stack_a->stack[0] < stack_b->stack[i - 1]))
			return (0);
	return (1);
}

void	ft_incrust_a_i_b_r(t_sol *solution, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	while (ft_condition(stack_a, stack_b, i) && stack_b->tam != 0)
		i++;
	j = stack_b->tam - i;
	if (stack_b->tam == 0)
		ft_m_p1(solution, stack_b, stack_a, "pb\n");
	else if (i <= j + 1)
		ft_incrust_top(solution, stack_a, stack_b, i);
	else
		ft_incrust_button(solution, stack_a, stack_b, j);
}
