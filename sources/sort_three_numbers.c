
#include "../includes/push_swap.h"

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
