#include "push_swap.h"

static void	ft_inrange(t_stack *stack, char *str, int i)
{
	long	num;

	num = (long)ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		ft_puterror("excedido limite de integer.\n");
	else
		stack->stack[i] = (int)num;
}

t_stack	*ft_reserve_stack(size_t tam)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(TRUE, sizeof(t_stack));
	if (NULL != stack)
	{
		stack->stack = (int *)ft_calloc(tam + 1, sizeof(int));
		if (NULL == stack->stack)
			stack = (t_stack *) stack->stack;
	}
	return (stack);
}

static t_stack	*ft_onearg(char *str)
{
	t_stack	*stack;
	char	**split;
	size_t	i;

	i = -1;
	while ('\0' != str[++i])
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i] && str[i] != '-'))
			ft_puterror("caracteres especiales\n");
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

t_stack	*ft_check_args(int argc, char **argv)
{
	t_stack	*stack;
	size_t	x;
	size_t	y;

	if (argc < 2)
		ft_puterror("Introduce argumentos");
	if (argc == 2)
		stack = ft_onearg(argv[1]);
	else
	{
		x = -1;
		stack = ft_reserve_stack(argc - 1);
		while (++x < (size_t) argc - 1) //recorre argumentos
		{
			y = -1;
			while (argv[x + 1][++y])
				if (!ft_isdigit(argv[x + 1][y]) && (0 != y || argv[x + 1][0] != '-'))
					ft_puterror("caracteres especiales.\n");
			ft_inrange(stack, argv[x + 1], x);
		}
		stack->tam = argc - 1;
	}
	return (stack);
}
