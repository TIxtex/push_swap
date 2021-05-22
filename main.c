#include "push_swap.h"

static int	*ft_fill_stack(int argc, char **argv)
{
	int		i;
	int		j;
	int		*stack;
	long	num;

	i = 0;
	stack = (int *)malloc((argc - 1) * sizeof(int));
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
			stack[i - 1] = (int)num;
	}
	return (stack);
}

static int	*ft_check_arg(int argc, char **argv)
{

	int		*stack;

	stack = NULL;
	if (argc < 2)
		ft_error("Error, introduce numeros enteros.\n");
	else if (argc > 2)
	{
		stack = ft_fill_stack(argc, argv);
		ft_have_dup(stack, argc - 1);
	}
	return (stack);
}

int			main(int argc, char **argv)
{
	int		*stack_a;
	stack_a = ft_check_arg(argc, argv);
	ft_putstack(stack_a, argc - 1);

	free(stack_a);
	return (0);
}