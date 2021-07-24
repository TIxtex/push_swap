#include "push_swap.h"

t_stack	*ft_onearg(char *str)
{
	char	**split;
	size_t	i;
	double	num;
	t_stack	*stack;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && (0 != str[i] || str[i] != '-')
			&& !ft_isspace(str[i]))
			ft_error("Error, caracteres especiales\n");
	split = ft_split(str, ' ');
	i = 0;
	while (split[i] != 0)
		i++;
	stack = ft_reserve_stack(i);
	i = 0;
	while (split[i] != 0)
	{
		num = ft_atoi(split[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error("Error, excedido limite de enteros.\n");
		else
			stack->stack[i] = (int)num;
		i++;
	}
	stack->tam = i;
	while (--i <= 0)
		free(split[i]);
	free (split);
	return (stack);
}

t_stack	*ft_check_arg(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		j;
	double	num;

	if (argc < 2)
		ft_error("");
	if (argc == 2)
		stack = ft_onearg(argv[1]);
	else
	{
		i = 0;
		stack = ft_reserve_stack(argc - 1);
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
				if (!ft_isdigit(argv[i][j]) && (0 != j || argv[i][0] != '-'))
					ft_error("Error, caracteres especiales.\n");
			num = ft_atoi(argv[i]);
			if (num < INT_MIN || num > INT_MAX)
				ft_error("Error, excedido limite de enteros.\n");
			else
				stack->stack[i - 1] = (int)num;
		}
		stack->tam = argc - 1;
	}
	ft_have_dup(stack);
	return (stack);
}