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

t_stack	*ft_check_arg(int argc, char **argv);
void	ft_have_dup(t_stack *stack);
void	ft_putstack(t_stack *stack, char s);//
void	ft_error(char *error);
void	ft_isordered(t_stack *stack);
t_stack	*ft_reserve_stack(int tam);
void	ft_core(t_stack *stack_a, t_sol *solution);
void	ft_order_100(t_sol *solution, t_stack *stack_a);
void	ft_incrust_a_i_b_r(t_sol *solution, t_stack *stack_a, t_stack *stack_b);
void	ft_incrust_button_r(t_sol *solution, t_stack *stack_a, t_stack *stack_b,
			int num);
void	ft_incrust_top_r(t_sol *solution, t_stack *stack_a, t_stack *stack_b,
			int num);
// FT_MOVS.C
void	ft_m_sa(t_sol *solution, t_stack *stack_a);
void	ft_m_sb(t_sol *solution, t_stack *stack_b);
void	ft_m_ss(t_sol *solution, t_stack *stack_a, t_stack *stack_b);
void	ft_m_ra(t_sol *solution, t_stack *stack_a);
void	ft_m_rb(t_sol *solution, t_stack *stack_b);
void	ft_m_rr(t_sol *solution, t_stack *stack_a, t_stack *stack_b);
void	ft_m_rra(t_sol *solution, t_stack *stack_a);
void	ft_m_rrb(t_sol *solution, t_stack *stack_b);
void	ft_m_rrr(t_sol *solution, t_stack *stack_a, t_stack *stack_b);
void	ft_m_pa(t_sol *solution, t_stack *stack_a, t_stack *stack_b);
void	ft_m_pb(t_sol *solution, t_stack *stack_a, t_stack *stack_b);
void	ft_up(t_sol *solution, t_stack *stack, int num);
// FT_SOLUTION
t_sol	*ft_solnew(void);
void	ft_soladd(t_sol *solution, char *add);
void	ft_optimice_sol(t_sol *solution);
void	ft_optimice_sol_7(t_sol *solution);
void	ft_optimice_sol_6(t_sol *solution);
void	ft_optimice_sol_5(t_sol *solution);
void	ft_optimice_sol_4(t_sol *solution);
void	ft_optimice_sol_3(t_sol *solution);
void	ft_optimice_sol_2(t_sol *solution);
void	ft_optimice_sol_1(t_sol *solution);
void	ft_optimice_sol_0(t_sol *solution);
#endif