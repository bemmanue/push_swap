
#include "../includes/push_swap.h"

void	swap_b(t_stack **stack_b)
{
	t_stack *temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_putstr_fd("sb\n", 1);
}

void	push_b(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack *temp;

	if (*stack_a == NULL)
		return ;
	temp = (*stack_a);
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	(*info)->main--;
	(*info)->remain++;
	(*info)->middle = (*info)->remain / 2;
	ft_putstr_fd("pb\n", 1);
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
	ft_putstr_fd("rb\n", 1);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	head = last_stack(*stack_b);
	tail = *stack_b;
	while (tail->next->next != NULL)
		tail = tail->next;
	tail->next = NULL;
	head->next = *stack_b;
	*stack_b = head;
	ft_putstr_fd("rrb\n", 1);
}