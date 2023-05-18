/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:48 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:49 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_lst_pp(t_sol *solution)
{
	t_sol	*ini;

	ini = solution->next;
	ft_lstdelone_d(&ini, NULL);
	ft_lstdelone_d(&solution, NULL);
}

static void	ft_lst_switch(t_sol *solution, char *pair, char *todo, char *ignore)
{
	t_sol	*ini;

	ini = solution;
	solution = solution->next;
	while (!ft_strncmp(ignore, solution->content, ft_strlen(ignore)))
		solution = solution->next;
	if (!ft_strncmp(pair, solution->content, ft_strlen(pair)))
	{
		ft_lstdelone_d(&solution, NULL);
		ini->content = todo;
	}
}

void		ft_optimice_sol(t_sol *solution)
{
	while (NULL != solution->next)
	{
		if (!ft_strncmp(SA, solution->content, ft_strlen(SA)))
			ft_lst_switch(solution, SB, SS, SA);
		else if (!ft_strncmp(SB, solution->content, ft_strlen(SB)))
			ft_lst_switch(solution, SA, SS, SB);
		else if (!ft_strncmp(RA, solution->content, ft_strlen(RA)))
			ft_lst_switch(solution, RB, RR, RA);
		else if (!ft_strncmp(RB, solution->content, ft_strlen(RB)))
			ft_lst_switch(solution, RA, RR, RB);
		else if (!ft_strncmp(RRA, solution->content, ft_strlen(RRA)))
			ft_lst_switch(solution, RRB, RRR, RRA);
		else if (!ft_strncmp(RRB, solution->content, ft_strlen(RRB)))
			ft_lst_switch(solution, RRA, RRR, RRB);
		else if (!ft_strncmp(PB, solution->content, ft_strlen(PB)))
		{
			if (!ft_strncmp(PA, solution->next->content, ft_strlen(PA)))
			{
				solution = solution->prev;
				ft_lst_pp(solution->next);
				continue;
			}
		}		
		solution = solution->next;
	}
}
