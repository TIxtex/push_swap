#include "checker.h"

void	ft_mc_s(t_st *stack)
{
	int	aux;

	aux = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = aux;
}

void	ft_mc_r(t_st *stack)
{
	int	aux;
	size_t	i;

	aux = stack->stack[0];
	i = -1;
	while (++i < stack->tam - 1)
		stack->stack[i] = stack->stack[i + 1];
	stack->stack[stack->tam - 1] = aux;
}

void	ft_mc_rr(t_st *stack)
{
	int	aux;
	int	i;

	aux = stack->stack[stack->tam - 1];
	i = stack->tam - 1;
	while (--i >= 0)
		stack->stack[i + 1] = stack->stack[i];
	stack->stack[0] = aux;
}

void	ft_mc_pa(t_st *st_a, t_st *st_b)
{
	int	i;

	i = st_a->tam;
	while (--i >= 0)
		st_a->stack[i + 1] = st_a->stack[i];
	st_a->stack[0] = st_b->stack[0];
	i = -1;
	while (++i < (int) st_b->tam - 1)
		st_b->stack[i] = st_b->stack[i + 1];
	st_a->tam++;
	st_b->tam--;
}

void	ft_mc_pb(t_st *st_a, t_st *st_b)
{
	int	i;

	i = st_b->tam;
	while (--i >= 0)
		st_b->stack[i + 1] = st_b->stack[i];
	st_b->stack[0] = st_a->stack[0];
	i = -1;
	while (++i < (int) st_a->tam - 1)
		st_a->stack[i] = st_a->stack[i + 1];
	st_a->tam--;
	st_b->tam++;
}
