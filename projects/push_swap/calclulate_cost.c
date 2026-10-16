#include "push_swap.h"

void	calculate_cost_a(t_stack *a, t_stack *b)
{
	t_node	*current;

	//printf("=== CALCULATE_COST_A START ===\n");
	current = a->top;
	while (current)
	{
		  //printf("Calculating cost for node %d\n", current->value);

		 if (!current->target) {
            /*printf("ERROR: Node %d has NULL target!\n", current->value);*/
            current->cost = INT_MAX;
            current = current->next;
            continue;
        }  
		current->cost = current->pos;
		if (!(current->abm))
			current->cost = a->size - (current->pos);
		if (current->target->abm)
			current->cost += current->target->pos;//value
		else
			current->cost += b->size - (current->target->pos);
		current = current->next;
	}
}

void	calculate_cost_b(t_stack *b, t_stack *a)
{
	t_node	*current;

	
	current = b->top;
	while (current)
	{
		current->cost = current->pos;
		if (!(current->abm))
			current->cost = b->size - (current->pos);
		if (current->target->abm)
			current->cost += current->target->pos;//value
			if (!current->target) {
    /*printf("ERROR: Node %d has no target!\n", current->value);
    return;*/
}
		else
			current->cost += a->size - (current->target->value);
		current = current->next;
	}
}
t_node	*get_cheapest_node(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest;
	long	lowest_cost;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	cheapest = current;
	lowest_cost = current->cost;
	while (current)
	{
		if (current->cost < lowest_cost)
		{
			lowest_cost = current->cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
/*void	get_cheapest_node(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest;
	long	lowest_cost;

	current = stack->top;
	cheapest = NULL;
	lowest_cost = LONG_MAX;
	if (!stack)
		return ;
	while (current)
	{
		if (current->cost < lowest_cost)
		{
			lowest_cost = current->cost;
			cheapest = current;
		}
		current = current->next;
	}
	cheapest->lowest_c = true;
}
t_node	*find_cheapest(t_stack *stack)
{
	t_node	*cheapest;
	t_node	*current;

	current = stack->top;
	cheapest = NULL;
	while (current)
	{
		if (current->lowest_c)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);	
}*/
