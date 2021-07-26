#include "push_swap.h"

void	ft_soladd(t_sol *solution, char *add)
{
	char	*newsol;

	newsol = ft_strjoin(solution->start, add);
	free (solution->start);
	solution->start = newsol;
	solution->tam += ft_strlen(add);
}

t_sol	*ft_solnew(void)
{
	t_sol	*solution;

	solution = (t_sol *)ft_calloc(1, sizeof(t_sol));
	if (NULL == solution)
		ft_error("Error. Reserva de memoria");
	solution->start = (char *)ft_calloc(1, sizeof(char));
	if (NULL == solution->start)
		ft_error("Error. Reserva de memoria");
	solution->tam = 0;
	return (solution);
}

void	ft_optimice_sol(t_sol *solution)
{
	ft_optimice_sol_0(solution, "sa\nsb", 's', 3);
	ft_optimice_sol_0(solution, "sb\nsa", 's', 3);
	ft_optimice_sol_1(solution, "rra\nrrb", 'r', 4);
	ft_optimice_sol_1(solution, "rrb\nrra", 'r', 4);
	ft_optimice_sol_2(solution, "pa\npb", 6);
	ft_optimice_sol_2(solution, "pb\npa", 6);
	if (solution->start[solution->tam] == '\n')
		solution->start[solution->tam] = '\0';
}
