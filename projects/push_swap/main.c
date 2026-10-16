 #include "push_swap.h"
 
 int	main(int argc, char **argv)
 {
	t_stack stack_a;
	t_stack	stack_b;
	int		i;
	int		num;
	int		*iarr;

	iarr = NULL;
	i = 0;
	num = 0;
	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc ==  2)
	{
		num = arg_count(argv[1]);
		iarr = parse_wq(argv[1]);
		if (!iarr)
		{
			return (1);
		}
		while (i < num)
		{
			t_node *new_node = create_node(iarr[i]);//enclose all parsing in cleaner functions
			if (!new_node)
			{
				free(iarr);
				return (1);
			}
			push_bottom(&stack_a, new_node);
			i++;
		}
		free(iarr);
	}
	else if (argc > 2)
	{
		num = argc - 1;
		iarr = parse_ma(argv + 1, num);
		if (!iarr)
		{
			write(2, "Error\n", 6);
			return (1);// error handle
		}
		while (i < num)
		{
			t_node *new_node = create_node(iarr[i]); // enclose all parsing in separate function
			if (!new_node)
			{
				free(iarr);
				return (1);
			}
			push_bottom(&stack_a, new_node);
			i++;
		}
		free(iarr);
	}
	assign_pos(&stack_a);
	if (is_sorted(&stack_a))
	{	
		print_stack(&stack_a, 'a');
		return (0);
	}
	else if (stack_a.size == 2)
		sa(&stack_a);
	else if (stack_a.size == 3)
		sort_three(&stack_a);
	else
		sort_stacks(&stack_a, &stack_b);
	print_stack(&stack_a, 'a');

	return (0);
 }