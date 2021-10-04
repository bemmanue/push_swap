
#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, char *str)
{
	t_stack	*temp;

	temp = stack;
	printf("%s\n", str);
	while (temp != NULL)
	{
		printf("number = %5d   ", temp->number);
		printf("index = %d", temp->index);
		printf("    flag = %d\n", temp->flag);
		temp = temp->next;
	}
}

void	start_sorting(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;

	if (argc == 1)
		return ;
	info = fill_info(argc);
	stack_a = fill_stack(argc, argv);
//	print_stack(stack_a, "Stack_a:");
	stack_b = NULL;
	if (info->number < 6)
		sort_few_numbers(&stack_a, &stack_b, &info);
	else
		sort_many_numbers(&stack_a, &stack_b, &info);
	free(info);
	free_stack(&stack_a);
}

int main(int argc, char **argv)
{
 	if (argc > 1)
	{
		if (!check_arguments(--argc, ++argv))
		{
			printf("Error\n");
			return (-1);
		}
		start_sorting(argc, argv);
	}
 	else
		printf("Error\n");
	return (0);
}