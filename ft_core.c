#include "push_swap.h"

static void	ft_order_3(int *stack_a)
{

	if (stack_a[1] > stack_a[2])
	{
		if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
			ft_m_rra(stack_a, 3);
		else if (stack_a[0] > stack_a[1])
		{
			ft_m_sa(stack_a);
			ft_m_rra(stack_a, 3);
		}
		else
		{
			ft_m_sa(stack_a);
			ft_m_ra(stack_a, 3);
		}
	}
	else if (stack_a[0] > stack_a[2])
		ft_m_ra(stack_a, 3);
	else if (stack_a[0] < stack_a[2] && stack_a[1] < stack_a[0])
		ft_m_sa(stack_a);
}

static void	ft_order_5(int *stack_a, int tam)
{
	int		*stack_b;
	int		i;
	int		tam_b;

	i = 0;
	stack_b = (int *)ft_calloc(2, sizeof(int));
	while (i < tam - 3)
		ft_m_pb(stack_a, stack_b, tam, i++);
	tam -= i;
	tam_b = i;
	ft_order_3(stack_a);
	while (tam_b > 0)
	{
		if (stack_b[0] < stack_a[0])
		{
			ft_m_pa(stack_a, stack_b, tam, tam_b);
			tam++;
		}
		else if (stack_b[0] > stack_a[tam - 1])
		{
			ft_m_pa(stack_a, stack_b, tam, tam_b);
			tam++;
			ft_m_ra(stack_a, tam);
		}
		else if (stack_b[0] < stack_a[1])
		{
			ft_m_pa(stack_a, stack_b, tam, tam_b);
			tam++;
			ft_m_sa(stack_a);
		}
		else if (stack_b[0] > stack_a[tam - 2])
		{
			ft_m_rra(stack_a, tam);
			ft_m_pa(stack_a, stack_b, tam, tam_b);
			tam++;
			ft_m_ra(stack_a, tam);
			ft_m_ra(stack_a, tam);
		}
		else
		{
			ft_m_ra(stack_a, tam);
			ft_m_pa(stack_a, stack_b, tam, tam_b);
			tam++;
			ft_m_sa(stack_a);
			ft_m_rra(stack_a, tam);
		}
		tam_b--;
	}
	free(stack_b);
}

void		ft_core(int *stack_a, int tam)
{

	if (2 == tam && stack_a[0] > stack_a[1])
			ft_m_sa(stack_a);
	else if (3 == tam)
		ft_order_3(stack_a);
	else if (6 > tam && 3 < tam)
		ft_order_5(stack_a, tam);

	ft_putstack(stack_a, tam);//
}