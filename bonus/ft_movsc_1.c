/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movsc_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:11:18 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:11:19 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_mc_ss(t_st *st_a, t_st *st_b)
{
	ft_mc_s(st_a);
	ft_mc_s(st_b);
}

void	ft_mc_rr2(t_st *st_a, t_st *st_b)
{
	ft_mc_r(st_a);
	ft_mc_r(st_b);
}

void	ft_mc_rrr(t_st *st_a, t_st *st_b)
{
	ft_mc_rr(st_a);
	ft_mc_rr(st_b);
}

void	ft_c_up(t_st *stack, int num)
{
	if (num > (int) stack->tam / 2)
		while (num++ < (int) stack->tam)
			ft_mc_rr(stack);
	else
		while (num-- > ZERO)
			ft_mc_r(stack);
}
