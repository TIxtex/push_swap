#include "checker.h"

static void	ft_isordered2(t_stack *stack, t_stack *stack_b)
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (++i < stack->tam - 1 && flag)
		if (stack->stack[i] > stack->stack[i + 1])
			flag = 0;
	if (flag && stack_b->tam == 0)
		write(1, "K\n", 2);
	else
		write(1, "KO\n", 3);
}

static void 	ft_make_move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (move[0] == 's')
	{
		if (move[1] == 'a')
			ft_mc_s(stack_a);
		else if (move[1] == 'b')
			ft_mc_s(stack_b);
		else if (move[1] == 's')
			ft_mc_ss(stack_a, stack_b);
		else
			ft_error("Error\n");
	}
	else if (move[0] == 'p')
	{
		if (move[1] == 'a')
			ft_mc_pa(stack_a, stack_b);
		else if (move[1] == 'b')
			ft_mc_pb(stack_a, stack_b);
		else
			ft_error("Error\n");
	}
	else if (move[0] == 'r')
	{
		if (move[1] == 'r')
		{
			if (move[2] == 'a')
				ft_mc_rr(stack_a);
			else if (move[2] == 'b')
				ft_mc_rr(stack_b);
			else if (move[2] == 'r')
				ft_mc_rrr(stack_a, stack_b);
			else
				ft_error("Error\n");
		}
		else if (move[1] == 'a')
			ft_mc_r(stack_a);
		else if (move[1] == 'b')
			ft_mc_r(stack_b);
		else
			ft_error("Error\n");
	}
	else
		ft_error("Error\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = ft_check_arg(argc, argv);
	stack_b = ft_reserve_stack(stack_a->tam);
	while (get_next_line(0, &line) >= 0)
		ft_make_move(line, stack_a, stack_b);
	ft_isordered2(stack_a, stack_b);
	free(stack_b->stack);
	free(stack_b);
	free(stack_a->stack);
	free(stack_a);
}
