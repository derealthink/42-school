#include "push_swap.h"

static t_node	*find_max(t_stack *stack)
{
	int	max_val;
	t_node *current;
	t_node *max;

	//printf("=== FIND_MAX DEBUG ===\n");
	if (!stack || !stack->top) {
		//printf("Stack is null or empty!\n");
		return NULL;
	}
	
	max_val = INT_MIN;
	current = stack->top;
	max = NULL;
	
	while (current)
	{
		//printf("Checking node %d vs current max %d\n", current->value, max_val);
		if (current->value > max_val)
		{
			max_val = current->value;
			max = current;
			//printf("New max: %d\n", max_val);
		}
		current = current->next;
	}
	/*printf("Final max: %s\n", max ? "found" : "NULL");
	printf("===================\n");*/
	return (max);
}

void	find_target_a(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	t_node	*current_a;
	t_node	*target;
	int	best_val;

	/*printf("*** FIND_TARGET_A ENTERED ***\n");
	printf("Stack A size: %d, Stack B size: %d\n", a ? a->size : -1, b ? b->size : -1);*/
	
	if (!a || !b || !a->top || !b->top) {
		//printf("*** EARLY RETURN - NULL STACKS ***\n");
		return;
	}
	
	current_a = a->top;
	while (current_a)
	{
		target = NULL;
		current_b = b->top;
		best_val = INT_MIN;
		//printf("Looking for target for node %d in stack B:\n", current_a->value);
		
		while (current_b)
		{
			//printf("  Checking B node %d: ", current_b->value);
			if (current_b->value < current_a->value && current_b->value > best_val)
			{
				best_val = current_b->value;
				target = current_b;
				//printf("NEW TARGET!\n");
			}
			/*else
			{
				printf("no match\n");
			}*/
			current_b = current_b->next;
		}
		
		if (!target) {
			//printf("No target found, calling find_max(b)\n");
			current_a->target = find_max(b);
			//printf("find_max returned: %s\n", current_a->target ? "SUCCESS" : "NULL");
		} else {
			//printf("Target found: %d\n", target->value);
			current_a->target = target;
		}
		
		/*printf("Final target for node %d: %s\n", 
		       current_a->value, 
		       current_a->target ? "SET" : "NULL");*/
		
		current_a = current_a->next;
	}
	//printf("find_target_a completed\n");
}
/*
void	find_target_a(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	t_node	*current_a;
	t_node	*target;
	long		best_val;

	current_a = a->top;
	while (current_a)
	{
		target = find_max(b);  // Default to max
		current_b = b->top;
		best_val = LONG_MIN;
		while (current_b)
		{
			if (current_b->value < current_a->value && current_b->value > best_val)
			{
				best_val = current_b->value;
				target = current_b;  // Override with better target
			}
			current_b = current_b->next;
		}
		current_a->target = target;
		current_a = current_a->next;
	}
}*/
