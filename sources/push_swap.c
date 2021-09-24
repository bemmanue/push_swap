
#include "../includes/push_swap.h"

int operation;

int check_args(int argc, char **mass)
{
	int number[argc];
	int i;
	int j;
	int temp;

	i = 0;
	temp = argc;
	while (argc--)
	{
		number[i] = ft_atoi(mass[i]);
		i++;
	}
	i = 0;
	while (i < temp)
	{
		j = 0;
		while (j <= temp)
		{
			if (number[j] == number[i])
			{
				if (i != j)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

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

void get_args(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp;
	t_info	*info;
	int 	position;
	int		index;
	int		number;

	position = 0;
	info = malloc(sizeof(t_info));
	info->number = argc;
	info->main = argc;
	info->remain = 0;
	info->middle_value = info->main / 2;
	info->sorted = 0;
	info->flag = 0;
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
	stack_b = NULL;
	print_stack(stack_a, "Спискок а до изменений\n");
	if (info->number == 1)
		return ;
	else if (info->number <= 3)
		sort_three_numbers(&stack_a);
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
		if (!check_args(--argc, ++argv))
		{
			printf("Error\n");
			return (-1);
		}
		get_args(argc, argv);
		printf("operations = %d\n", operation);
	}
 	else
		printf("Напиши аргументы\n");
	return (0);
}