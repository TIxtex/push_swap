#include "../push_swap.h"

static t_stack	*ft_check_arg(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		j;
	long	num;

	if (argc < 2)
		ft_error("Error, introduce numeros enteros.\n");
	stack = ft_reserve_stack(argc - 1);
	i = 0;
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
	ft_have_dup(stack);
	ft_isordered(stack);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = ft_check_arg(argc, argv);
	ft_core(stack_a);
	free(stack_a->stack);
	free(stack_a);
	return (0);
}
