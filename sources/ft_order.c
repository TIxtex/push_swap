/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:43 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:44 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_find_2(t_st *stack, t_fragment *fragment)
{
	register int	i;

	i = stack->tam;
	while (--i >= 0)
		if (stack->stack[i] <= fragment->min + ((int) fragment->tam
				* (fragment->phase + 1)) && fragment->min
			+ ((int) fragment->tam * fragment->phase) <= stack->stack[i])
			return (i);
	return (-1);
}	

static int	ft_find_1(t_st *stack, t_fragment *fragment)
{
	register int	i;

	i = -1;
	while (++i < (int) stack->tam)
		if (stack->stack[i] <= fragment->min + ((int) fragment->tam
				* (fragment->phase + 1)) && fragment->min + ((int) fragment->tam
				* fragment->phase) <= stack->stack[i])
			return (i);
	return (-1);
}

static void	ft_2_step(t_sol *solution, t_st *st_a, t_st *st_b, t_fragment *f)
{
	register int			i;
	register int			j;
	register int			flag;

	if (st_a->tam > 100)
		flag = 14;
	else
		flag = 6;
	while (f->phase < flag && st_a->tam != 0)
	{
		i = ft_find_1(st_a, f);
		j = ft_find_2(st_a, f);
		while (((-1) != i || (-1) != j) && st_a->tam != 0)
		{
			if (i > ((int) st_a->tam - j))
				ft_up(solution, st_a, j, RA);
			else
				ft_up(solution, st_a, i, RA);
			ft_incrust_a_i_b_r(solution, st_a, st_b);
			i = ft_find_1(st_a, f);
			j = ft_find_2(st_a, f);
		}
		f->phase += 1;
	}
}

static void	ft_1_step(t_sol *solution, t_st *st_a, t_st *st_b)
{
	t_fragment		*fragment;
	register int	i;

	fragment = (t_fragment *)ft_calloc(1, sizeof(t_fragment));
	if (fragment == NULL)
		ft_puterror(ERR_5);
	i = -1;
	fragment->min = INT_MAX;
	fragment->max = INT_MIN;
	while (++i < (int) st_a->tam)
	{
		if (st_a->stack[i] < fragment->min)
			fragment->min = st_a->stack[i];
		if (st_a->stack[i] > fragment->max)
			fragment->max = st_a->stack[i];
	}
	if (st_a->tam > 100)
		fragment->tam = ((fragment->max - fragment->min) / 14) + 1;
	else
		fragment->tam = ((fragment->max - fragment->min) / 6) + 1;
	ft_2_step(solution, st_a, st_b, fragment);
	ft_colocate(solution, st_b);
	while (st_b->tam != 0)
		ft_m_p1(solution, st_a, st_b, PA);
	free(fragment);
}

void	ft_order_100(t_sol *solution, t_st *st_a)
{
	t_st	*st_b;

	st_b = ft_reserve_stack(st_a->tam);
	ft_1_step(solution, st_a, st_b);
	free(st_b->stack);
	free(st_b);
}
