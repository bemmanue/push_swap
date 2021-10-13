/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:56:34 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/04 13:56:37 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_already_sorted(int count, int *set)
{
	int	i;

	i = 0;
	while (--count > 0)
	{
		if (set[i] > set[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	check_repeats(int count, int *set)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (set[j] == set[i])
			{
				if (i != j)
					terminate();
			}
			j++;
		}
		i++;
	}
}

static void	check_digits(int count, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) && (args[i][j + 1]) == '-')
				terminate();
			if (!ft_isdigit(args[i][j]))
			{
				if (args[i][j] != '-'
				|| (args[i][j] == '-' && !ft_isdigit(args[i][j + 1])))
					terminate();
			}
			j++;
		}
		i++;
	}
}

static int	*fill_set(int count, char **args)
{
	int		*set;
	int		i;
	int		len;
	long	number;

	i = 0;
	set = malloc(sizeof(int) * count);
	if (!set)
		return (0);
	while (i < count)
	{
		len = ft_strlen((args[i]));
		number = ft_atol((args[i]));
		if ((number > 2147483647 || number < -2147483648) && len > 11)
			return (NULL);
		set[i] = ft_atoi(args[i]);
		i++;
	}
	return (set);
}

int	check_arguments(int count, char **args)
{
	int	*set;

	check_digits(count, args);
	set = fill_set(count, args);
	if (!set)
		terminate();
	check_repeats(count, set);
	if (check_already_sorted(count, set))
	{
		free(set);
		return (2);
	}
	free(set);
	return (1);
}
