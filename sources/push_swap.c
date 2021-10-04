/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:57:04 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/04 13:57:05 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	start_sorting(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;

	if (argc == 1)
		return ;
	info = fill_info(argc);
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	if (info->number < 6)
		sort_few_numbers(&stack_a, &stack_b, &info);
	else
		sort_many_numbers(&stack_a, &stack_b, &info);
	free(info);
	free_stack(&stack_a);
}

int	main(int argc, char **argv)
{
	int	check;

	if (argc > 1)
	{
		check = check_arguments(--argc, ++argv);
		if (check == 0)
		{
			ft_putstr_fd("Error\n", 1);
			return (-1);
		}
		else if (check == 2)
			return (0);
		else
			start_sorting(argc, argv);
	}
	else
		ft_putstr_fd("Error\n", 1);
	return (0);
}
