#include "push_swap.h"

t_stack	*ft_reserve_stack(int tam)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (NULL == stack)
		ft_error("Error, fallo en reserva de memoria.\n");
	stack->stack = (int *)ft_calloc(tam, sizeof(int));
	if (NULL == stack->stack)
		ft_error("Error, fallo en reserva de memoria.\n");
	return (stack);
}

void	ft_have_dup(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->tam)
	{
		j = i;
		while (++j < stack->tam)
			if (stack->stack[i] == stack->stack[j])
				ft_error("Error, numeros duplicados.\n");
	}
}

int	ft_isordered(t_stack *stack)
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (++i < stack->tam - 1 && flag)
		if (stack->stack[i] > stack->stack[i + 1])
			flag = 0;
	if (flag)
		return (1);
	return (0);
}

void	ft_putstack(t_stack *stack, char s)
{
	int		i;

	i = -1;
	ft_putstr_fd("\n||Stack -> ", 1);
	ft_putchar_fd(s, 1);
	ft_putstr_fd("\n||_ _ _ _ _ _ _ ||\n", 1);
	while (++i < stack->tam)
	{
		ft_putstr_fd("||\t", 1);
		ft_putnbr_fd(stack->stack[i], 1);
		ft_putstr_fd("\t||\n", 1);
		ft_putstr_fd("\n||_ _ _ _ _ _ _ ||\n", 1);
	}
	ft_putstr_fd("||_ _ _ _ _ _ _ ||\n\n", 1);
}

void		ft_onearg(char *str)
{
	char	**split;
	size_t	i;
	double	num;

	while (str[i])
		if (!ft_isdigit(str[i]) && (0 != str[i] || str[i] != '-')
			&& !ft_isspace(str[i]))
			ft_error("Error, caracteres especiales\n");
	split = ft_split(str, ' ');
	i = 0;
	while (split[i][0])
	{
		num = ft_atoi(split[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error("Error, excedido limite de enteros.\n");
		else
			stack->stack[i] = (int)num;
		i++
	}
	i = -1;
	while (split[++i][0])
		free(split[i]);
	free (split);
}
