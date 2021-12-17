/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_a_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:33:30 by bemmanue          #+#    #+#             */
/*   Updated: 2021/12/17 15:33:32 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	bns_swap_a(t_stack **stack_a)
{
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	bns_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	temp = (*stack_b);
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	bns_rotate_a(t_stack **stack_a)
{
	t_stack	*tail;
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
	{
		write(2, "KO\n", 3);
		exit(0);
	}
	tail = *stack_a;
	*stack_a = (*stack_a)->next;
	tail->next = NULL;
	if ((*stack_a)->next != NULL)
		temp = (*stack_a)->next;
	else
		temp = *stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = tail;
}

void	bns_reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack_a || !(*stack_a)->next)
	{
		write(2, "KO\n", 3);
		exit(0);
	}
	head = last_stack(*stack_a);
	tail = *stack_a;
	while (tail->next->next != NULL)
		tail = tail->next;
	tail->next = NULL;
	head->next = *stack_a;
	*stack_a = head;
}
