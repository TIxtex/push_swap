#include "push_swap.h"

static int		ft_find_2(t_stack *stack, t_fragment fragment)
{
	int			i;

	i = stack->tam;
	while (--i >= 0)
		if (stack->stack[i] < fragment.min + (fragment.tam * (fragment.phase + 1)) 
		&& fragment.min + (fragment.tam * fragment.phase) < stack->stack[i])
			return (i);
	return (0);
}	

static int		ft_find_1(t_stack *stack, t_fragment fragment)
{
	int			i;

	i = -1;
	while (++i < stack->tam)
		if (stack->stack[i] <= fragment.min + (fragment.tam * (fragment.phase + 1)) 
		&& fragment.min + (fragment.tam * fragment.phase) <= stack->stack[i])
			return (i);
	return (0);
}

static void		ft_up(t_stack *stack, int num)
{
	if (num > stack->tam / 2)
		while (num++ < stack->tam)
			ft_m_rra(stack);
	else
		while (num-- > 0)
			ft_m_ra(stack);
}

static void		ft_i_b_2(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	int			j;

	i = 0;
	j = stack_b->tam - 1;
	while (stack_a->stack[0] < stack_b->stack[i])
		i++;
	while (stack_a->stack[0] > stack_b->stack[j])
		j--;
	if (i < stack_b->tam - j)
	{
		j = i;
		while (i-- > 0)
			ft_m_rb(stack_b);
		ft_m_pb(stack_a, stack_b);
		while (j-- > 0)
			ft_m_rrb(stack_b);
	}
	else
	{
		i = j;
		while (++j < stack_b->tam)
			ft_m_rrb(stack_b);
		ft_m_pb(stack_a, stack_b);
		while (++i < stack_b->tam)
			ft_m_rb(stack_b);
	}
}

static void		ft_i_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack[0] > stack_b->stack[0])
		ft_m_pb(stack_a, stack_b);
	else if (stack_a->stack[0] < stack_b->stack[stack_b->tam - 1])
	{
		ft_m_pb(stack_a, stack_b);
		ft_m_rb(stack_b);
	}
	else
		ft_i_b_2(stack_a, stack_b);
}

static void		ft_1_step(t_stack *stack_a, t_stack *stack_b)
{
	t_fragment	fragment;
	int			i;
	int			j;

	i = -1;
	fragment.min = INT_MAX;
	fragment.max = INT_MIN;
	while (++i < stack_a->tam)
	{
		if (stack_a->stack[i] < fragment.min)
			fragment.min = stack_a->stack[i];
		if (stack_a->stack[i] > fragment.max)
			fragment.max = stack_a->stack[i];
	}
	fragment.tam = ((fragment.max - fragment.min) / 5) + 1;//tam++ for fit
	while (fragment.phase < 5)
	{
		i = ft_find_1(stack_a, fragment);
		j = ft_find_2(stack_a, fragment);
		while (i || j)
		{
			i = ft_find_1(stack_a, fragment);
			j = ft_find_2(stack_a, fragment);
			if (i > (stack_a->tam - j) || 0 == i)
				ft_up(stack_a, j);
			else
				ft_up(stack_a, i);
			ft_i_b(stack_a, stack_b);
		}
		fragment.phase += 1;
	}
	while (stack_b->tam != 0)
		ft_m_pa(stack_a, stack_b);
}

void			ft_order_100(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack *));
	stack_b->stack = (int *)ft_calloc(stack_a->tam, sizeof(int));
	ft_1_step(stack_a, stack_b);
	free(stack_b->stack);
	free(stack_b);
}