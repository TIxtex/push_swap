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

void	have_dup(t_st *stack)
{
	t_st	*aux;

	while (NULL != stack->next)
	{
		aux = stack;
		while (NULL != stack->next)
		{
			if (aux->content == stack->next->content)
				ft_puterror(ERR_6);
			stack = stack->next;
		}
		stack = stack->next;
	}
}

int	isordered(t_st *stack)
{
	while (NULL != stack->next)
	{
		if (stack->content > stack->next->content)
			return (EXIT_FAILURE);
		stack = stack->next;
	}
	return (EXIT_SUCCESS);
}

int	condition(t_st *st_a, t_st *st_b, int i)
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

void	colocate(t_sol *solution, t_st *stack)
{
	register int	i;
	register int	tam;
	t_st			*aux;

	i = ZERO;
	tam = ft_lstsize(stack);
	aux = stack;
	while (i < tam - 1 && aux->content > aux->next->content)
	{
		i++;
		aux = aux->next;
	}
	if (i != tam - 1)
	{
		if (i < tam / 2)
			while (i-- > ZERO)
				m_r(solution, stack, RB);
		else
			while (i++ < tam - 1)
				m_rr(solution, stack, RRB);
	}
}

void	copy_stack(t_st *st_source, t_st **st_destiny)
{
	register int	i;
	t_st			*aux;

	while (NULL != st_source)
	{
		aux = ft_lstnew_d(st_source->content);
		if (NULL != aux)
			ft_lstadd_back_d(st_destiny, &aux);
		else
			ft_puterror(ERR_0);
		st_source = st_source->next;
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
