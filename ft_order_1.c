#include "push_swap.h"

static void	ft_incrust_top(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	j;

	j = num;
	while (num > 1)
	{
		ft_m_rb(stack_b);
		num--;
	}
	ft_m_pb(stack_a, stack_b);
	if (1 == num)
		ft_m_sb(stack_b);
	while (j-- > 1)
		ft_m_rrb(stack_b);
}

static void	ft_incrust_button(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	i;

	i = num;
	while (--num >= 0)
		ft_m_rrb(stack_b);
	ft_m_pb(stack_a, stack_b);
	ft_m_rb(stack_b);
	while (i-- > 0)
		ft_m_rb(stack_b);
}

void	ft_incrust_a_i_b_r(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack_b->tam > i && stack_a->stack[0] < stack_b->stack[i])
		i++;
	while (stack_b->tam > j && stack_a->stack[0] > stack_b->stack[(stack_b->tam - 1) - j])
		j++;
	if (stack_b->tam == 0 || stack_a->stack[0] > stack_b->stack[0])
		ft_m_pb(stack_a, stack_b);
	else if (i <= j + 1)
		ft_incrust_top(stack_a, stack_b, i);
	else
		ft_incrust_top(stack_a, stack_b, j);
}

void	ft_incrust_a_i_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack_b->tam > i && stack_a->stack[0] < stack_b->stack[i])
		i++;
	while (stack_b->tam > j && stack_a->stack[0] > stack_b->stack[(stack_b->tam - 1) - j])
		j++;
	if (stack_b->tam == 0 || stack_a->stack[0] > stack_b->stack[0])
		ft_m_pb(stack_a, stack_b);
	else if (i <= j + 1)
		ft_incrust_top(stack_a, stack_b, i);
	else
		ft_incrust_top(stack_a, stack_b, j);
}