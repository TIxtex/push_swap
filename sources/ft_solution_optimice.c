/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_optimice.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:45 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:46 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void 	ft_lst_ss()
{

}

void	ft_optimice_sol_s(t_sol *solution)
{
	t_sol	*aux;

	while (NULL != solution->next)
	{
		if (&SA == &solution->content)
		{
		
		}
		else if (&SB == &solution->content)
		{
		
		}
		solution = solution->next;
	}

}

void	ft_optimice_sol_1(t_sol *solution, char *find, char put, int num)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->str, find, solution->size);
	if (NULL != i)
	{
		i[2] = put;
		i[3] = '\0';
		aux = ft_strjoin(solution->str, &i[7]);
		solution->size -= num;
		free(solution->str);
		solution->str = aux;
		ft_optimice_sol_1(solution, find, put, num);
	}
}

void	ft_optimice_sol_2(t_sol *solution, char *find, int num)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->str, find, solution->size);
	if (NULL != i)
	{
		i[0] = '\0';
		aux = ft_strjoin(solution->str, &i[6]);
		solution->size -= num;
		free(solution->str);
		solution->str = aux;
		ft_optimice_sol_2(solution, find, num);
	}
}

void	ft_optimice_sol_3(t_sol *solution, char *find, char put, int num)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->str, find, solution->size);
	if (NULL != i && i[-1] != 'r')
	{
		i[2] = put;
		i[3] = '\0';
		aux = ft_strjoin(solution->str, &i[6]);
		solution->size -= num;
		free(solution->str);
		solution->str = aux;
		ft_optimice_sol_3(solution, find, put, num);
	}
}
