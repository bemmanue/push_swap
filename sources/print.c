
#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, char *str)
{
	t_stack	*temp;

	temp = stack;
	printf("%s", str);
	while (temp != NULL)
	{
		printf("number = %5d   ", temp->number);
		printf("index = %d\n", temp->index);
		temp = temp->next;
	}
}