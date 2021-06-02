#include "push_swap.h"



static void	ft_incrust_a_i_b_r(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	while (stack_b->tam > i && stack_a->stack[0] < stack_b->stack[i])
		i++;
	while (stack_b->tam > j && stack_a->stack[0] > stack_b->stack[(stack_b->tam - 1) - j])
		j++;
	if (stack_b->tam == 0 || stack_a->stack[0] > stack_b->stack[0])
		ft_m_pb(stack_a, stack_b);
	else if (i <= j + 1)
	{
		j = i;
		while (i > 1)
		{
			ft_m_rb(stack_b);
			i--;
		}
		ft_m_pb(stack_a, stack_b);
		if (1 == i)
			ft_m_sb(stack_b);
		while (j-- > 1)
			ft_m_rrb(stack_b);
	}
	else
	{
		i = j;
		while (--j >= 0)
			ft_m_rrb(stack_b);
		ft_m_pb(stack_a, stack_b);
		ft_m_rb(stack_b);
		while (i-- > 0)
			ft_m_rb(stack_b);
	}
}

static void	ft_2_step(t_stack *stack_a, t_stack *stack_b, t_fragment *f)
{
	int			i;
	int			j;
	int			flag;

	if (stack_a->tam > 100)
		flag = 11;
	else
		flag = 5;
	while (f->phase < flag && stack_a->tam != 0)
	{
		i = ft_find_1(stack_a, f);
		j = ft_find_2(stack_a, f);
		while ((-1 != i && (-1) != j) && stack_a->tam != 0)
		{
			i = ft_find_1(stack_a, f);
			j = ft_find_2(stack_a, f);
			if (i > (stack_a->tam - j))
				ft_up(stack_a, j);
			else
				ft_up(stack_a, i);
			ft_incrust_a_i_b_r(stack_a, stack_b);
			ft_putstack(stack_b, 'B');
		}
		f->phase += 1;
	}
}

static void	ft_1_step(t_stack *stack_a, t_stack *stack_b)
{
	t_fragment	*fragment;
	int			i;

	fragment = (t_fragment *)ft_calloc(1, sizeof(t_fragment));
	if (fragment == NULL)
		ft_error("Error, fallo en reserva de memoria.\n");
	i = -1;
	fragment->min = INT_MAX;
	fragment->max = INT_MIN;
	while (++i < stack_a->tam)
	{
		if (stack_a->stack[i] < fragment->min)
			fragment->min = stack_a->stack[i];
		if (stack_a->stack[i] > fragment->max)
			fragment->max = stack_a->stack[i];
	}
	fragment->tam = ((fragment->max - fragment->min) / 5) + 1;
	ft_2_step(stack_a, stack_b, fragment);
	while (stack_b->tam != 0)
		ft_m_pa(stack_a, stack_b);
	free(fragment);
}

void	ft_order_100(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = ft_reserve_stack(stack_a->tam);
	ft_1_step(stack_a, stack_b);
	free(stack_b->stack);
	free(stack_b);
}
