
#include "../includes/push_swap.h"

int operation = 0;

void	sort_numbers(t_stack *stack_a, t_info *info)
{
	t_stack *stack_b;
	t_stack *temp;
	int i;

	i = 1;
	stack_b = NULL;
	temp = stack_a;
	while (i < 16)
	{
		temp = stack_a;
		while (temp != NULL)
		{
			if (temp->index == i)
			{
				while (stack_a->index != i)
					rotate_a(&stack_a);
				push_b(&stack_a, &stack_b);
				operation++;
				temp = NULL;
			}
			else
				temp = temp->next;
		}
		i++;
	}
	i = 0;
	while (i < 15)
	{
		push_a(&stack_a, &stack_b);
		operation++;
		i++;
	}
	print_stack(stack_a, "Список а после изменений\n");
	printf("%d\n", operation);
}