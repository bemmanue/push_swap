
#include "../includes/push_swap.h"
#include <stdio.h>

int operation = 0;

void	swap_a(t_stack **stack_a)
{
	t_stack *temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	operation++;
}

void	swap_b(t_stack **stack_b)
{
	t_stack *temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	operation++;
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	operation--;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (*stack_b == NULL)
		return ;
	temp = (*stack_b);
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	operation++;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (*stack_a == NULL)
		return ;
	temp = (*stack_a);
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	operation++;
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
	operation++;
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
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
	operation++;
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	operation--;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = ft_lstlast_ps(*stack_a);
	tail = *stack_a;
	while (tail->next->next != NULL)
		tail = tail->next;
	tail->next = NULL;
	head->next = *stack_a;
	*stack_a = head;
	operation++;
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	head = ft_lstlast_ps(*stack_b);
	tail = *stack_b;
	while (tail->next->next != NULL)
		tail = tail->next;
	tail->next = NULL;
	head->next = *stack_b;
	*stack_b = head;
	operation++;
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	operation--;
}
