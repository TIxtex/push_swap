#include "../push_swap.h"

void	del(void	*to_del)
{
	free((char *)to_del);
	to_del = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_sol	*solution;

	stack_a = ft_check_args(argc, argv);
	if (NULL == stack_a)
		ft_puterror("Allocando stack");
	ft_have_dup(stack_a);
	solution = ft_lstnew("");
	if (NULL == solution)
		ft_puterror("Allocando solución");
	ft_core(stack_a, solution);
	ft_lstclear(&solution, NULL);
	free(stack_a->stack);
	free(stack_a);
	return (ZERO);
}

