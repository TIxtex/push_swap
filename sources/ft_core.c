/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:34 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:35 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	incrust_b_i_a(t_sol *solution, t_st *a, t_st *b)
{
	int		tam;
	size_t	x;
	size_t	y;
	t_st	*aux;

	x = ZERO;
	y = ZERO;
	tam = ft_lstsize(a) / 2 + 1;
	aux = a;
	while (tam > x && b->content > a->content)
	{
		x++;
		a = a->next;
	}
	a = ft_lstlast(aux);
	while (tam > y && b->content < a->content)
	{
		y++;
		a = a->prev;
	}
	if (x <= y + 1)
		incrust_top_pa(solution, aux, b, x);
	else
		incrust_button_pa(solution, aux, b, y);
}

static void	order_3(t_sol *solution, t_st *stack)
{
	int	*x;

	x[0] = stack->content;
	x[1] = stack->next->content;
	x[2] = stack->next->next->content;
	if (x[1] > x[2])
	{
		if (x[0] < x[1] && x[0] > x[2])
			m_rr(solution, stack, RRA);
		else
		{
			m_s(solution, stack, SA);
			if (x[0] > x[1])
				m_r(solution, stack, RA);
			else
				m_rr(solution, stack, RRA);
		}
	}
	else if (x[0] > x[2])
		m_r(solution, stack, RA);
	else if (x[0] < x[2] && x[1] < x[0])
		m_s(solution, stack, SA);
}

static void	order_5(t_sol *solution, t_st *st_a, int tam)
{
	t_st	*st_b;

	while (tam > 3)
		m_p1(solution, st_b, st_a, PB);
	order_3(solution, st_a);
	while (ft_lstsize(st_b) > ZERO)
		incrust_b_i_a(solution, st_a, st_b);
	ft_lstclear(st_b, NULL);
	st_b = ft_lstlast(st_a);
	while (st_a->content > st_b->content)
		m_rr(solution, st_a, RRA);
}

void	core(t_st *st_a, t_sol *solution)
{
	int	tam;

	tam = ft_lstsize(st_a);
	if (ZERO == isordered(st_a))
	{
		if (2 == tam && (int) st_a->content > (int) st_a->next->content)
			m_s(solution, st_a, SA);
		else if (3 == tam)
			order_3(solution, st_a);
		else if (6 > tam && 3 < tam)
			order_5(solution, st_a, tam);
		else if (5 < tam)
			order_100(solution, st_a);
		while (NULL != solution)
		{
			ft_putstr_fd(solution->content, STDOUT_FILENO);
			solution = solution->next;
		}
	}
}
