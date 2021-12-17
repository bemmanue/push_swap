/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_b_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:33:41 by bemmanue          #+#    #+#             */
/*   Updated: 2021/12/17 15:33:43 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	bns_swap_b(t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	bns_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return ;
	temp = (*stack_a);
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	bns_rotate_b(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*stack_b || !(*stack_b)->next)
	{
		write(2, "KO\n", 3);
		exit(0);
	}
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	if ((*stack_b)->next != NULL)
		temp2 = (*stack_b)->next;
	else
		temp2 = *stack_b;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
}

void	bns_reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack_b || !(*stack_b)->next)
	{
		write(2, "KO\n", 3);
		exit(0);
	}
	head = last_stack(*stack_b);
	tail = *stack_b;
	while (tail->next->next != NULL)
		tail = tail->next;
	tail->next = NULL;
	head->next = *stack_b;
	*stack_b = head;
}
