#include "push_swap.h"

static void	ft_incrust_top(t_sol *solution, t_stack *stack_a, t_stack *stack_b,
			int num)
{
	int	j;

	j = num;
	while (num > 1)
	{
		ft_m_rb(solution, stack_b);
		num--;
	}
	ft_m_pb(solution, stack_a, stack_b);
	if (1 == num)
		ft_m_sb(solution, stack_b);
	while (j-- > 1)
		ft_m_rrb(solution, stack_b);
}

static void	ft_incrust_button(t_sol *solution,
			t_stack *stack_a, t_stack *stack_b, int num)
{
	int	i;

	i = num;
	while (--num >= 0)
		ft_m_rrb(solution, stack_b);
	ft_m_pb(solution, stack_a, stack_b);
	ft_m_rb(solution, stack_b);
	while (i-- > 0)
		ft_m_rb(solution, stack_b);
}

void	ft_incrust_top_r(t_sol *solution, t_stack *stack_a, t_stack *stack_b,
			int num)
{
	int	j;

	j = num;
	while (num > 0)
	{
		ft_m_ra(solution, stack_a);
		num--;
	}
	ft_m_pa(solution, stack_a, stack_b);
	if (1 == num)
		ft_m_sa(solution, stack_a);
	while (j-- > 1)
		ft_m_rra(solution, stack_a);
}

void	ft_incrust_button_r(t_sol *solution, t_stack *stack_a, t_stack *stack_b,
			int num)
{
	int	i;

	i = num;
	while (--num >= 0)
		ft_m_rra(solution, stack_a);
	ft_m_pa(solution, stack_a, stack_b);
	ft_m_ra(solution, stack_a);
	while (i-- > 0)
		ft_m_ra(solution, stack_a);
}

void	ft_incrust_a_i_b_r(t_sol *solution, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack_b->tam > i && stack_a->stack[0] < stack_b->stack[i])
		i++;
	while (stack_b->tam > j
		&& stack_a->stack[0] > stack_b->stack[(stack_b->tam - 1) - j])
		j++;
	if (stack_b->tam == 0 || stack_a->stack[0] > stack_b->stack[0])
		ft_m_pb(solution, stack_a, stack_b);
	else if (i <= j + 1)
		ft_incrust_top(solution, stack_a, stack_b, i);
	else
		ft_incrust_button(solution, stack_a, stack_b, j);
}
