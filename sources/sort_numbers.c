
#include "../includes/push_swap.h"

int operation;

void	sort_numbers(t_stack *stack_a, t_info *info)
{
	t_stack *stack_b;
	t_stack *temp;
	int i;
	int flag;
	int min;
	int a;
	int b;

	i = 0;
	flag = 0;
	stack_b = NULL;
	info->middle_value = info->count / 2;
	while (i < info->count)
	{
		temp = stack_a;
		while (temp != NULL)
		{
			if (temp->index <= info->middle_value)
			{
				temp->flag++;
				while (stack_a->index != temp->index)
					rotate_a(&stack_a);
				push_b(&stack_a, &stack_b);
				temp = NULL;
			}
			else
			{
				temp->flag = 0;
				temp = temp->next;
			}
		}
		i++;
	}
	i = 0;
	info->count = info->middle_value;
	info->middle_value = info->count / 2;
	while (info->count > 3)
	{
		i = 0;
		while (i < info->count)
		{
			temp = stack_b;
			while (temp != NULL)
			{
				if (temp->index > info->middle_value)
				{
					temp->flag += flag;
					while (stack_b->index != temp->index)
						rotate_b(&stack_b);
					push_a(&stack_a, &stack_b);
					temp = NULL;
				}
				else
				{
					temp = temp->next;
				}
			}
			i++;
		}
		flag++;
		info->count = info->middle_value;
		printf("numbers = %d\n", info->count);
		info->middle_value = info->middle_value / 2;
	}
	temp = stack_b;
	if (temp->index == 1)
	{
		push_a(&stack_a, &stack_b);
		if (stack_a->next != NULL)
			rotate_a(&stack_a);
		temp = stack_b;
		if (temp && temp->index == 2)
		{
			push_a(&stack_a, &stack_b);
			rotate_a(&stack_a);
		}
		temp = stack_b;
		if (temp && temp->index == 3)
		{
			push_a(&stack_a, &stack_b);
			rotate_a(&stack_a);
		}
	}
	else if (temp->index == 2)
	{
		swap_b(&stack_b);
		temp = stack_b;
		if (temp->index == 1)
		{
			push_a(&stack_a, &stack_b);
			rotate_a(&stack_a);
		}
		temp = stack_b;
		if (temp->index == 2)
		{
			push_a(&stack_a, &stack_b);
			rotate_a(&stack_a);
			temp = stack_b;
			if (temp && temp->index == 3)
			{
				push_a(&stack_a, &stack_b);
				rotate_a(&stack_a);
			}
		}
	}
	else if (temp->index == 3)
	{
		push_a(&stack_a, &stack_b);
		temp = stack_b;
		if (temp && temp->index == 1)
			rotate_b(&stack_b);
		push_a(&stack_a, &stack_b);
		push_a(&stack_a, &stack_b);
		rotate_a(&stack_a);
		rotate_a(&stack_a);
		rotate_a(&stack_a);
	}
	temp = stack_a;
	min = 4;
	while (stack_a->flag == flag)
	{
		temp = stack_a;
		push_b(&stack_a, &stack_b);
	}
	print_stack(stack_a, "Список а после изменений\n");
	print_stack(stack_b, "Список b после изменений\n");
}
