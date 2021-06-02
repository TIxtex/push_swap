#include "push_swap.h"

int	ft_find_2(t_stack *stack, t_fragment *fragment)
{
	int			i;

	i = stack->tam;
	while (--i >= 0)
		if (stack->stack[i] < fragment->min + (fragment->tam
				* (fragment->phase + 1)) && fragment->min
			+ (fragment->tam * fragment->phase) < stack->stack[i])
			return (i);
	return (-1);
}	

int	ft_find_1(t_stack *stack, t_fragment *fragment)
{
	int			i;

	i = -1;
	while (++i < stack->tam)
		if (stack->stack[i] <= fragment->min + (fragment->tam
				* (fragment->phase + 1)) && fragment->min + (fragment->tam
				* fragment->phase) <= stack->stack[i])
			return (i);
	return (-1);
}
