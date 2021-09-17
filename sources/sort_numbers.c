
#include "../includes/push_swap.h"

int number;

void	divide_into_two_stacks(t_stack *stack_a, t_info *info)
{
	t_stack	*stack_b;
	t_stack	*temp;
	int		position;

	stack_b = NULL;
	number = info->number;
	info->middle_value = info->number / 2;
	while (info->number)
	{
		temp = stack_a;
		position = 0;
		while (temp != NULL)
		{
			if (temp->index < info->middle_value)
			{
				temp->flag = 1;
				if (position >= info->number / 2 + 1)
					while (stack_a->index != temp->index)
						reverse_rotate_a(&stack_a);
				else
					while (stack_a->index != temp->index)
						rotate_a(&stack_a);
				push_b(&stack_a, &stack_b);
				temp = NULL;
			}
			else
				temp = temp->next;
			position++;
		}
		info->number--;
	}
	info->number = info->middle_value;
	info->middle_value = info->number / 2;
	divide_into_groups(stack_a, stack_b, info);
}

void	divide_into_groups(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_stack	*temp;

	info->flag = 0;
	info->remain = info->number;
	while (info->remain >= number / 6)
	{
		while (info->number)
		{
			temp = stack_b;
			while (temp != NULL)
			{
				if (temp->index > info->middle_value)
				{
					temp->flag += info->flag;
					while (stack_b->index != temp->index)
						rotate_b(&stack_b);
					push_a(&stack_a, &stack_b);
					info->remain--;
					temp = NULL;
				}
				else
					temp = temp->next;
			}
			info->number--;
		}
		info->flag++;
		info->number = info->middle_value;
		info->middle_value = info->middle_value / 2;
	}
	info->sorted = 0;
	sort_remains(&stack_a, &stack_b, &info);
	sort_groups(&stack_a, &stack_b, &info);
	print_stack(stack_a, "Список а после изменений\n");
	print_stack(stack_b, "Список b после изменений\n");
}

void	sort_remains(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack *temp;
	int 	position;

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
//				rotate_ab(stack_a, stack_b);
				(*info)->sorted++;
				(*info)->remain--;
				temp = NULL;
			}
			else
				temp = temp->next;
			position++;
		}
	}
}

void	sort_groups(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack *temp;

	while ((*info)->sorted < number)
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
	}
}

void	sort_greater_remains(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	t_stack 	*temp;

	(*info)->remain = (*info)->number;
	(*info)->middle_value = (*info)->number / 2;
	while ((*info)->remain >= number / 5)
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
	sort_remains(stack_a, stack_b, info);
}
