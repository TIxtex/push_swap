#include "push_swap.h"

void	ft_optimice_sol_5(t_sol *solution)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, "rrb\nrra", solution->tam);
	if (NULL != i)
	{
		i[2] = 'r';
		i[3] = '\0';
		aux = ft_strjoin(solution->start, &i[7]);
		solution->tam -= 3;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_5(solution);
	}
}

void	ft_optimice_sol_6(t_sol *solution)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, "pa\npb", solution->tam);
	if (NULL != i)
	{
		i[0] = '\0';
		aux = ft_strjoin(solution->start, &i[6]);
		solution->tam -= 3;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_6(solution);
	}
}

void	ft_optimice_sol_7(t_sol *solution)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, "pb\npa", solution->tam);
	if (NULL != i)
	{
		i[0] = '\0';
		aux = ft_strjoin(solution->start, &i[6]);
		solution->tam -= 3;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_7(solution);
	}
}
