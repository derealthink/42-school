#include "push_swap.h"

 t_node	*find_min(t_stack *stack)
{
	int	min_val;
	t_node *current;
	t_node *min;
	
	min_val = INT_MAX;
	current = stack->top;
	min = NULL;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min = current;
		}
		current = current->next;
	}
	return (min);
}

void	find_target_b(t_stack *b, t_stack *a)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*target;
	int		best_val;

	if (!a || !b || !a->top || !b->top)
    return;
	current_b = b->top;
	while (current_b)
	{
		target = NULL;
		current_a = a->top;
		best_val = INT_MAX;
		while (current_a)
		{
			if (current_a->value > current_b->value && current_a->value < best_val)
			{
				best_val = current_a->value;
				target = current_a;
				//printf("target is %d", target->value);
			}
		current_a = current_a->next;
		}
		if (!target){
			//printf("error target not found");
			current_b->target = find_min(a);
		}
		else
			current_b->target = target;
		current_b = current_b->next;
	}
}
