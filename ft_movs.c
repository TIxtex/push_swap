#include "push_swap.h"

void	ft_m_sa(int *stack_a)
{
	int	aux;

	aux = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = aux;
	ft_putstr_fd("sa\n", 1);
}

void	ft_m_ra(int *stack_a, int tam)
{
	int	i;
	int	aux;

	aux = stack_a[0];
	i = -1;
	while (++i < tam - 1)
		stack_a[i] = stack_a[i + 1];
	stack_a[tam - 1] = aux;
	ft_putstr_fd("ra\n", 1);
}

void	ft_m_rra(int *stack_a, int tam)
{
	int	i;
	int	aux;

	aux = stack_a[tam - 1];
	i = tam - 1;
	while(--i >= 0)
		stack_a[i + 1] = stack_a[i];
	stack_a[0] = aux;
	ft_putstr_fd("rra\n", 1);
}

void	ft_m_pa(int *stack_a, int *stack_b, int tam_a, int tam_b)
{
	int	i;

	i = tam_a;
	while (--i >= 0)
		stack_a[i + 1] = stack_a[i];
	stack_a[0] = stack_b[0];
	i = -1;
	while (++i < tam_b - 1)
		stack_b[i] = stack_b[i + 1];
	ft_putstr_fd("pa\n", 1);
}

void	ft_m_pb(int *stack_a, int *stack_b, int tam_a, int tam_b)
{
	int	i;

	i = tam_b;
	while (--i >=0)
		stack_b[i + 1] = stack_b[i];
	stack_b[0] = stack_a[0];
	i = -1;
	while (++i < tam_a - 1)
		stack_a[i] = stack_a[i + 1];
	ft_putstr_fd("pb\n", 1);
}