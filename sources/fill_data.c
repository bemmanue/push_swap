
#include "../includes/push_swap.h"

static int	count_index(char **mass, int number)
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
	info->middle = info->main / 2;
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