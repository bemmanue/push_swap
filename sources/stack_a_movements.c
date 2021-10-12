/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:57:48 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/04 13:57:49 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_putstr_fd("sa\n", 1);
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	temp = (*stack_b);
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	(*info)->main++;
	(*info)->remain--;
	(*info)->middle = (*info)->remain / 2;
	ft_putstr_fd("pa\n", 1);
}

void	rotate_a(t_stack **stack_a)
{
	t_stack	*tail;
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
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
	ft_putstr_fd("ra\n", 1);
}

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = last_stack(*stack_a);
	tail = *stack_a;
	while (tail->next->next != NULL)
		tail = tail->next;
	tail->next = NULL;
	head->next = *stack_a;
	*stack_a = head;
	ft_putstr_fd("rra\n", 1);
}
