
#include "../includes/push_swap.h"

void	put_up_element_b(t_stack **stack, int index, int position, int middle)
{
	if (position > middle)
		while ((*stack)->index != index)
			reverse_rotate_b(stack);
		else
			while ((*stack)->index != index)
				rotate_b(stack);
}

void	put_up_element_a(t_stack **stack, int index, int position, int middle)
{
	if (position > middle)
		while ((*stack)->index != index)
			reverse_rotate_a(stack);
	else
		while ((*stack)->index != index)
			rotate_a(stack);
}

int	check_fast_a_sorting(t_stack **stack_a, t_info **info)
{
	t_stack *next;

	next = (*stack_a)->next;
	if ((*stack_a)->index - (*info)->sorted == 0)
	{
		rotate_a(stack_a);
		(*info)->sorted++;
		return (1);
	}
	else if ((*stack_a)->index - (*info)->sorted == 1
	&& next->index - (*info)->sorted == 0)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
		(*info)->sorted += 2;
		return (1);
	}
	return (0);
}

int	check_fast_b_sorting(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	if ((*stack_b)->index - (*info)->sorted == 0)
	{
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		(*info)->sorted++;
		return (1);
	}
	else if ((*stack_b)->next && (*stack_b)->index - (*info)->sorted == 1
	&& (*stack_b)->next->index - (*info)->sorted == 0)
	{
		push_a(stack_a, stack_b, info);
		push_a(stack_a, stack_b, info);
		rotate_a(stack_a);
		rotate_a(stack_a);
		(*info)->sorted += 2;
		return (1);
	}
	return (0);
}
