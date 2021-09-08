
#include "../includes/push_swap.h"
#include <stdio.h>

void	swap_a(t_stack **stack_a)
{
	t_stack *temp;

	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	swap_b(t_stack **stack_b)
{
	t_stack *temp;

	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	temp = (*stack_b);
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	temp = (*stack_a);
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	rotate_a(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	temp->next = NULL;
	temp2 = (*stack_a)->next;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	temp->next = NULL;
	temp2 = (*stack_b)->next;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;;
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*first;

	first = ft_lstlast_ps(*stack_a);
	last = *stack_a;
	while (last->next->next != NULL)
		last = last->next;
	last->next = NULL;
	first->next = *stack_a;
	*stack_a = first;
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*first;

	first = ft_lstlast_ps(*stack_b);
	last = *stack_b;
	while (last->next->next != NULL)
		last = last->next;
	last->next = NULL;
	first->next = *stack_b;
	*stack_b = first;
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);;
}
