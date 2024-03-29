/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:11:05 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:11:06 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del(void	*to_del)
{
	free(to_del);
	to_del = NULL;
}

int	main(int argc, char **argv)
{
	t_st	*st_a;
	t_sol	*solution;

	st_a = check_args(argc, argv);
	if (NULL == st_a)
		ft_puterror(ERR_0);
	have_dup(st_a);
	solution = (t_sol *)ft_lstnew_d("");
	if (NULL == solution)
		ft_puterror(ERR_0);
	core(st_a, solution);
	ft_lstclear((t_list **) &solution, NULL);
	ft_lstclear((t_list **) &st_a, NULL);
	return (ZERO);
}

