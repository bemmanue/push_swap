
#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, char *str)
{
	t_stack	*temp;

	temp = stack;
	printf("%s\n", str);
	while (temp != NULL)
	{
		printf("number = %5d   ", temp->number);
		printf("index = %d", temp->index);
		printf("    flag = %d\n", temp->flag);
		temp = temp->next;
	}
}