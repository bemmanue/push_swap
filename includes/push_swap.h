
# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>

typedef struct		s_info
{
	int				count;
}					t_info;

typedef struct		s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}					t_stack;

void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_ab(t_stack **stack_a, t_stack **stack_b);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		reverse_rotate_a(t_stack **stack_a);
void		reverse_rotate_b(t_stack **stack_b);
void		reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

void		print_stack(t_stack *stack, char *str);

void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast_ps(t_stack *lst);
t_stack		*ft_lstnew_ps(int number, int index);

void		sort_numbers(t_stack *stack_a, t_info *info);

#endif