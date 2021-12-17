/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:57:04 by bemmanue          #+#    #+#             */
/*   Updated: 2021/12/10 18:24:53 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	start_sorting(int count, int *set)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;

	info = fill_info(count);
	if (!info)
		terminate();
	stack_a = fill_stack(count, set);
	if (!stack_a)
		terminate();
	stack_b = NULL;
	if (info->number < 6)
		sort_few_numbers(&stack_a, &stack_b, &info);
	else
		sort_many_numbers(&stack_a, &stack_b, &info);
	free(info);
	free_stack(&stack_a);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*set;
	int	count;

	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = unify_string(argv);
			argc = count_argc(argv);
		}
		count = argc - 1;
		set = check_and_convert(count, ++argv);
		if (!already_sorted(count, set) && count > 1)
			start_sorting(count, set);
	}
	return (0);
}
