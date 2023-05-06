/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:31 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:32 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_inrange(t_st *stack, char *str, int i)
{
	register long	num;

	num = (long) ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		ft_puterror(ERR_2);
	else if (ZERO == num && !ft_strncmp(str, "-", 2))
		ft_puterror(ERR_X);
	else
		stack->stack[i] = (int)num;

}

t_st	*ft_reserve_stack(size_t tam)
{
	t_st	*stack;

	stack = (t_st *) malloc(TRUE * sizeof(t_st));
	if (NULL != stack)
	{
		stack->stack = (int *) ft_calloc(tam + 1, sizeof(int));
		if (NULL == stack->stack)
			stack = (t_st *) stack->stack;
	}
	return (stack);
}

static t_st	*ft_onearg(char *str)
{
	t_st	*stack;
	char	**split;
	size_t	i;

	i = -1;
	while ('\0' != str[++i])
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i] && str[i] != '-'))
			ft_puterror(ERR_3);
	split = ft_split(str, ' ');
	i = ZERO;
	while (NULL != split[i])
		i++;
	stack = ft_reserve_stack(i);
	i = -1;
	while (NULL != split[++i])
		ft_inrange(stack, split[i], i);
	stack->tam = i;
	i = ZERO;
	while (i < stack->tam)
		free (split[i++]);
	free (split);
	return (stack);
}

t_st	*ft_check_args(int argc, char **argv)
{
	register size_t	x;
	register size_t	y;
	t_st			*stack;

	if (argc < 2)
		ft_puterror(ERR_1);
	if (argc == 2)
		stack = ft_onearg(argv[1]);
	else
	{
		x = -1;
		stack = ft_reserve_stack(argc - 1);
		while (++x < (size_t) argc - 1) /*recorre argumentos*/
		{
			y = -1;
			while (argv[x + 1][++y])
				if (!ft_isdigit(argv[x + 1][y]) && (0 != y || argv[x + 1][0] != '-'))
					ft_puterror(ERR_3);
			ft_inrange(stack, argv[x + 1], x);
		}
		stack->tam = argc - 1;
	}
	return (stack);
}
