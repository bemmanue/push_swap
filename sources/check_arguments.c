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

int	already_sorted(int count, int *set)
{
	int	i;

	i = 0;
	while (i < count - 1)
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
			if (set[j] == set[i] && i != j)
				terminate();
			j++;
		}
		i++;
	}
}

static void	check_digits(char *arg)
{
	int	i;
	int	digit;

	i = 0;
	digit = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			terminate();
		i++;
		digit++;
	}
	if (!digit || digit > 10)
		terminate();
}

static int	*fill_set(int count, char **args)
{
	int			*set;
	int			i;
	long long	temp;

	i = 0;
	set = malloc(sizeof(int) * count);
	if (!set)
		terminate();
	while (i < count)
	{
		temp = ft_atol((args[i]));
		if (temp > 2147483647 || temp < -2147483648)
		{
			free(set);
			terminate();
		}
		set[i] = ft_atoi(args[i]);
		i++;
	}
	return (set);
}

int	*check_and_convert(int count, char **args)
{
	int	*set;
	int	i;

	i = 0;
	while (i < count)
	{
		check_digits(args[i]);
		i++;
	}
	set = fill_set(count, args);
	check_repeats(count, set);
	return (set);
}
