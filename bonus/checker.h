/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:32:28 by bemmanue          #+#    #+#             */
/*   Updated: 2021/12/17 15:32:32 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/push_swap.h"
# include "get_next_line/get_next_line.h"

void	bns_swap_a(t_stack **stack_a);
void	bns_push_a(t_stack **stack_a, t_stack **stack_b);
void	bns_rotate_a(t_stack **stack_a);
void	bns_reverse_rotate_a(t_stack **stack_a);
void	bns_swap_b(t_stack **stack_b);
void	bns_push_b(t_stack **stack_a, t_stack **stack_b);
void	bns_rotate_b(t_stack **stack_b);
void	bns_reverse_rotate_b(t_stack **stack_b);
void	bns_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	bns_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

#endif
