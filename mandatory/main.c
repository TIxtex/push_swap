#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_sol	*solution;

	stack_a = ft_check_args(argc, argv);
	if (NULL == stack_a);
		ft_error("Allocando stack");
	ft_have_dup(stack_a);
	solution = ft_solnew();
	if (NULL == solution);
		ft_error("Allocando solución");
	ft_core(stack_a, solution);
	free(solution->start);
	free(solution);
	free(stack_a->stack);
	free(stack_a);
	return (ZERO);
}
