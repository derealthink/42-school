
#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node *node;
	if (!from || from->size == 0)
		return ;
	node = from->top;
	from->top = node->next;
	if(from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;
	node->next = to->top;
	node->prev = NULL;
	if (to->top)
		to->top->prev = node;
	else
		to->bottom = node;
	to->top = node;
	to->size++;
}
void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	printf("pa\n");
}
void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	printf("pb\n");
}