
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
	int		flag;

	flag = 1;
	while ((*info)->remain > 3)
	{
		temp = *stack_b;
		while (temp)
		{
			if (temp->index > (*info)->middle_value)
			{
				temp->flag += flag;
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
		flag++;
		(*info)->middle_value = (*info)->remain / 2;
	}
}

void	sort_remains(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack *temp;
	int 	position;

//	if ((*info)->remain <= 3)
//		sort_three_elements(stack_a, stack_b, info);
//	else
//	{
		while ((*info)->remain > 0)
		{
			temp = *stack_b;
			position = 0;
			while (temp != NULL)
			{
				if (temp->index - (*info)->sorted == 0)
				{
					if (position >= (*info)->remain / 2 + 1)
						while ((*stack_b)->index != temp->index)
							reverse_rotate_b(stack_b);
					else
						while ((*stack_b)->index != temp->index)
							rotate_b(stack_b);
					push_a(stack_a, stack_b);
					rotate_a(stack_a);
					(*info)->sorted++;
					(*info)->remain--;
					temp = NULL;
				}
				else
				{
					temp = temp->next;
					position++;
				}
			}
		}
//	}
}

void	sort_groups(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack *temp;

	while ((*info)->sorted < (*info)->number)
	{
		temp = *stack_a;
		(*info)->number = 0;
		while (temp->flag == (*info)->flag)
		{
			push_b(stack_a, stack_b);
			(*info)->number++;
			temp = *stack_a;
		}
		(*info)->flag--;
		sort_greater_remains(stack_a, stack_b, info);
		sort_remains(stack_a, stack_b, info);
	}
}

void	sort_greater_remains(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack 	*temp;

	(*info)->remain = (*info)->number;
	(*info)->middle_value = (*info)->number / 2;
	while ((*info)->remain >= 30)
	{
		while ((*info)->number)
		{
			temp = *stack_b;
			while (temp != NULL)
			{
				if (temp->index - (*info)->sorted > (*info)->middle_value)
				{
					while ((*stack_b)->index != temp->index)
						rotate_b(stack_b);
					push_a(stack_a, stack_b);
					temp = NULL;
					(*info)->remain--;
				}
				else
					temp = temp->next;
			}
			(*info)->number--;
		}
		(*info)->flag++;
		(*info)->number = (*info)->middle_value;
		(*info)->middle_value = (*info)->middle_value / 2;
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
		(*info)->sorted++;
		(*info)->remain--;
		temp = *stack_b;
		if (!temp)
			rotate_a(stack_a);
		else if (temp->index - (*info)->sorted == 0)
		{
			rotate_a(stack_a);
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			(*info)->sorted++;
			(*info)->remain--;
			temp = *stack_b;
			if (temp && temp->index - (*info)->sorted == 0)
			{
				push_a(stack_a, stack_b);
				rotate_a(stack_a);
				(*info)->sorted++;
				(*info)->remain--;
			}
		}
		else if (temp->index - (*info)->sorted == 1)
		{
			rotate_ab(stack_a, stack_b);
			push_a(stack_a, stack_b);
			(*info)->sorted++;
			(*info)->remain--;
			push_a(stack_a, stack_b);
			(*info)->sorted++;
			(*info)->remain--;
		}
	}
	else if (temp->index - (*info)->sorted == 1)
	{
		push_a(stack_a, stack_b);
		(*info)->sorted++;
		(*info)->remain--;
		temp = *stack_b;
		if (!temp)
			rotate_a(stack_a);
		else if (temp->index - (*info)->sorted == 0)
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted++;
			(*info)->remain--;
			temp = *stack_b;
			if (temp && temp->index - (*info)->sorted == 1)
			{
				push_a(stack_a, stack_b);
				rotate_a(stack_a);
				(*info)->sorted++;
				(*info)->remain--;
			}
		}
		else if (temp->index - (*info)->sorted == 1)
		{
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			swap_a(stack_a);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 2;
			(*info)->remain -= 2;
		}
	}
	else if (temp->index - (*info)->sorted == 2)
	{
		push_a(stack_a, stack_b);
		(*info)->sorted++;
		(*info)->remain--;
		temp = *stack_a;
		if (temp->index - (*info)->sorted == 0)
		{
			rotate_b(stack_b);
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 2;
			(*info)->remain -= 2;
		}
		else if (temp->index - (*info)->sorted == 1)
		{
			push_a(stack_a, stack_b);
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			rotate_a(stack_a);
			rotate_a(stack_a);
			(*info)->sorted += 2;
			(*info)->remain -= 2;
		}
	}
	printf("three elements\n");
}
