/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:40 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:41 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_incrust_top(t_sol *solution, t_st *st_a, t_st *st_b, int num)
{
	while (num > 1)
	{
		ft_m_r(solution, st_b, RB);
		num--;
	}
	ft_m_p1(solution, st_b, st_a, PB);
	if (1 == num)
		ft_m_s(solution, st_b, SB);
}

static void	ft_incrust_button(t_sol *solution, t_st *st_a, t_st *st_b, int num)
{
	while (--num >= 0)
		ft_m_rr(solution, st_b, RRB);
	ft_m_p1(solution, st_b, st_a, PB);
}

void	ft_incrust_top_pa(t_sol *solution, t_st *st_a, t_st *st_b, int num)
{
	register int	j;

	j = num;
	while (num > 1)
	{
		ft_m_r(solution, st_a, RA);
		num--;
	}
	ft_m_p1(solution, st_a, st_b, PA);
	if (j > 0)
		ft_m_s(solution, st_a, SA);
	while (j > 1)
	{
		ft_m_rr(solution, st_a, RRA);
		j--;
	}
}

void	ft_incrust_button_pa(t_sol *solution, t_st *st_a, t_st *st_b, int num)
{
	register int	i;

	i = num;
	while (num > 0)
	{
		ft_m_rr(solution, st_a, RRA);
		num--;
	}
	ft_m_p1(solution, st_a, st_b, PA);
	ft_m_r(solution, st_a, RA);
	while (i > 0)
	{
		ft_m_r(solution, st_a, RA);
		i--;
	}
}

void	ft_incrust_a_i_b_r(t_sol *solution, t_st *st_a, t_st *st_b)
{
	register int	i;
	register int	j;

	i = 0;
	while (ft_condition(st_a, st_b, i) && st_b->tam != 0)
		i++;
	j = st_b->tam - i;
	if (st_b->tam == 0)
		ft_m_p1(solution, st_b, st_a, PB);
	else if (i <= j + 1)
		ft_incrust_top(solution, st_a, st_b, i);
	else
		ft_incrust_button(solution, st_a, st_b, j);
}
