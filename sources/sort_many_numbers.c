/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:57:24 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/04 13:57:26 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stacks(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack	*temp;
	int		position;
	int		middle;

	temp = *stack_a;
	position = 0;
	middle = (*info)->main / 2;
	while (temp)
	{
		if (temp->index < middle)
		{
			temp->flag = 1;
			put_up_element_a(stack_a, temp->index,
				position, (*info)->main / 2);
			push_b(stack_a, stack_b, info);
			temp = *stack_a;
			position = 0;
		}
		else
			temp = temp->next;
		position++;
	}
}

void	sort_more_elements(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int	limit;
	int	flag;
	int	i;

	flag = 1;
	while ((*info)->remain > 3)
	{
		limit = (*info)->middle + (*info)->sorted;
		i = (*info)->middle - 1 + ((*info)->remain % 2);
		while (i && *stack_b)
		{
			if ((*stack_b)->index > limit)
			{
				(*stack_b)->flag += flag;
				push_a(stack_a, stack_b, info);
				i--;
			}
			else if (!fast_b_sorting(stack_a, stack_b, info))
				rotate_b(stack_b);
		}
		flag++;
	}
}

void	sort_groups(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int	flag;

	while ((*info)->sorted < (*info)->number)
	{
		if ((*info)->remain > 3)
			sort_more_elements(stack_a, stack_b, info);
		sort_three_element(stack_a, stack_b, info);
		flag = (*stack_a)->flag;
		while ((*stack_a)->flag == flag && (*stack_a)->index != 0)
		{
			if (!fast_a_sorting(stack_a, info))
				push_b(stack_a, stack_b, info);
		}
	}
}

void	sort_many_numbers(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	divide_stacks(stack_a, stack_b, info);
	sort_groups(stack_a, stack_b, info);
}
