/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:11:12 by uliherre          #+#    #+#             */
/*   Updated: 2023/05/06 18:11:13 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../push_swap.h"
# include "../libft/libft.h"

void	ft_mc_s(t_st *st_a);
void	ft_mc_ss(t_st *st_a, t_st *st_b);
void	ft_mc_r(t_st *st_a);
void	ft_mc_rr2(t_st *st_a, t_st *st_b);
void	ft_mc_rr(t_st *st_a);
void	ft_mc_rrr(t_st *st_a, t_st *st_b);
void	ft_mc_pa(t_st *st_a, t_st *st_b);
void	ft_mc_pb(t_st *st_a, t_st *st_b);
void	ft_c_up(t_st *stack, int num);

#endif
