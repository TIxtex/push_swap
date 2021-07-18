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
	ft_soladd(solution, "\0");
	ft_optimice_sol_0(solution, "sa\nsb", 's', 3);
	ft_optimice_sol_0(solution, "sb\nsa", 's', 3);
	ft_optimice_sol_0(solution, "ra\nrb", 'r', 3);
	ft_optimice_sol_0(solution, "rb\nra", 'r', 3);
	ft_optimice_sol_1(solution, "rra\nrrb", 'r', 4);
	ft_optimice_sol_1(solution, "rrb\nrra", 'r', 4);
	ft_optimice_sol_2(solution, "pa\npb", 5);
	ft_optimice_sol_2(solution, "pb\npa", 5);
	ft_soladd(solution, "\0");
}
