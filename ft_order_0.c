#include "push_swap.h"

static int	ft_find_2(t_stack *stack, t_fragment *fragment)
{
	int	i;

	i = stack->tam;
	while (--i >= 0)
		if (stack->stack[i] <= fragment->min + (fragment->tam
				* (fragment->phase + 1)) && fragment->min
			+ (fragment->tam * fragment->phase) <= stack->stack[i])
			return (i);
	return (-1);
}	

static int	ft_find_1(t_stack *stack, t_fragment *fragment)
{
	int	i;

	i = -1;
	while (++i < stack->tam)
		if (stack->stack[i] <= fragment->min + (fragment->tam
				* (fragment->phase + 1)) && fragment->min + (fragment->tam
				* fragment->phase) <= stack->stack[i])
			return (i);
	return (-1);
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
		while (((-1) != i || (-1) != j) && stack_a->tam != 0)
		{
			if (i > (stack_a->tam - j))
				ft_up(stack_a, j);
			else
				ft_up(stack_a, i);
			ft_incrust_a_i_b_r(stack_a, stack_b);
			ft_putstack(stack_a, 'a');
			ft_putstack(stack_b, 'b');
			i = ft_find_1(stack_a, f);
			j = ft_find_2(stack_a, f);
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
