
#include "../includes/push_swap.h"

int operation;

int count_index(char **mass, int number)
{
	int index;
	int i;

	i = 0;
	index = 0;
	while (mass[i])
	{
		if (number > ft_atoi(mass[i]))
			index++;
		i++;
	}
	return (index);
}

t_info	*fill_info(int argc)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->number = argc;
	info->main = argc;
	info->remain = 0;
	info->middle_value = info->main / 2;
	info->sorted = 0;
	info->flag = 0;
	return (info);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*temp;
	int 	position;
	int		index;
	int		number;

	position = 0;
	number = ft_atoi(argv[position]);
	index = count_index(argv, ft_atoi(argv[position]));
	stack_a = ft_lstnew_ps(number, index);
	temp = stack_a;
	while (--argc)
	{
		++position;
		number = ft_atoi(argv[position]);
		index = count_index(argv, ft_atoi(argv[position]));
		temp->next = ft_lstnew_ps(number, index);
		temp = temp->next;
	}
	return (stack_a);
}

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
	else if (info->number <= 5)
		sort_five_numbers(&stack_a, &stack_b, &info);
	else
	{
		divide_into_two_stacks(&stack_a, &stack_b, &info);
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