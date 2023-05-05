#include "../push_swap.h"

void	ft_m_s(t_sol *solution, t_st *stack, char *add)
{
	int		aux;
	t_list	*new;

	aux = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = aux;
	new = ft_lstnew((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back(&solution, new);
}

void	ft_m_r(t_sol *solution, t_st *stack, char *add)
{
	int		aux;
	size_t	i;
	t_list	*new;

	aux = stack->stack[0];
	i = -1;
	while (++i < stack->tam - 1)
		stack->stack[i] = stack->stack[i + 1];
	stack->stack[stack->tam - 1] = aux;
	new = ft_lstnew((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back(&solution, new);
}

void	ft_m_rr(t_sol *solution, t_st *stack, char *add)
{
	int	aux;
	int	i;
	t_list	*new;

	aux = stack->stack[stack->tam - 1];
	i = stack->tam - 1;
	while (--i >= 0)
		stack->stack[i + 1] = stack->stack[i];
	stack->stack[0] = aux;
	new = ft_lstnew((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back(&solution, new);
}

void	ft_m_p1(t_sol *solution, t_st *stack_1, t_st *stack_2, char *add)
{
	int	i;
	t_list	*new;

	i = stack_1->tam;
	while (--i >= 0)
		stack_1->stack[i + 1] = stack_1->stack[i];
	stack_1->stack[0] = stack_2->stack[0];
	i = -1;
	while ((size_t) ++i < stack_2->tam - 1)
		stack_2->stack[i] = stack_2->stack[i + 1];
	new = ft_lstnew((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back(&solution, new);
	stack_1->tam++;
	stack_2->tam--;
}

void	ft_up(t_sol *solution, t_st *stack, int num, char *add)
{
	if ((size_t) num > stack->tam / 2)
	{
		while ((size_t) num++ < stack->tam)
		{
			if (!ft_strncmp(add, RA, 3))
				ft_m_rr(solution, stack, RRA);
			else /*(RB == add)*/
				ft_m_rr(solution, stack, RRB);
		}
	}
	else
		while (num-- > 0)
			ft_m_r(solution, stack, add);
}
