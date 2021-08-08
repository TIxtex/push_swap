#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_sol	*solution;

	stack_a = ft_check_arg(argc, argv);
	ft_have_dup(stack_a);
	solution = ft_solnew();
	ft_core(stack_a, solution);
	free(solution->start);
	free(solution);
	free(stack_a->stack);
	free(stack_a);
	system("leaks push_swap");
	return (1);
}
