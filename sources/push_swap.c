/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:57:04 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/13 15:10:23 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_sorting(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;

	if (argc == 1)
		return (1);
	info = fill_info(argc);
	stack_a = fill_stack(argc, argv);
	if (!info || !stack_a)
	{
		free(info);
		free_stack(&stack_a);
		return (0);
	}
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
	int		check;
	char	*temp;

	if (argc > 1)
	{
		if (argc == 2)
		{
			*argv = ft_strjoin("./push_swap ", argv[1]);
			if (!*argv)
				terminate();
			argv = ft_split(*argv, ' ');
			if (!argv || !*argv)
				terminate();
			argc = count_argc(argv);
			temp = *argv;
			free (temp);
		}
		check = check_arguments(--argc, ++argv);
		if (check == 1 && !start_sorting(argc, argv))
			terminate();
	}
	return (0);
}
