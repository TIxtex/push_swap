#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
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
/*
typedef struct s_sol
{
	int			tam;
	char		*start;
	char		*end;
}				t_sol;
*/

void			ft_have_dup(t_stack *stack);
void			ft_putstack(t_stack *stack, char s);//
void			ft_error(char *error);
void			ft_isordered(t_stack *stack);
t_stack			*ft_reserve_stack(int tam);
void			ft_core(t_stack *stack_a);
void			ft_order_100(t_stack *stack_a);
//int				ft_find_1(t_stack *stack, t_fragment *fragment);//
//int				ft_find_2(t_stack *stack, t_fragment *fragment);//
void			ft_incrust_a_i_b_r(t_stack *stack_a, t_stack *stack_b);
void			ft_incrust_b_i_a(t_stack *stack_a, t_stack *stack_b);
// FT_MOVS.C
void			ft_m_sa(t_stack *stack_a);
void			ft_m_sb(t_stack *stack_b);
void			ft_m_ss(t_stack *stack_a, t_stack *stack_b);
void			ft_m_ra(t_stack *stack_a);
void			ft_m_rb(t_stack *stack_b);
void			ft_m_rr(t_stack *stack_a, t_stack *stack_b);
void			ft_m_rra(t_stack *stack_a);
void			ft_m_rrb(t_stack *stack_b);
void			ft_m_rrr(t_stack *stack_a, t_stack *stack_b);
void			ft_m_pa(t_stack *stack_a, t_stack *stack_b);
void			ft_m_pb(t_stack *stack_a, t_stack *stack_b);
void			ft_up(t_stack *stack, int num);

#endif