#include "push_swap.h"

static	void	prep_nodes_a(t_stack *a, t_stack *b)
{
    //printf("=== PREP_NODES_A CALLED ===\n");
    assign_pos(a);
    assign_pos(b);
    //printf("About to call find_target_a\n");
    find_target_a(a, b);
    //printf("find_target_a completed\n");
    calculate_cost_a(a, b);
    //printf("=== PREP_NODES_A DONE ===\n");
}

static	void	prep_nodes_b(t_stack *a, t_stack *b)
{

	assign_pos(a);
	assign_pos(b);
	find_target_b(b, a);
	calculate_cost_b(b, a);
}
static	void	min_top(t_stack *a)
{
	t_node	*min_node;

	assign_pos(a);  // Make sure positions are current
	min_node = find_min(a);
	
	while (a->top != min_node)  // Compare nodes, not values
	{
		if (min_node->abm)
			ra(a);
		else
			rra(a);
	}
}
void	sort_stacks(t_stack *a, t_stack *b)
{
		if (a->size > 3 && (!is_sorted(a)))
		pb(a,b);
	if (a->size > 3 && (!is_sorted(a)))
		pb(a,b);
	while (a->size > 3 && (!is_sorted(a)))
	{
		prep_nodes_a(a, b);
		pa_greedy(a, b);
	}
	//printf("About to call sort_three with stack size: %d\n", a->size);
	if (a->size != 3) {
    	//printf("ERROR: sort_three called with wrong size!\n");
    	return;
	}
	if(a->size == 3)
		sort_three(a);
	while (b->top)
	{
		prep_nodes_b(a, b);
		pb_greedy(a, b);
	}
	assign_pos(a);
	min_top(a);
}