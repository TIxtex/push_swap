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
	size_t	x;
	size_t	y;

	x = ZERO;
	y = ZERO;
	while (a->tam > x && b->stack[0] > a->stack[x])
		x++;
	while (a->tam > y && b->stack[0] < a->stack[(a->tam - 1) - y])
		y++;
	if (x <= y + 1)
		incrust_top_pa(solution, a, b, x);
	else
		incrust_button_pa(solution, a, b, y);
}

static void	order_3(t_sol *solution, t_st *stack)
{
	int	*x;

	x = stack->stack;
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

static void	order_5(t_sol *solution, t_st *st_a)
{
	t_st	*st_b;

	st_b = reserve_stack(2);
	while (st_a->tam > 3)
		m_p1(solution, st_b, st_a, PB);
	order_3(solution, st_a);
	while (st_b->tam > ZERO)
		incrust_b_i_a(solution, st_a, st_b);
	free(st_b->stack);
	free(st_b);
	while (st_a->stack[0] > st_a->stack[st_a->tam - 1])
		m_rr(solution, st_a, RRA);
}

void	core(t_st *st_a, t_sol *solution)
{
	if (ZERO == isordered(st_a))
	{
		if (2 == st_a->tam && st_a->stack[0] > st_a->stack[1])
			m_s(solution, st_a, SA);
		else if (3 == st_a->tam)
			order_3(solution, st_a);
		else if (6 > st_a->tam && 3 < st_a->tam)
			order_5(solution, st_a);
		else if (5 < st_a->tam)
			order_100(solution, st_a);
		while (NULL != solution)
		{
			ft_putstr_fd(solution->content, STDOUT_FILENO);
			solution = solution->next;
		}
	}
}
