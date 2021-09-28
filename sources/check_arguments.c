
#include "../includes/push_swap.h"

static int	check_digits(int count, char **args)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (args[i][j])
		{
			if (!isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_repeats(int count, int *set)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (set[j] == set[i])
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

int check_arguments(int count, char **args)
{
	int *set;
	int i;

	i = 0;
	if (!check_digits(count, args))
		return (0);
	set = malloc(sizeof(int) * count);
	while (i < count)
	{
		set[i] = ft_atoi(args[i]);
		i++;
	}
	if (!check_repeats(count, set))
		return (0);
	return (1);
}