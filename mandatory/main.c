#include "../push_swap.h"

void	del(void	*to_del)
{
	free((char *) to_del);
	to_del = NULL;
}

int	main(int argc, char **argv)
{
	t_st	*st_a;
	t_sol	*solution;

	st_a = ft_check_args(argc, argv);
	if (NULL == st_a)
		ft_puterror(ERR_0);
	ft_have_dup(st_a);
	solution = ft_lstnew("");
	if (NULL == solution)
		ft_puterror(ERR_0);
	ft_core(st_a, solution);
	ft_lstclear(&solution, NULL);
	free(st_a->stack);
	free(st_a);
	return (ZERO);
}

