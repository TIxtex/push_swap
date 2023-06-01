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

	i = 1;
	while (NULL != stack->next)
	{
		++i;
		stack = stack->next;
	}
	while (NULL != stack)
	{
		--i;
		if (stack->content <= fragment->min + ((int) fragment->tam
				* (fragment->phase + 1)) && fragment->min
				+ ((int) fragment->tam * fragment->phase) <= stack->content)
			return (i);
		stack = stack->prev;
	}
	return (-1);
}	

static int	find_1(t_st *stack, t_fragment *fragment)
{
	register int	i;

	i = -1;
	while (NULL != stack)
	{
		++i;
		if (stack->content <= fragment->min + ((int) fragment->tam 
				* (fragment->phase + 1)) && fragment->min
				+ ((int) fragment->tam * fragment->phase) <= stack->content)
			return (i);
		stack = stack->next;
	}
	return (-1);
}

static void	step_2(t_sol *solution, t_st *st_a, t_st *st_b, t_fragment *f)
{
	register int			i;
	register int			j;
	register int			flag;
	register int			tam;

	tam = ft_lstsize(st_a);
	if (tam > 100)
		flag = 14;
	else
		flag = 6;
	while (f->phase < flag && tam != 0)
	{
		i = find_1(st_a, f);
		j = find_2(st_a, f);
		while (((-1) != i || (-1) != j) && tam != 0)
		{
			if (i > (tam - j))
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
	t_st			*aux;

	fragment = (t_fragment *) ft_calloc(1, sizeof(t_fragment));
	if (fragment == NULL)
		ft_puterror(ERR_5);
	fragment->min = INT_MAX;
	fragment->max = INT_MIN;
	aux = st_a;
	while (NULL != aux)
	{
		if (aux->content < fragment->min)
			fragment->min = aux->content;
		if (st_a->content > fragment->max)
			fragment->max = aux->content;
		aux = aux->next;
	}
	fragment->tam = ((fragment->max - fragment->min) / iterator) + 1;
	step_2(solution, st_a, st_b, fragment);
	colocate(solution, st_b);
	while (NULL != st_b)
		m_p1(solution, &st_a, &st_b, PA);
	free(fragment);
}

void	order_100(t_sol *solution, t_st *st_a)
{
	t_st	*st_b;
	t_st	*st_aux;
	size_t	i;
/* 	int		solution_tam; */

	if (ft_lstsize(st_a) > 100)
		i = 14;
	else
		i = 6;
/*	while (++i <= st_a->tam * 5)
	{*/
		copy_stack(st_a, &st_aux);
		step_1(solution, st_aux, st_b, i);
		ft_lstclear(st_aux, NULL);
		ft_lstclear(st_b, NULL);
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
