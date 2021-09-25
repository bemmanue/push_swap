
# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>

typedef struct		s_info
{
	int				middle_value;
	int				number;
	int				remain;
	int				main;
	int				flag;
	int				sorted;
}					t_info;

typedef struct		s_stack
{
	int				number;
	int				index;
	int				flag;
	struct s_stack	*next;
}					t_stack;

int		check_arguments(int count, char **args);
void	start_sorting(int argc, char **argv);

t_stack	*fill_stack(int argc, char **argv);
t_info	*fill_info(int argc);

void	sort_few_numbers(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	sort_three_numbers(t_stack **stack_a);

void	divide_into_two_stacks(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	divide_into_groups(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	sort_remains(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	sort_groups(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	sort_more_elements(t_stack **stack_a, t_stack **stack_b, t_info **info);
void	sort_three_elements(t_stack **stack_a, t_stack **stack_b, t_info **info);

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

void	print_stack(t_stack *stack, char *str);

t_stack	*ft_lstlast_ps(t_stack *lst);
t_stack	*ft_lstnew_ps(int number, int index);

#endif