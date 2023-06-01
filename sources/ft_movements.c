/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:37 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:38 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	m_s(t_sol *solution, t_st *stack, char *add)
{
	int		aux;
	t_sol	*new;

	aux = stack->content;
	stack->content = stack->next->content;
	stack->next->content = aux;
	new = ft_lstnew_d((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back_d(&solution, &new);
}

void	m_r(t_sol *solution, t_st *stack, char *add)
{
	int		aux;
	t_sol	*new;

	aux = stack->content;
	while (NULL != stack->next)
		stack->content = stack->next;
	stack->content = aux;
	new = ft_lstnew_d((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back_d(&solution, &new);
}

void	m_rr(t_sol *solution, t_st *stack, char *add)
{
	int	aux;
	t_st	*last;
	t_sol	*new;

	last = ft_lstlast(stack);
	aux = last->content;
	while (NULL != last->prev)
		last->content = last->prev->content;
	last->content = aux;
	new = ft_lstnew_d((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back_d(&solution, &new);
}

void	m_p1(t_sol *solution, t_st **stack_1, t_st **stack_2, char *add)
{
	t_sol	*new;
	t_st	*aux;

	aux = *stack_2;
	if (NULL != (*stack_2)->next)
	{
		*stack_2 = (*stack_2)->next;
		(*stack_2)->prev = NULL;
	}
	else
		*stack_2 = NULL;
	if (NULL != *stack_1)
		ft_lstadd_front_d(stack_1, aux);
	else
		*stack_1 = aux;
	new = ft_lstnew_d((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back_d(&solution, &new);
}

void	m_up(t_sol *solution, t_st *stack, int num, char *add)
{
	int	tam;

	tam = ft_lstsize(stack);
	if (num > tam / 2)
	{
		while (num++ < tam)
		{
			if (!ft_strncmp(add, RA, 3))
				m_rr(solution, stack, RRA);
			else /*(RB == add)*/
				m_rr(solution, stack, RRB);
		}
	}
	else
		while (num-- > 0)
			m_r(solution, stack, add);
}
