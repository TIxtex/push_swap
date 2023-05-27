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

static int	find_2(t_st *stack, t_fragment *fragment)
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

static int	find_1(t_st *stack, t_fragment *fragment)
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

static void	step_2(t_sol *solution, t_st *st_a, t_st *st_b, t_fragment *f)
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
		i = find_1(st_a, f);
		j = find_2(st_a, f);
		while (((-1) != i || (-1) != j) && st_a->tam != 0)
		{
			if (i > ((int) st_a->tam - j))
				m_up(solution, st_a, j, RA);
			else
				m_up(solution, st_a, i, RA);
			incrust_a_i_b_r(solution, st_a, st_b);
			i = find_1(st_a, f);
			j = find_2(st_a, f);
		}
		f->phase += 1;
	}
}

static void	step_1(t_sol *solution, t_st *st_a, t_st *st_b, size_t iterator)
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
	fragment->tam = ((fragment->max - fragment->min) / iterator) + 1;
	step_2(solution, st_a, st_b, fragment);
	colocate(solution, st_b);
	while (st_b->tam != 0)
		m_p1(solution, st_a, st_b, PA);
	free(fragment);
}

void	order_100(t_sol *solution, t_st *st_a)
{
	t_st	*st_b;
	t_st	*st_aux;
	size_t	i;
/* 	int		solution_tam; */

	i = 6;
/*	while (++i <= st_a->tam * 5)
	{*/
		st_b = reserve_stack(st_a->tam);
		st_aux = reserve_stack(st_a->tam);
		copy_stack(st_a, &st_aux);
		step_1(solution, st_aux, st_b, i);
		free(st_aux->stack);
		free(st_aux);
		free(st_b->stack);
		free(st_b);
		optimice_sol(solution);
/* 		solution_tam = ft_lstsize((t_list *) solution);
		ft_putnbr_fd(solution_tam, 1);ft_putstr_fd("<- tam	", 1);
		ft_putnbr_fd(i, 1);ft_putendl_fd("<- i", 1);
		ft_lstclear((t_list **) &solution, NULL);
		solution = (t_sol *) ft_lstnew_d("");
		if (NULL == solution)
			ft_puterror(ERR_0); */
/*	}*/
	
}
