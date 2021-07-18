#include "push_swap.h"

void	ft_optimice_sol_0(t_sol *solution, char *find, char put, int num)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, find, solution->tam);
	if (NULL != i)
	{
		i[1] = put;
		i[2] = '\0';
		aux = ft_strjoin(solution->start, &i[5]);
		solution->tam -= num;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_0(solution);
	}
}

void	ft_optimice_sol_1(t_sol *solution, char *find, char put, int num)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, find, solution->tam);
	if (NULL != i)
	{
		i[2] = put;
		i[3] = '\0';
		aux = ft_strjoin(solution->start, &i[7]);
		solution->tam -= num;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_0(solution);
	}
}

void	ft_optimice_sol_2(t_sol *solution, char *find, int num)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, "pb\npa", solution->tam);
	if (NULL != i)
	{
		i[0] = '\0';
		aux = ft_strjoin(solution->start, &i[5]);
		solution->tam -= num;
		free(solution->start);
		solution->start = aux;
	}
}