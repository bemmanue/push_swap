/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:57:14 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/04 13:57:17 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_numbers(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	while ((*info)->main != 3)
	{
		while ((*stack_a)->index != 4 && (*stack_a)->index != 3)
			rotate_a(stack_a);
		push_b(stack_a, stack_b, info);
	}
	sort_three_numbers(stack_a);
	if ((*stack_b)->index == 4)
	{
		push_a(stack_a, stack_b, info);
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_b)->index == 3)
	{
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
	}
}

void	sort_four_numbers(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack	*temp;
	int		position;

	position = 0;
	temp = *stack_a;
	while (temp->index != 3)
	{
		temp = temp->next;
		position++;
	}
	while ((*stack_a)->index != 3)
	{
		if (position > (*info)->middle)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	push_b(stack_a, stack_b, info);
	sort_three_numbers(stack_a);
	push_a(stack_a, stack_b, info);
	rotate_a(stack_a);
}

void	sort_three_numbers(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *stack_a;
	next = (*stack_a)->next;
	if (temp->index == 0 && next->index == 2)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (temp->index == 1 && next->index == 0)
		swap_a(stack_a);
	else if (temp->index == 1 && next->index == 2)
		reverse_rotate_a(stack_a);
	else if (temp->index == 2 && next->index == 0)
		rotate_a(stack_a);
	else if (temp->index == 2 && next->index == 1)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
}

void	sort_few_numbers(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	if ((*info)->number <= 3)
		sort_three_numbers(stack_a);
	else if ((*info)->number == 4)
		sort_four_numbers(stack_a, stack_b, info);
	else if ((*info)->number == 5)
		sort_five_numbers(stack_a, stack_b, info);
}
