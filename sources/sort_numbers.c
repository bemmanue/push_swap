
#include "../includes/push_swap.h"

void	put_up_element(t_stack **stack, int index, int position, int middle)
{
	if (position > middle)
		while ((*stack)->index != index)
			reverse_rotate_a(stack);
	else
		while ((*stack)->index != index)
			rotate_a(stack);
}

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
			put_up_element(stack_a, temp->index,
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

void	divide_into_groups(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack	*temp;
	int		position;
	int		limit;

	while ((*info)->remain > 3)
	{
		temp = *stack_b;
		limit = (*info)->middle;
		while (temp)
		{
			if (temp->index >= limit)
			{
				temp->flag += (*info)->flag;
				put_up_element(stack_b, temp->index,
							   position, (*info)->middle);
				push_a(stack_a, stack_b, info);
				temp = *stack_b;
				position = 0;
			}
			else
				temp = temp->next;
			position++;
		}
		(*info)->flag++;
	}
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

void	sort_groups(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int 	flag;

	while ((*info)->sorted < (*info)->number)
	{
		flag = (*stack_a)->flag;
		while ((*stack_a)->flag == flag && (*stack_a)->index != 0)
		{
			if (!check_fast_a_sorting(stack_a, info))
				push_b(stack_a, stack_b, info);
		}
		if ((*info)->remain > 3)
			sort_more_elements(stack_a, stack_b, info);
		sort_three_elements(stack_a, stack_b, info);
	}
}

void	sort_more_elements(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int		limit;
	int 	flag;
	int 	i;

	flag = 1;
	while ((*info)->remain > 3)
	{
		limit = (*info)->middle + (*info)->sorted;
		i = (*info)->middle - 1 + ((*info)->remain % 2);
		while (i && *stack_b)
		{
//			if ((*stack_b)->index - (*info)->sorted == 0
//			&& (*stack_b)->index > limit)
//			{
//				push_a(stack_a, stack_b, info);
//				rotate_a(stack_a);
//				(*info)->sorted++;
//				i--;
//			}
//			else
			if ((*stack_b)->index > limit)
			{
				(*stack_b)->flag += flag;
				push_a(stack_a, stack_b, info);
				i--;
			}
			else if (!check_fast_b_sorting(stack_a, stack_b, info))
				rotate_b(stack_b);
		}
		flag++;
	}
}

void	sort_three_elements(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack *temp;

	temp = *stack_b;
	if (!temp)
		return ;
	if (temp->index - (*info)->sorted == 0)
	{
		push_a(stack_a, stack_b, info);
		temp = *stack_b;
		if (!temp)
		{
			rotate_a(stack_a);
			(*info)->sorted++;
		}
		else if (temp->index - (*info)->sorted == 1)
		{
			rotate_a(stack_a);
			(*info)->sorted++;
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			(*info)->sorted++;
			temp = *stack_b;
			if (temp && temp->index - (*info)->sorted == 0)
			{
				push_a(stack_a, stack_b, info);
				rotate_a(stack_a);
				(*info)->sorted++;
			}
		}
		else if (temp->index - (*info)->sorted == 2)
		{
			rotate_ab(stack_a, stack_b);
			(*info)->sorted++;
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			(*info)->sorted++;
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			(*info)->sorted++;
		}
	}
	else if (temp->index - (*info)->sorted == 1)
	{
		push_a(stack_a, stack_b, info);
		temp = *stack_b;
		if (!temp)
		{
			rotate_a(stack_a);
			(*info)->sorted++;
		}
		else if (temp->index - (*info)->sorted == 0)
		{
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 2;
			temp = *stack_b;
			if (temp && temp->index - (*info)->sorted == 0)
			{
				push_a(stack_a, stack_b, info);
				rotate_a(stack_a);
				(*info)->sorted++;
			}
		}
		else if (temp->index - (*info)->sorted == 2)
		{
			push_a(stack_a, stack_b, info);
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			swap_a(stack_a);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 3;
		}
	}
	else if (temp->index - (*info)->sorted == 2)
	{
		push_a(stack_a, stack_b, info);
		temp = *stack_b;
		if (temp->index - (*info)->sorted == 0)
		{
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 3;
		}
		else if (temp->index - (*info)->sorted == 1)
		{
			push_a(stack_a, stack_b, info);
			push_a(stack_a, stack_b, info);
			rotate_a(stack_a);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 3;
		}
	}
}
