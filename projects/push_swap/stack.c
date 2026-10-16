#include "push_swap.h"

void	assign_pos(t_stack *stack)
{
	t_node	*current;
	int	i;
	int	median;

	i = 0;
	if(!stack || !stack->top)  // Also check for empty stack
		return ;
	median = stack->size / 2;
	current = stack->top;
	while(current)
	{
		current->pos = i;
		if (i <= median)  // Changed from <= to 
			current->abm = true;
		else
			current->abm = false;
		current = current->next;
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if(!stack)
		return(0);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
