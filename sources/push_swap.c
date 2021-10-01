
#include "../includes/push_swap.h"

int operation;

void	start_sorting(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;

	if (argc == 1)
		return ;
	info = fill_info(argc);
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
//	print_stack(stack_a, "Список а до изменений");
	if (info->number < 6)
		sort_few_numbers(&stack_a, &stack_b, &info);
	else
		sort_many_numbers(&stack_a, &stack_b, &info);
//	print_stack(stack_a, "Список a после изменений");
	free(info);
	free(stack_a);
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
//		printf("operations = %d\n", operation);
	}
 	else
		printf("Напиши аргументы\n");
	return (0);
}