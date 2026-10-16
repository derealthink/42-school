#include "push_swap.h"

void debug_costs(t_stack *a) {
    t_node *current = a->top;
    printf("=== COSTS ===\n");
    while (current) {
        printf("Node %d: pos=%d, abm=%d, cost=%d, target=%d\n", 
               current->value, current->pos, current->abm, 
               current->cost, current->target ? current->target->value : -999);
        current = current->next;
    }
    printf("=============\n");
}

static void	prep_p(t_stack *stack, t_node *tar, char s_name)
{
	int safety = 0;
	//printf("=== PREP_P START (stack %c, target %d) ===\n", s_name, tar ? tar->value : -999);
	
	if (!stack || !tar) {
		//printf("ERROR: NULL stack or target in prep_p\n");
		return;
	}
	
	while(stack->top != tar && safety < stack->size * 2)
	{
		/*printf("Current top: %d, target: %d, abm: %d\n", 
		       stack->top->value, tar->value, tar->abm);*/
		
		if (s_name == 'a')
		{
			if (tar->abm) 
				ra(stack);
			 else 
				rra(stack);
		}
		else if (s_name == 'b')
		{
			if (tar->abm) 
				rb(stack);
			 else 
				rrb(stack);
		}
		safety++;
	}
	
}

void	pa_greedy(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	cheapest = get_cheapest_node(a);
	
	if (cheapest->abm && cheapest->target->abm) 
		rotate_both(a, b, cheapest);
	 else if (!(cheapest->abm) && !(cheapest->target->abm)) 
		rev_rotate_both(a, b, cheapest);
	
	assign_pos(a);
	assign_pos(b);
	//printf("About to call prep_p for A\n");
	prep_p(a, cheapest, 'a');
	//printf("About to call prep_p for B\n");
	prep_p(b, cheapest->target, 'b');
	//printf("About to call pb\n");
	pb(a, b);
	//printf("=== PA_GREEDY DONE ===\n");
}

void	pb_greedy(t_stack *a, t_stack *b)
{
	t_node	*current;

	//printf("=== PB_GREEDY START ===\n");
	current = b->top;
	/*printf("Moving node %d from B to A, target: %d\n", 
	       current->value, current->target ? current->target->value : -999);*/
	
	if (!current->target) {
		//printf("ERROR: Node %d has no target!\n", current->value);
		return;
	}
	
	prep_p(a, current->target, 'a');
	//printf("About to call pa\n");
	pa(a, b);
	//printf("=== PB_GREEDY DONE ===\n");
}
/*void pb_greedy(t_stack *a, t_stack *b)
{
    t_node *cheapest;  // Change from current to cheapest
    
    cheapest = get_cheapest_node(b);  // ✅ Find actual cheapest in B!
    
    if (!cheapest || !cheapest->target) {
        printf("ERROR: No cheapest node or no target!\n");
        return;
    }
    
    // Position the cheapest node at top of B first
    prep_p(b, cheapest, 'b');
    
    // Position target at top of A
    prep_p(a, cheapest->target, 'a');
    
    // Pull from B to A
    pa(a, b);
}*/