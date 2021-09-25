
#include "../includes/push_swap.h"

void	divide_into_two_stacks(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack	*temp;
	int		position;

	position = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index < (*info)->middle_value)
		{
			if (temp->index == 0)
				temp->flag = -1;
			else
				temp->flag = 1;
			if (position > (*info)->middle_value)
				while ((*stack_a)->index != temp->index)
					reverse_rotate_a(stack_a);
			else
				while ((*stack_a)->index != temp->index)
					rotate_a(stack_a);
			push_b(stack_a, stack_b);
			(*info)->main--;
			(*info)->remain++;
			temp = *stack_a;
			position = 0;
		}
		else
		{
			temp = temp->next;
			position++;
		}
	}
	(*info)->middle_value = (*info)->remain / 2;
}

void	divide_into_groups(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack	*temp;
	int		position;

	while ((*info)->remain > 3)
	{
		temp = *stack_b;
		while (temp)
		{
			if (temp->index >= (*info)->middle_value)
			{
				temp->flag += (*info)->flag;
				if (position >= (*info)->main / 2 + 1)
					while ((*stack_b)->index != temp->index)
						reverse_rotate_b(stack_b);
				else
					while ((*stack_b)->index != temp->index)
						rotate_b(stack_b);
				push_a(stack_a, stack_b);
				(*info)->remain--;
				(*info)->main++;
				temp = *stack_b;
				position = 0;
			}
			else
			{
				temp = temp->next;
				position++;
			}
		}
		(*info)->flag++;
		(*info)->middle_value = (*info)->remain / 2;
	}
}

void	sort_remains(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack *temp;
	int 	position;
	int		i;

	i = 1;
	if ((*info)->remain <= 3)
		sort_three_elements(stack_a, stack_b, info);
	else
	{
		while ((*info)->remain > 0)
		{
			temp = *stack_b;
			while (temp)
			{
				if (temp->index - (*info)->sorted == 0)
				{
					temp->flag += i;
					if (position >= (*info)->main / 2 + 1)
						while ((*stack_b)->index != temp->index)
							reverse_rotate_b(stack_b);
					else
						while ((*stack_b)->index != temp->index)
							rotate_b(stack_b);
					push_a(stack_a, stack_b);
					rotate_a(stack_a);
					(*info)->remain--;
					(*info)->main++;
					(*info)->sorted++;
					temp = *stack_b;
					position = 0;
				}
				else
				{
					temp = temp->next;
					position++;
				}
			}
			i++;
		}
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
		while (temp->flag == flag)
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
			{
				push_b(stack_a, stack_b);
				(*info)->remain++;
				(*info)->main--;
			}
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

	flag = 1;
	(*info)->middle_value = (*info)->remain / 2;
	while ((*info)->remain > 3)
	{
		temp = *stack_b;
		while (temp)
		{
			if ((*stack_b)->index - (*info)->sorted == 0)
			{
				push_a(stack_a, stack_b);
				rotate_a(stack_a);
				(*info)->sorted++;
				(*info)->remain--;
				(*info)->main++;
				temp = *stack_b;
				(*info)->middle_value = (*info)->remain / 2;
			}
			else if ((*stack_b)->next && (*stack_b)->index - (*info)->sorted == 1
				&& (*stack_b)->next->index - (*info)->sorted == 0)
			{
				push_a(stack_a, stack_b);
				push_a(stack_a, stack_b);
				rotate_a(stack_a);
				rotate_a(stack_a);
				(*info)->sorted += 2;
				(*info)->remain -= 2;
				(*info)->main += 2;
				temp = *stack_b;
				(*info)->middle_value = (*info)->remain / 2;
			}
			else if (temp->index - (*info)->sorted > (*info)->middle_value)
			{
				temp->flag += flag;
				while ((*stack_b)->index != temp->index)
					rotate_b(stack_b);
				push_a(stack_a, stack_b);
				(*info)->remain--;
				(*info)->main++;
				temp = *stack_b;
			}
			else
				temp = temp->next;
		}
		flag++;
		(*info)->middle_value = (*info)->remain / 2;
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
		push_a(stack_a, stack_b);
		(*info)->remain--;
		(*info)->main++;
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
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			(*info)->sorted++;
			(*info)->remain--;
			(*info)->main++;
			temp = *stack_b;
			if (temp && temp->index - (*info)->sorted == 0)
			{
				push_a(stack_a, stack_b);
				rotate_a(stack_a);
				(*info)->sorted++;
				(*info)->remain--;
				(*info)->main++;
			}
		}
		else if (temp->index - (*info)->sorted == 2)
		{
			rotate_ab(stack_a, stack_b);
			(*info)->sorted++;
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			(*info)->sorted++;
			(*info)->remain--;
			(*info)->main++;
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			(*info)->sorted++;
			(*info)->remain--;
			(*info)->main++;
		}
	}
	else if (temp->index - (*info)->sorted == 1)
	{
		push_a(stack_a, stack_b);
		(*info)->remain--;
		(*info)->main++;
		temp = *stack_b;
		if (!temp)
		{
			rotate_a(stack_a);
			(*info)->sorted++;
		}
		else if (temp->index - (*info)->sorted == 0)
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 2;
			(*info)->remain--;
			(*info)->main++;
			temp = *stack_b;
			if (temp && temp->index - (*info)->sorted == 0)
			{
				push_a(stack_a, stack_b);
				rotate_a(stack_a);
				(*info)->sorted++;
				(*info)->remain--;
				(*info)->main++;
			}
		}
		else if (temp->index - (*info)->sorted == 2)
		{
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			swap_a(stack_a);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 3;
			(*info)->remain -= 2;
			(*info)->main += 2;
		}
	}
	else if (temp->index - (*info)->sorted == 2)
	{
		push_a(stack_a, stack_b);
		(*info)->remain--;
		(*info)->main++;
		temp = *stack_b;
		if (temp->index - (*info)->sorted == 0)
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 3;
			(*info)->remain -= 2;
			(*info)->main += 2;
		}
		else if (temp->index - (*info)->sorted == 1)
		{
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 3;
			(*info)->remain -= 2;
			(*info)->main += 2;
		}
	}
}
