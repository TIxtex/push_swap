#ifndef CHECKER_H
# define CHECKER_H
# include "../push_swap.h"
# include <stdio.h>

void	ft_mc_s(t_stack *stack_a);
void	ft_mc_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_mc_r(t_stack *stack_a);
void	ft_mc_rr2(t_stack *stack_a, t_stack *stack_b);
void	ft_mc_rr(t_stack *stack_a);
void	ft_mc_rrr(t_stack *stack_a, t_stack *stack_b);
void	ft_mc_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_mc_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_c_up(t_stack *stack, int num);

#endif