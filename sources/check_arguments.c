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

static int	check_digits(int count, char **args)
{
	int	digit;
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		digit = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				if (args[i][j] != '-' || digit > 11
				|| (args[i][j] == '-' && !ft_isdigit(args[i][j + 1])))
					return (0);
			}
			j++;
			digit++;
		}
		i++;
	}
	return (1);
}

static int	*fill_set(int count, char **args)
{
	int		*set;
	int		i;
	long	number;

	i = 0;
	set = malloc(sizeof(int) * count);
	if (!set)
		return (0);
	while (i < count)
	{
		number = ft_atol((args[i]));
		if (number > 2147483647 || number < -2147483648)
		{
			free(set);
			return (NULL);
		}
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
		return (3);
	}
	free(set);
	return (1);
}
