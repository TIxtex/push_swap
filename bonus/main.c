/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:11:21 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:11:22 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_isordered2(t_st *stack)
{
	size_t	i;
	int	flag;

	i = -1;
	flag = 1;
	while (++i < stack->tam - 1 && flag)
		if (stack->stack[i] > stack->stack[i + 1])
			flag = ZERO;
	if (flag == ZERO)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
}

static void 	ft_make_move(char *move, t_st *st_a, t_st *st_b)
{
	if (ft_strncmp(move, "sa", 2) == 0)
		ft_mc_s(st_a);
	else if (ft_strncmp(move, "sb", 2) == 0)
		ft_mc_s(st_b);
	else if (ft_strncmp(move, "ss", 2) == 0)
		ft_mc_ss(st_a, st_b);
	else if (ft_strncmp(move, "pa", 2) == 0)
		ft_mc_pa(st_a, st_b);
	else if (ft_strncmp(move, "pb", 2) == 0)
		ft_mc_pb(st_a, st_b);
	else if (ft_strncmp(move, "ra", 2) == 0)
		ft_mc_r(st_a);
	else if (ft_strncmp(move, "rb", 2) == 0)
		ft_mc_r(st_b);
	else if (ft_strncmp(move, "rra", 3) == 0)
		ft_mc_rr(st_a);
	else if (ft_strncmp(move, "rrb", 3) == 0)
		ft_mc_rr(st_b);
	else if (ft_strncmp(move, "rrr", 3) == 0)
		ft_mc_rrr(st_a, st_b);
	else if (ft_strncmp(move, "rr", 2) == 0)
		ft_mc_rr2(st_a, st_b);
}

int	main(int argc, char **argv)
{
	t_st	*st_a;
	t_st	*st_b;
	char	*line;

	st_a = ft_check_args(argc, argv);
	ft_have_dup(st_a);
	st_b = ft_reserve_stack(st_a->tam);
	while (get_next_line(0, &line) > 0)
		ft_make_move(line, st_a, st_b);
	ft_isordered2(st_a);
	free(st_b->stack);
	free(st_b);
	free(st_a->stack);
	free(st_a);
	return (42);
}
