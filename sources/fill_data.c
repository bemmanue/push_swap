/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:56:44 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/04 13:56:46 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_index(int *set, int count, int number)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (i < count)
	{
		if (number > set[i])
			index++;
		i++;
	}
	return (index);
}

t_info	*fill_info(int count)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->number = count;
	info->main = count;
	info->remain = 0;
	info->middle = info->main / 2;
	info->sorted = 0;
	info->flag = 0;
	return (info);
}

t_stack	*fill_stack(int count, int *set)
{
	t_stack	*stack_a;
	t_stack	*temp;
	int		i;

	i = 0;
	stack_a = new_stack(count_index(set, count, set[i++]));
	if (!stack_a)
		return (NULL);
	temp = stack_a;
	while (i < count)
	{
		temp->next = new_stack(count_index(set, count, set[i]));
		if (!temp->next)
			return (NULL);
		temp = temp->next;
		i++;
	}
	return (stack_a);
}
