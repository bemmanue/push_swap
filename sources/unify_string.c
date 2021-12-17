/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unify_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:30:51 by bemmanue          #+#    #+#             */
/*   Updated: 2021/12/17 15:30:55 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_argc(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

char	**unify_string(char **argv)
{
	char	*temp;

	*argv = ft_strjoin("./push_swap ", argv[1]);
	if (!*argv)
		terminate();
	argv = ft_split(*argv, ' ');
	if (!argv || !*argv || !argv[1])
		terminate();
	temp = *argv;
	free(temp);
	return (argv);
}
