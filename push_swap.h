#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# include "./libft/libft.h"
# include <limits.h>

void	ft_have_dup(int *srack_a, int tam);
void	ft_putstack(int *stack_a, int tam);
void	ft_error(char *error);
void	ft_core(int *stack_a, int tam);

void	ft_m_sa(int *stack_a);
void	ft_m_ra(int *stack_a, int tam);
void	ft_m_rra(int *stack_a, int tam);
void	ft_m_pa(int *stack_a, int *stack_b, int tam_a, int tam_b);
void	ft_m_pb(int *stack_a, int *stack_b, int tam_a, int tam_b);

#endif