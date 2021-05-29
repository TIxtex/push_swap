#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>//**//

typedef struct	s_fragment
{
	int			min;
	int			max;
	int			tam;
	int			phase;
}				t_fragment;

typedef struct	s_stack
{
	int			tam;
	int			*stack;
}				t_stack;

//FT_TOOLS
void			ft_have_dup(t_stack *stack);
void			ft_putstack(t_stack *stack, char s);//
void			ft_error(char *error);
// FT_CORE
void			ft_core(t_stack *stack_a);
// FT_MOVS.C
void			ft_m_sa(t_stack *stack_a);
void			ft_m_ra(t_stack *stack_a);
void			ft_m_rb(t_stack *stack_b);
void			ft_m_rra(t_stack *stack_a);
void			ft_m_rrb(t_stack *stack_b);
void			ft_m_pa(t_stack *stack_a, t_stack *stack_b);
void			ft_m_pb(t_stack *stack_a, t_stack *stack_b);
// FT_ORDER_100
void			ft_order_100(t_stack *stack_a);

#endif