
#include "../includes/push_swap.h"

static int check_digits(char *str)
{
	int i;
	int digit;

	i = 0;
	digit = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if ((str[i] != '-' && str[i] != ' ') || digit > 11
			|| (str[i] == '-' && !ft_isdigit(str[i + 1]))
			|| (ft_isdigit(str[i]) && str[i + 1] == '-'))
				return (0);
			digit = 0;
		}
		i++;
		digit++;
	}
	return (1);
}

int	count_numbers(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
		{
			if (str[i] == '-')
				i++;
			while (ft_isdigit(str[i]))
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

static int	*fill_set(char *str, int size)
{
	int		*set;
	long	number;
	int		i;

	i = 0;
	set = malloc(sizeof(int) * size);
	if (!set)
		return (NULL);
	while (*str)
	{
		if (ft_isdigit(*str) || *str == '-')
		{
			number = ft_atol(str);
			if (number > 2147483647 || number < -2147483648)
			{
				free(set);
				return (NULL);
			}
			set[i++] = ft_atoi(str);
			while (ft_isdigit(*str) || *str == '-')
				str++;
		}
		str++;
	}
	return (set);
}

int	check_string(char *argv)
{
	int *set;
	int count;

	if (!check_digits(argv))
		return (0);
	count = count_numbers(argv);
	if (!count)
		return (0);
	set = fill_set(argv, count);
	if (!set)
		return (0);
	if (!check_repeats(count, set))
	{
		free(set);
		return (0);
	}
	if (already_sorted(count, set))
	{
		free(set);
		return (2);
	}
	free(set);
	return (1);
}