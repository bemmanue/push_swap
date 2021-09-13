
#include "../includes/push_swap.h"

void	divide_into_two_stacks(t_stack *stack_a, t_info *info)
{
	t_stack	*stack_b;
	t_stack	*temp;
	int		position;

	stack_b = NULL;
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
//	print_stack(stack_a, "Список а после изменений\n");
//	print_stack(*stack_b, "Список b после изменений\n");
	divide_into_groups(stack_a, stack_b, info);
}

void	divide_into_groups(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_stack	*temp;
	int		i;
	int		position;
	int		remain;

	info->flag = 0;
	info->number = info->middle_value;
	info->middle_value = info->number / 2;
	remain = info->number;
	while (remain >= 3)
	{
		i = 0;
		while (info->number)
		{
			temp = stack_b;
			position = 0;
			while (temp != NULL)
			{
				if (temp->index > info->middle_value)
				{
					temp->flag += info->flag;
					while (stack_b->index != temp->index)
						rotate_b(&stack_b);
					push_a(&stack_a, &stack_b);
					temp = NULL;
				}
				else
					temp = temp->next;
				position++;
			}
			info->number--;
		}
		info->flag++;
		info->number = info->middle_value;
		info->middle_value = info->middle_value / 2;
		remain = info->number;
	}
	sort_remains(stack_a, stack_b, info);
//	print_stack(stack_a, "Список а после изменений\n");
//	print_stack(stack_b, "Список b после изменений\n");
}

void	sort_remains(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_stack *temp;

	temp = stack_b;
	info->sorted = 0;
	if (temp->index == 1)
		swap_b(&stack_b);
	temp = stack_b;
	if (temp->index == 0)
	{
		push_a(&stack_a, &stack_b);
		rotate_a(&stack_a);
		info->sorted++;
		push_a(&stack_a, &stack_b);
		rotate_a(&stack_a);
		info->sorted++;
		temp = stack_b;
		if (temp && temp->index == 2)
		{
			push_a(&stack_a, &stack_b);
			rotate_a(&stack_a);
			info->sorted++;
		}
	}
	else if (temp->index == 2)
	{
		push_a(&stack_a, &stack_b);
		if (stack_b->index == 0)
			swap_b(&stack_b);
		push_a(&stack_a, &stack_b);
		push_a(&stack_a, &stack_b);
		rotate_a(&stack_a);
		info->sorted++;
		rotate_a(&stack_a);
		info->sorted++;
		rotate_a(&stack_a);
		info->sorted++;
	}
	sort_groups(stack_a, stack_b, info);
//	print_stack(stack_a, "Список а после изменений\n");
//	print_stack(stack_b, "Список b после изменений\n");
}

void	sort_groups(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	t_stack *temp;

	while (info->flag > 0)
	{
		info->number = 0;
		while (stack_a->flag == info->flag)
		{
			push_b(&stack_a, &stack_b);
			info->number++;
		}
		if (info->number <= 3)
		{
			printf("sorted = %d\n", info->sorted);
			temp = stack_b;
			if (temp->index - info->sorted == 1)
				swap_b(&stack_b);
			temp = stack_b;
			if (temp->index - info->sorted == 0)
			{
				push_a(&stack_a, &stack_b);
				rotate_a(&stack_a);
				info->sorted++;
				push_a(&stack_a, &stack_b);
				rotate_a(&stack_a);
				info->sorted++;
				temp = stack_b;
				if (temp && temp->index - info->sorted == 2)
				{
					push_a(&stack_a, &stack_b);
					rotate_a(&stack_a);
					info->sorted++;
				}
			}
			else if (temp->index - info->sorted == 2)
			{
				push_a(&stack_a, &stack_b);
				if (stack_b->index - info->sorted == 0)
					swap_b(&stack_b);
				push_a(&stack_a, &stack_b);
				push_a(&stack_a, &stack_b);
				rotate_a(&stack_a);
				info->sorted++;
				rotate_a(&stack_a);
				info->sorted++;
				rotate_a(&stack_a);
				info->sorted++;
			}
		}
		else
			info->flag = 0;
		info->flag--;
	}
	print_stack(stack_a, "Список а после изменений\n");
	print_stack(stack_b, "Список b после изменений\n");
	printf("sorted = %d\n", info->sorted);
}
