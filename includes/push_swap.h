/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:17:20 by bemmanue          #+#    #+#             */
/*   Updated: 2021/10/08 20:17:22 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_info
{
	int				middle;
	int				number;
	int				remain;
	int				main;
	int				flag;
	int				sorted;
}					t_info;

typedef struct s_stack
{
	int				number;
	int				index;
	int				flag;
	struct s_stack	*next;
}					t_stack;

int		count_argc(char **str);
int		check_arguments(int argc, char **args);
int		start_sorting(int argc, char **argv);

t_stack	*fill_stack(int argc, char **argv);
t_info	*fill_info(int argc);

void	sort_three_numbers(t_stack **stack_a);
void	sort_few_numbers(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	sort_many_numbers(t_stack **stack_a, t_stack **stack_b, t_info **info);

void	divide_stacks(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	sort_groups(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	sort_three_element(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	sort_more_elements(t_stack **stack_a, t_stack **stack_b, t_info **info);

void	put_up_element_a(t_stack **stack, int index, int position, int middle);
void	put_up_element_b(t_stack **stack, int index);
int		fast_a_sorting(t_stack **stack_a, t_info **info);
int		fast_b_sorting(t_stack **stack_a, t_stack **stack_b, t_info **info);

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	push_b(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);

t_stack	*last_stack(t_stack *lst);
t_stack	*new_stack(int number, int index);
void	free_stack(t_stack **stack);
void	terminate(void);

#endif
