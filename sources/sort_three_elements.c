/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:57:35 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/04 13:57:36 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_from_two(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	push_a(stack_a, stack_b, info);
	if ((*stack_b)->index - (*info)->sorted == 0)
	{
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		rotate_a(stack_a);
		(*info)->sorted += 3;
	}
	else if ((*stack_b)->index - (*info)->sorted == 1)
	{
		push_a(stack_a, stack_b, info);
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
		(*info)->sorted += 3;
	}
}

static void	sort_from_one(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	push_a(stack_a, stack_b, info);
	if ((*stack_b)->index - (*info)->sorted == 0)
	{
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		rotate_a(stack_a);
		(*info)->sorted += 2;
		if (*stack_b)
		{
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			(*info)->sorted++;
		}
	}
	else if ((*stack_b)->index - (*info)->sorted == 2)
	{
		push_a(stack_a, stack_b, info);
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
		(*info)->sorted += 3;
	}
}

static void	sort_from_null(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	push_a(stack_a, stack_b, info);
	rotate_a(stack_a);
	(*info)->sorted++;
	if (!*stack_b)
		return ;
	else if ((*stack_b)->index - (*info)->sorted == 0)
	{
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		(*info)->sorted++;
		if (*stack_b)
		{
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			(*info)->sorted++;
		}
	}
	else if ((*stack_b)->index - (*info)->sorted == 1)
	{
		push_a(stack_a, stack_b, info);
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		rotate_a(stack_a);
		(*info)->sorted += 2;
	}
}

void	sort_three_element(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	if (!*stack_b)
		return ;
	if ((*stack_b)->index - (*info)->sorted == 0)
		sort_from_null(stack_a, stack_b, info);
	else if ((*stack_b)->index - (*info)->sorted == 1)
		sort_from_one(stack_a, stack_b, info);
	else if ((*stack_b)->index - (*info)->sorted == 2)
		sort_from_two(stack_a, stack_b, info);
}
