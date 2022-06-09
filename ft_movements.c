#include "push_swap.h"

void	ft_m_s(t_smart_str *solution, t_stack *stack, char *add)
{
	int	aux;

	aux = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = aux;
	ft_smart_stradd(solution, add);
}

void	ft_m_r(t_smart_str *solution, t_stack *stack, char *add)
{
	int	aux;
	int	i;

	aux = stack->stack[0];
	i = -1;
	while (++i < stack->tam - 1)
		stack->stack[i] = stack->stack[i + 1];
	stack->stack[stack->tam - 1] = aux;
	ft_smart_stradd(solution, add);
}

void	ft_m_rr(t_smart_str *solution, t_stack *stack, char *add)
{
	int	aux;
	int	i;

	aux = stack->stack[stack->tam - 1];
	i = stack->tam - 1;
	while (--i >= 0)
		stack->stack[i + 1] = stack->stack[i];
	stack->stack[0] = aux;
	ft_smart_stradd(solution, add);
}

void	ft_m_p1(t_smart_str *solution, t_stack *stack_1, t_stack *stack_2, char *add)
{
	int	i;

	i = stack_1->tam;
	while (--i >= 0)
		stack_1->stack[i + 1] = stack_1->stack[i];
	stack_1->stack[0] = stack_2->stack[0];
	i = -1;
	while (++i < stack_2->tam - 1)
		stack_2->stack[i] = stack_2->stack[i + 1];
	ft_smart_stradd(solution, add);
	stack_1->tam++;
	stack_2->tam--;
}

void	ft_up(t_smart_str *solution, t_stack *stack, int num, char *add)
{
	char	*print;

	if (num > stack->tam / 2)
	{
		while (num++ < stack->tam)
		{
			print = ft_strjoin("r", add);
			ft_m_rr(solution, stack, print);
			free(print);
		}
	}
	else
		while (num-- > 0)
			ft_m_r(solution, stack, add);
}
