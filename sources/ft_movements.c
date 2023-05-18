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

void	ft_m_s(t_sol *solution, t_st *stack, char *add)
{
	int		aux;
	t_sol	*new;

	aux = stack->stack[ZERO];
	stack->stack[ZERO] = stack->stack[1];
	stack->stack[1] = aux;
	new = ft_lstnew_d((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back_d(&solution, &new);
}

void	ft_m_r(t_sol *solution, t_st *stack, char *add)
{
	int		aux;
	size_t	i;
	t_sol	*new;

	aux = stack->stack[ZERO];
	i = -1;
	while (++i < stack->tam - 1)
		stack->stack[i] = stack->stack[i + 1];
	stack->stack[stack->tam - 1] = aux;
	new = ft_lstnew_d((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back_d(&solution, &new);
}

void	ft_m_rr(t_sol *solution, t_st *stack, char *add)
{
	int	aux;
	int	i;
	t_sol	*new;

	aux = stack->stack[stack->tam - 1];
	i = stack->tam - 1;
	while (--i >= ZERO)
		stack->stack[i + 1] = stack->stack[i];
	stack->stack[ZERO] = aux;
	new = ft_lstnew_d((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back_d(&solution, &new);
}

void	ft_m_p1(t_sol *solution, t_st *stack_1, t_st *stack_2, char *add)
{
	int	i;
	t_sol	*new;

	i = stack_1->tam;
	while (--i >= ZERO)
		stack_1->stack[i + 1] = stack_1->stack[i];
	stack_1->stack[0] = stack_2->stack[ZERO];
	i = -1;
	while ((size_t) ++i < stack_2->tam - 1)
		stack_2->stack[i] = stack_2->stack[i + 1];
	new = ft_lstnew_d((void *) add);
	if (NULL == new)
		ft_puterror(ERR_4);
	ft_lstadd_back_d(&solution, &new);
	stack_1->tam++;
	stack_2->tam--;
}

void	ft_up(t_sol *solution, t_st *stack, int num, char *add)
{
	if ((size_t) num > stack->tam / 2)
	{
		while ((size_t) num++ < stack->tam)
		{
			if (!ft_strncmp(add, RA, 3))
				ft_m_rr(solution, stack, RRA);
			else /*(RB == add)*/
				ft_m_rr(solution, stack, RRB);
		}
	}
	else
		while (num-- > 0)
			ft_m_r(solution, stack, add);
}
