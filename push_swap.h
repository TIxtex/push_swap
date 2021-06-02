#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>//**//

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

//FT_TOOLS
void			ft_have_dup(t_stack *stack);
void			ft_putstack(t_stack *stack, char s);//
void			ft_error(char *error);
void			ft_isordered(t_stack *stack);
t_stack			*ft_reserve_stack(int tam);
// FT_CORE
void			ft_core(t_stack *stack_a);
// FT_MOVS.C
void			ft_m_sa(t_stack *stack_a);
void			ft_m_sb(t_stack *stack_b);
void			ft_m_ra(t_stack *stack_a);
void			ft_m_rb(t_stack *stack_b);
void			ft_m_rra(t_stack *stack_a);
void			ft_m_rrb(t_stack *stack_b);
void			ft_m_pa(t_stack *stack_a, t_stack *stack_b);
void			ft_m_pb(t_stack *stack_a, t_stack *stack_b);
void			ft_up(t_stack *stack, int num);
// FT_ORDER
void			ft_order_100(t_stack *stack_a);
int				ft_find_1(t_stack *stack, t_fragment *fragment);
int				ft_find_2(t_stack *stack, t_fragment *fragment);

#endif