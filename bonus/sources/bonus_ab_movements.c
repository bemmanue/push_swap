/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ab_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:35:14 by bemmanue          #+#    #+#             */
/*   Updated: 2021/12/17 15:35:16 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	bns_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	bns_rotate_a(stack_a);
	bns_rotate_b(stack_b);
}

void	bns_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	bns_rotate_a(stack_a);
	bns_rotate_b(stack_b);
}
