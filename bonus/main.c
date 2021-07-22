#include "checker.h"

static void	ft_isordered2(t_stack *stack)
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (++i < stack->tam - 1 && flag)
		if (stack->stack[i] > stack->stack[i + 1])
			flag = 0;
	if (flag == 0)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
}

static void 	ft_make_move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(move, "sa", 2) == 0)
		ft_mc_s(stack_a);
	else if (ft_strncmp(move, "sb", 2) == 0)
		ft_mc_s(stack_b);
	else if (ft_strncmp(move, "ss", 2) == 0)
		ft_mc_ss(stack_a, stack_b);
	else if (ft_strncmp(move, "pa", 2) == 0)
		ft_mc_pa(stack_a, stack_b);
	else if (ft_strncmp(move, "pb", 2) == 0)
		ft_mc_pb(stack_a, stack_b);
	else if (ft_strncmp(move, "ra", 2) == 0)
		ft_mc_r(stack_a);
	else if (ft_strncmp(move, "rb", 2) == 0)
		ft_mc_r(stack_b);
	else if (ft_strncmp(move, "rra", 3) == 0)
		ft_mc_rr(stack_a);
	else if (ft_strncmp(move, "rrb", 3) == 0)
		ft_mc_rr(stack_b);
	else if (ft_strncmp(move, "rrr", 3) == 0)
		ft_mc_rrr(stack_a, stack_b);
	else if (ft_strncmp(move, "rr", 2) == 0)
		ft_mc_rr2(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = ft_check_arg(argc, argv);
	stack_b = ft_reserve_stack(stack_a->tam);
	while (get_next_line(0, &line) > 0)
		ft_make_move(line, stack_a, stack_b);
	ft_isordered2(stack_a);
	free(stack_b->stack);
	free(stack_b);
	free(stack_a->stack);
	free(stack_a);
}
