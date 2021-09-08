
#include "../includes/push_swap.h"

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
	index = 1;
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
	t_stack	*temp_a;
	t_info	*info;
	int 	i;

	i = 0;
	info = malloc(sizeof(t_info));
	info->count = argc;
	stack_a = ft_lstnew_ps(ft_atoi(argv[i]),
						   count_index(argv, ft_atoi(argv[i])));
	temp_a = stack_a;
	while (--argc)
	{
		++i;
		temp_a->next = ft_lstnew_ps(ft_atoi(argv[i]),
									count_index(argv, ft_atoi(argv[i])));
		temp_a = temp_a->next;
	}

	print_stack(stack_a, "Спискок а до изменений\n");
	sort_numbers(stack_a, info);
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
	}
 	else
		printf("Напиши аргументы\n");
	return (0);
}