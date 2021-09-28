
#include "../includes/push_swap.h"

void	put_up_element(t_stack **stack, int index, int position, int i)
{
	if (position > i)
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
	int		limit;

	temp = *stack_a;
	position = 0;
	limit = (*info)->main / 2;
	while (temp)
	{
		if (temp->index < limit)
		{
			temp->flag = 1;
			put_up_element(stack_a, temp->index,
						   position,(*info)->main / 2);
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

void	sort_groups(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack *temp;
	t_stack *next;
	int 	flag;

	next = (*stack_a)->next;
	while ((*info)->sorted < (*info)->number)
	{
		temp = *stack_a;
		flag = (*stack_a)->flag;
		while (temp->flag == flag && temp->index != 0)
		{
			if (temp->index - (*info)->sorted == 0)
			{
				rotate_a(stack_a);
				(*info)->sorted++;
			}
			else if (temp->index - (*info)->sorted == 1
			&& next->index - (*info)->sorted == 0)
			{
				swap_a(stack_a);
				rotate_a(stack_a);
				rotate_a(stack_a);
				(*info)->sorted += 2;
			}
			else
				push_b(stack_a, stack_b, info);
			temp = *stack_a;
			next = (*stack_a)->next;
		}
		if ((*info)->remain > 3)
			sort_more_elements(stack_a, stack_b, info);
		sort_three_elements(stack_a, stack_b, info);
	}
}

void	sort_more_elements(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack	*temp;
	int		flag;
	int 	limit;

	flag = 1;
	(*info)->middle = (*info)->remain / 2;
	limit = (*info)->middle;
	while ((*info)->remain > 3)
	{
		temp = *stack_b;
		while (temp)
		{
			if ((*stack_b)->index - (*info)->sorted == 0)
			{
				push_a(stack_a, stack_b, info);
				rotate_a(stack_a);
				(*info)->sorted++;
				temp = *stack_b;
				limit = (*info)->middle;
			}
			else if ((*stack_b)->next && (*stack_b)->index - (*info)->sorted == 1
				&& (*stack_b)->next->index - (*info)->sorted == 0)
			{
				push_a(stack_a, stack_b, info);
				push_a(stack_a, stack_b, info);
				rotate_a(stack_a);
				rotate_a(stack_a);
				(*info)->sorted += 2;
				temp = *stack_b;
				limit = (*info)->middle;
			}
			else if (temp->index - (*info)->sorted > limit)
			{
				temp->flag += flag;
				while ((*stack_b)->index != temp->index)
					rotate_b(stack_b);
				push_a(stack_a, stack_b, info);
				temp = *stack_b;
			}
			else
				temp = temp->next;
		}
		flag++;
		limit = (*info)->middle;
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
