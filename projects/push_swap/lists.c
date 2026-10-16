#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

t_node	*create_node(int value)
{
	t_node	*n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->abm = false;
	n->cost = 0;
	n->pos = 0;
	n->next = NULL;
	n->prev = NULL;
	n->target = NULL;
	return (n);
}
void	push_bottom(t_stack *stack, t_node *n)
{
	if (!stack || !n)
		return ;
	if (stack->size == 0)
	{
		stack->top = n;
		stack->bottom = n;
	}
	else 
	{
		stack->bottom->next = n;
		n->prev = stack->bottom;
		stack->bottom = n;
	}
	stack->size++;
}
void	print_stack(t_stack *stack, char name)
{
	t_node *current = stack->top;
	printf("Stack %c [size: %d]: ", name, stack->size);
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}
