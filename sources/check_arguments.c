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

#include "../includes/push_swap.h"

static int	already_sorted(int count, int *set)
{
	int	i;

	i = 0;
	while (count--)
	{
		if (set[i] > set[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	check_digits(int count, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				if (args[i][j] != '-'
				|| (args[i][j] == '-' && !ft_isdigit(args[i][j + 1])))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_repeats(int count, int *set)
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
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	*fill_set(int count, char **args)
{
	int	*set;
	int	i;

	i = 0;
	set = malloc(sizeof(int) * count);
	if (!set)
		return (0);
	while (i < count)
	{
		set[i] = ft_atoi(args[i]);
		i++;
	}
	return (set);
}

int	check_arguments(int count, char **args)
{
	int	*set;

	if (!check_digits(count, args))
		return (0);
	set = fill_set(count, args);
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
