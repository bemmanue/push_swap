/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:35:30 by bemmanue          #+#    #+#             */
/*   Updated: 2021/12/17 15:35:32 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	check_result(t_stack *stack_a, int count)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		if (stack_a->index != i)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	if (i != count)
		return (0);
	return (1);
}

void	do_commands(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa", ft_strlen(line)))
		bns_swap_a(stack_a);
	else if (!ft_strncmp(line, "pa", ft_strlen(line)))
		bns_push_a(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra", ft_strlen(line)))
		bns_rotate_a(stack_a);
	else if (!ft_strncmp(line, "rra", ft_strlen(line)))
		bns_reverse_rotate_a(stack_a);
	else if (!ft_strncmp(line, "sb", ft_strlen(line)))
		bns_swap_b(stack_b);
	else if (!ft_strncmp(line, "pb", ft_strlen(line)))
		bns_push_b(stack_a, stack_b);
	else if (!ft_strncmp(line, "rb", ft_strlen(line)))
		bns_rotate_b(stack_b);
	else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
		bns_reverse_rotate_b(stack_b);
	else if (!ft_strncmp(line, "rr", ft_strlen(line)))
		bns_rotate_ab(stack_a, stack_b);
	else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
		bns_reverse_rotate_ab(stack_a, stack_b);
	else
		terminate();
}

int	start_checking(int count, int *set)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int		res;

	stack_a = fill_stack(count, set);
	if (!stack_a)
		terminate();
	stack_b = NULL;
	while (get_next_line(0, &line) > 0)
	{
		do_commands(&stack_a, &stack_b, line);
		free(line);
	}
	res = check_result(stack_a, count);
	return (res);
}

int	main(int argc, char **argv)
{
	int		*set;
	int		count;
	int		res;

	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = unify_string(argv);
			argc = count_argc(argv);
		}
		count = argc - 1;
		set = check_and_convert(count, ++argv);
		res = start_checking(count, set);
		if (res)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	return (0);
}
