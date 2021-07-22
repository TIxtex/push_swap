#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <limits.h>

typedef struct s_fragment
{
	int			min;
	int			max;
	int			tam;
	int			phase;
}				t_fragment;

typedef struct s_stack
{
	int			tam;
	int			*stack;
}				t_stack;

typedef struct s_sol
{
	int			tam;
	char		*start;
}				t_sol;

// FT_CORE
t_stack	*ft_check_arg(int argc, char **argv);
void	ft_core(t_stack *stack_a, t_sol *solution);
// FT_TOOLS.c
void	ft_have_dup(t_stack *stack);
void	ft_putstack(t_stack *stack, char s);//
int		ft_isordered(t_stack *stack);
t_stack	*ft_reserve_stack(int tam);
// FT_ORDER.c
void	ft_order_100(t_sol *solution, t_stack *stack_a);
void	ft_incrust_a_i_b_r(t_sol *solution, t_stack *stack_a, t_stack *stack_b);
void	ft_incrust_button_pa(t_sol *solution, t_stack *stack_a,
			t_stack *stack_b, int num);
void	ft_incrust_top_pa(t_sol *solution, t_stack *stack_a, t_stack *stack_b,
			int num);
// FT_MOVEMENTS.C
void	ft_m_s(t_sol *solution, t_stack *stack, char *add);
void	ft_m_r(t_sol *solution, t_stack *stack, char *add);
void	ft_m_rr(t_sol *solution, t_stack *stack, char *add);
void	ft_m_p1(t_sol *solution, t_stack *stack_1, t_stack *stack_2, char *add);
void	ft_up(t_sol *solution, t_stack *stack, int num, char *add);
// FT_SOLUTION
t_sol	*ft_solnew(void);
void	ft_soladd(t_sol *solution, char *add);
void	ft_optimice_sol(t_sol *solution);
void	ft_optimice_sol_2(t_sol *solution, char *find, int num);
void	ft_optimice_sol_1(t_sol *solution, char *find, char put, int num);
void	ft_optimice_sol_0(t_sol *solution, char *find, char put, int num);

#endif