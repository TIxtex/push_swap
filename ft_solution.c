#include "push_swap.h"

void	ft_soladd(t_smart_str *solution, char *add)
{
	char	*newsol;

	newsol = ft_strjoin(solution->start, add);
	free (solution->start);
	solution->start = newsol;
	solution->size += ft_strlen(add);
}

t_smart_str	*ft_solnew(void)
{
	t_smart_str	*solution;

	solution = (t_smart_str *)ft_calloc(TRUE, sizeof(t_smart_str));
	if (NULL != solution)
	{
		solution->start = (char *)ft_calloc(TRUE, sizeof(char));
		if (NULL != solution->start)
			solution->size = ZERO;
		else
			solution = soluton->start
	}
	return (solution);
}

void	ft_optimice_sol(t_smart_str *solution)
{
	ft_optimice_sol_0(solution, "sa\nsb", 's', 3);
	ft_optimice_sol_0(solution, "sb\nsa", 's', 3);
	ft_optimice_sol_1(solution, "rra\nrrb", 'r', 4);
	ft_optimice_sol_1(solution, "rrb\nrra", 'r', 4);
	ft_optimice_sol_2(solution, "pa\npb", 6);
	ft_optimice_sol_2(solution, "pb\npa", 6);
	ft_optimice_sol_3(solution, "\nra\nrb", 'r', 3);
	ft_optimice_sol_3(solution, "\nrb\nra", 'r', 3);
	if (solution->start[solution->tam] == '\n')
		solution->start[solution->tam] = '\0';
}
