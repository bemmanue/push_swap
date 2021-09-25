
#include "../includes/push_swap.h"

void	sort_five_elements(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int 	max;
	int 	premax;

	max = (*info)->number - 1;
	premax = max - 1;
	while ((*stack_a)->index != max && (*stack_a)->index != premax)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	while ((*stack_a)->index != max && (*stack_a)->index != premax)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_three_numbers(stack_a);
	if ((*stack_b)->index == max)
	{
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_b)->index == premax)
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
}

void	sort_four_elements(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack *temp;
	int 	max;
	int 	position;

	position = 0;
	max = (*info)->number - 1;
	temp = *stack_a;
	while (temp->index != max)
	{
		temp = temp->next;
		position++;
	}
	while ((*stack_a)->index != max)
	{
		if (position > (*info)->middle_value)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	sort_three_numbers(stack_a);
	push_a(stack_a, stack_b);
	rotate_a(stack_a);
}

void	sort_five_numbers(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	(void) *stack_b;
	if ((*info)->number <= 3)
		sort_three_numbers(stack_a);
	else if ((*info)->number == 4)
		sort_four_elements(stack_a, stack_b, info);
	else if ((*info)->number == 5)
		sort_five_elements(stack_a, stack_b, info);
}

void	sort_three_numbers(t_stack **stack_a)
{
	t_stack *temp;
	t_stack *next;

	temp = *stack_a;
	next = (*stack_a)->next;
	if (!temp)
		return ;
	if (temp->index == 0)
	{
		if (next && next->index == 2)
		{
			reverse_rotate_a(stack_a);
			swap_a(stack_a);
		}
	}
	else if (temp->index == 1)
	{
		if (next->index == 0)
			swap_a(stack_a);
		else if (next->index == 2)
			reverse_rotate_a(stack_a);
	}
	else if (temp->index == 2)
	{
		if (next->index == 0)
			rotate_a(stack_a);
		else if (next->index == 1)
		{
			swap_a(stack_a);
			reverse_rotate_a(stack_a);
		}
	}
}
