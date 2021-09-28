
#include "../includes/push_swap.h"

int operation;

void	start_sorting(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;

	info = fill_info(argc);
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	print_stack(stack_a, "Спискок а до изменений\n");
	if (info->number == 1)
		return ;
	else if (info->number < 6)
		sort_few_numbers(&stack_a, &stack_b, &info);
	else
	{
		divide_stacks(&stack_a, &stack_b, &info);
		divide_into_groups(&stack_a, &stack_b, &info);
		sort_three_elements(&stack_a, &stack_b, &info);
		sort_groups(&stack_a, &stack_b, &info);
	}
	print_stack(stack_a, "Список a после изменений");
	print_stack(stack_b, "Список b после изменений");
	printf("info->main = %d\n", info->main);
	printf("info->remain = %d\n", info->remain);
	printf("info->sorted = %d\n", info->sorted);
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
		printf("operations = %d\n", operation);
	}
 	else
		printf("Напиши аргументы\n");
	return (0);
}