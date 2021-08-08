#include "push_swap.h"
#include <stdio.h>

static void	ft_inrange(t_stack *stack, char *str, int i)
{
	double	num;

	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		ft_error("Error, excedido limite de enteros.\n");
	else
		stack->stack[i] = (int)num;
}

static t_stack	*ft_onearg(char *str)
{
	char	**split;
	size_t	i;
	t_stack	*stack;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != '-' && !ft_isspace(str[i]))
			ft_error("Error, caracteres especiales\n");
	split = ft_split(str, ' ');
	i = 0;
	while (split[i] != 0)
		i++;
	stack = ft_reserve_stack(i);
	i = -1;
	while (split[++i] != 0)
		ft_inrange(stack, split[i], i);
	stack->tam = i;
	i = 0;
	while (i < (size_t)stack->tam)
		free (split[i++]);
	free (split);
	return (stack);
}

t_stack	*ft_check_arg(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		j;

	if (argc < 2)
		ft_error("");
	if (argc == 2)
		stack = ft_onearg(argv[1]);
	else
	{
		i = -1;
		stack = ft_reserve_stack(argc - 1);
		while (++i < argc - 1)
		{
			j = -1;
			while (argv[i + 1][++j])
				if (!ft_isdigit(argv[i + 1][j]) && (0 != j
					|| argv[i + 1][0] != '-'))
					ft_error("Error, caracteres especiales.\n");
			ft_inrange(stack, argv[i + 1], i);
		}
		stack->tam = argc - 1;
	}
	return (stack);
}
