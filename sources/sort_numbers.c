
#include "../includes/push_swap.h"

int operation;

void	sort_numbers(t_stack *stack_a, t_info *info)
{
	t_stack *stack_b;
	t_stack *temp;
	int i;

	i = 0;
	stack_b = NULL;
	info->middle_element = info->count / 2;
	temp = stack_a;
	while (i < info->count)
	{
		temp = stack_a;
		while (temp != NULL)
		{
			if (temp->index <= info->middle_element)
			{
				while (stack_a->index != temp->index)
					rotate_a(&stack_a);
				push_b(&stack_a, &stack_b);
				temp = NULL;
			}
			else
				temp = temp->next;
		}
		i++;
	}
	print_stack(stack_a, "Список а после изменений\n");
	print_stack(stack_b, "Список b после изменений\n");
}