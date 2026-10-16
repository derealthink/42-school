#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->bottom == second)
		stack->bottom = first;
}
void	sa(t_stack *a)
{
	swap(a);
	printf("sa\n");
}
void	sb(t_stack *b)
{
	swap(b);
	printf("sb\n");
}
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}