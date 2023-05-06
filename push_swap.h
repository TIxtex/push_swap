/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:21 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:22 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# define PA "pa\n"
# define SA "sa\n"
# define RA "ra\n"
# define RRA "rra\n"
# define PB "pb\n"
# define SB "sb\n"
# define RB "rb\n"
# define RRB "rrb\n"

# ifndef ERRORS_LIST
#  define ERRORS_LIST
#  define ERR_0 "Allocando stack"
#  define ERR_1 "Introduce argumentos"
#  define ERR_2 "Excedido limite de integer."
#  define ERR_3 "Caracteres especiales"
#  define ERR_4 "Allocando solucion"
#  define ERR_5 "Reserva de memoria de fragment."
#  define ERR_6 "Error, numeros duplicados."
#  define ERR_X "Me das asco por probar esto que lo sepas"
# endif

typedef struct s_list t_sol;

typedef struct s_fragment
{
	int			min;
	int			max;
	size_t		tam;
	int			phase;
}				t_fragment;

typedef struct s_stack
{
	size_t		tam;
	int			*stack;
}				t_st;

/**	FT_CORE	**/
t_st	*ft_check_args(int argc, char **argv);
void	ft_core(t_st *stack_a, t_sol *solution);
/**	FT_TOOLS.c	**/
void	ft_have_dup(t_st *stack);
/*void	ft_putstack(t_st *stack, char s);*/
int		ft_condition(t_st *stack_a, t_st *stack_b, int i);
int		ft_isordered(t_st *stack);
t_st	*ft_reserve_stack(size_t tam);
void	ft_colocate(t_sol *solution, t_st *stack);
int		get_next_line(int fd, char **line);
/**	FT_ORDER.c	**/
void	ft_order_100(t_sol *solution, t_st *stack_a);
void	ft_incrust_a_i_b_r(t_sol *solution, t_st *stack_a, t_st *stack_b);
void	ft_incrust_button_pa(t_sol *solution, t_st *stack_a, t_st *stack_b, int num);
void	ft_incrust_top_pa(t_sol *solution, t_st *stack_a, t_st *stack_b, int num);
/**	FT_MOVEMENTS.C	**/
void	ft_m_s(t_sol *solution, t_st *stack, char *add);
void	ft_m_r(t_sol *solution, t_st *stack, char *add);
void	ft_m_rr(t_sol *solution, t_st *stack, char *add);
void	ft_m_p1(t_sol *solution, t_st *stack_1, t_st *stack_2, char *add);
void	ft_up(t_sol *solution, t_st *stack, int num, char *add);

/**		FT_SOLUTION		**/
t_sol	*ft_solnew(void);
void	ft_soladd(t_sol *solution, char *add);
void	ft_optimice_sol(t_sol *solution);
void	ft_optimice_sol_3(t_sol *solution, char *find, char put, int num);
void	ft_optimice_sol_2(t_sol *solution, char *find, int num);
void	ft_optimice_sol_1(t_sol *solution, char *find, char put, int num);
void	ft_optimice_sol_0(t_sol *solution, char *find, char put, int num);

#endif
