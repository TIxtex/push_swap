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
	ft_optimice_sol_0(solution);
	ft_optimice_sol_1(solution);
	ft_optimice_sol_2(solution);
	ft_optimice_sol_3(solution);
	ft_optimice_sol_4(solution);
	ft_optimice_sol_5(solution);
}
