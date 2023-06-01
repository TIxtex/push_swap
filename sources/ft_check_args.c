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

static int	*inrange(char *str)
{
	register long	num;
	register size_t	i;
	int				*ok;

	num = ZERO;
	i = ZERO;
	if ('-' == str[num] || '+' == str[num])
		num++;
	while (ft_isdigit(str[num]) && '\0' != str[num])
		num++;
	if (12 < num)
		ft_puterror(ERR_2);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		ft_puterror(ERR_2);
	ok = (int *) malloc(sizeof(int *));
	if (NULL != ok)
		*ok = (int) num;
	else
		ft_puterror(ERR_0);
	return (ok);

}

static void	one_arg(t_st **stack, char *str)
{
	char	**split;
	t_st	*aux;
	size_t	i;

	split = ft_split(str, ' ');
	i = ZERO;
	while (NULL != split[i])
	{
		aux = ft_lstnew_d(inrange(split[i]));
		if (NULL != aux)
			ft_lstadd_back_d(stack ,aux);
		else
			ft_puterror(ERR_0);
		++i;
	}
	i = ZERO;
	while (NULL != split[i])
		free (split[i++]);
	free (split);
}

static void	parse_argv(char	*argv)
{
	register size_t	i;

	i = ZERO;
	while ('\0' != argv[i])
	{
		if ('\0' != argv[i] && (argv[i] == '-' || argv[i] != '+'))
			++i;
		if (!ft_isdigit(argv[i]))
			ft_puterror(ERR_3);
		while ('\0' != argv[i] && ft_isdigit(argv[i]))
			++i;
		while ('\0' != argv[i] && ' ' == argv[i])
			++i;
	}
}

t_st	*check_args(int argc, char **argv)
{
	register size_t	i;
	t_st			*stack;

	if (argc < 2)
		ft_puterror(ERR_1);
	i = 1;
	while (++i <= argc)
	{
		parse_argv(argv[i - 1]);
		one_arg(&stack, argv[i - 1]);
	}
	return (stack);
}
