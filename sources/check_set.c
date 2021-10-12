/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:11:15 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/08 20:11:18 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(int count, int *set)
{
	int	i;

	i = 0;
	while (--count)
	{
		if (set[i] > set[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_repeats(int count, int *set)
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
