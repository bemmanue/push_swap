
#include "../includes/push_swap.h"

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (!lst || !new)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_stack	*ft_lstnew_ps(int number, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = number;
	new->index = index;
	new->flag = 0;
	new->next = NULL;
	return (new);
}