#include "../push_swap.h"

void	ft_optimice_sol(t_sol *solution)
{
	ft_optimice_sol_0(solution, "sa\nsb", 's', 3);
	ft_optimice_sol_0(solution, "sb\nsa", 's', 3);
	ft_optimice_sol_1(solution, "rra\nrrb", 'r', 4);
	ft_optimice_sol_1(solution, "rrb\nrra", 'r', 4);
	ft_optimice_sol_2(solution, "pa\npb", 6);
	ft_optimice_sol_2(solution, "pb\npa", 6);
	ft_optimice_sol_3(solution, "\nra\nrb", 'r', 3);
	ft_optimice_sol_3(solution, "\nrb\nra", 'r', 3);
	if (solution->str[solution->size] == '\n')
		solution->str[solution->size] = '\0';
}
