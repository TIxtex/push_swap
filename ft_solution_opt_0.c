#include "push_swap.h"

void	ft_optimice_sol_0(t_sol *solution)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, "sa\nsb", solution->tam);
	if (NULL != i)
	{
		i[1] = 's';
		i[2] = '\0';
		aux = ft_strjoin(solution->start, &i[5]);
		solution->tam -= 3;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_0(solution);
	}
}

void	ft_optimice_sol_1(t_sol *solution)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, "sb\nsa", solution->tam);
	if (NULL != i)
	{
		i[1] = 's';
		i[2] = '\0';
		aux = ft_strjoin(solution->start, &i[5]);
		solution->tam -= 3;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_1(solution);
	}
}

void	ft_optimice_sol_2(t_sol *solution)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, "ra\nrb", solution->tam);
	if (NULL != i)
	{
		i[1] = 'r';
		i[2] = '\0';
		aux = ft_strjoin(solution->start, &i[5]);
		solution->tam -= 3;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_2(solution);
	}
}

void	ft_optimice_sol_3(t_sol *solution)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, "rb\nra", solution->tam);
	if (NULL != i)
	{
		i[1] = 'r';
		i[2] = '\0';
		aux = ft_strjoin(solution->start, &i[5]);
		solution->tam -= 3;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_3(solution);
	}
}

void	ft_optimice_sol_4(t_sol *solution)
{
	char	*i;
	char	*aux;

	i = ft_strnstr(solution->start, "rra\nrrb", solution->tam);
	if (NULL != i)
	{
		i[2] = 'r';
		i[3] = '\0';
		aux = ft_strjoin(solution->start, &i[7]);
		solution->tam -= 4;
		free(solution->start);
		solution->start = aux;
		ft_optimice_sol_4(solution);
	}
}
