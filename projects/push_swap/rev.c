#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate (b);
	printf("rrb\n"); 
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}

void	rev_rotate_both(t_stack *a, t_stack *b, t_node *cheapest)
{
	while (a->top != cheapest && b->top != cheapest->target)
	{
		rrr(a, b);
	}
	assign_pos(a);
	assign_pos(b);
}