#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a = stack->top->value;
	int	b = stack->top->next->value;
	int	c = stack->top->next->next->value;

	if (a > b && b < c && a < c)
		sa(stack);

	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack); 
	}

	else if (a > b && b < c && a > c)
		ra(stack);

	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}

	else if (a < b && b > c && a > c)
		rra(stack);
}
