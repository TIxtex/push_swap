/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:52 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:53 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_have_dup(t_st *stack)
{
	register size_t	x;
	register size_t	y;

	x = -1;
	while (++x < stack->tam)
	{
		y = x;
		while (++y < stack->tam)
			if (stack->stack[x] == stack->stack[y])
				ft_puterror(ERR_6);
	}
}

int	ft_isordered(t_st *stack)
{
	register int	i;
	register int	flag;

	i = -1;
	flag = 1;
	while (++i < (int) stack->tam - 1 && flag)
		if (stack->stack[i] > stack->stack[i + 1])
			flag = 0;
	if (flag)
		return (1);
	return (0);
}

int	ft_condition(t_st *st_a, t_st *st_b, int i)
{
	if (0 == i && st_a->stack[0] > st_b->stack[0]
		&& st_a->stack[0] < st_b->stack[st_b->tam - 1])
		return (0);
	else if ((int) st_b->tam == i)
		return (0);
	else if (0 != i && st_a->stack[0] > st_b->stack[i]
		&& st_a->stack[0] < st_b->stack[i - 1])
		return (0);
	else if (0 != i && st_b->stack[i] > st_b->stack[i - 1])
		if ((st_a->stack[0] > st_b->stack[i]
				&& st_a->stack[0] > st_b->stack[i - 1])
			|| (st_a->stack[0] < st_b->stack[i]
				&& st_a->stack[0] < st_b->stack[i - 1]))
			return (0);
	return (1);
}

void	ft_colocate(t_sol *solution, t_st *stack)
{
	register int	i;

	i = ZERO;
	while (i < (int) stack->tam - 1 && stack->stack[i] > stack->stack[i + 1])
		i++;
	if (i != (int) stack->tam - 1)
	{
		if (i < (int) stack->tam / 2)
			while (i-- > ZERO)
				ft_m_r(solution, stack, RB);
		else
			while (i++ < (int) stack->tam - 1)
				ft_m_rr(solution, stack, RRB);
	}
}

/*
void	ft_putstack(t_st *stack, char s)
{
	int		i;

	i = -1;
	ft_putstr_fd("\n||Stack -> ", 1);
	ft_putchar_fd(s, 1);
	ft_putstr_fd("\n||_ _ _ _ ||\n", 1);
	while (++i < stack->tam)
	{
		ft_putstr_fd("||\t", 1);
		ft_putnbr_fd(stack->stack[i], 1);
		ft_putstr_fd("\t||\n", 1);
	}
	ft_putstr_fd("||_ _ _ _ ||\n\n", 1);
}*/
