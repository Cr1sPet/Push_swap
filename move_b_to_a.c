#include "push_swap.h"


void go_rotate_stack (t_list **stack, int flag)
{
	if (1 == flag)
		rotate_stack(stack);
	else if (-1 == flag)
		reverse_rotate_stack(stack);
}

void    elem_b_to_a (t_list **stack_a, t_list **stack_b, t_info_a_to_b elem_info_a_to_b)
{
	int i;
	int has_more_iterations;

	i = 0;
	if (0 == elem_info_a_to_b.min_summary_iterations)
	{
		push_stack (stack_b, stack_a);
	}
	else if (elem_info_a_to_b.reverse_same_time)
	{
		while (i < elem_info_a_to_b.min_iterations)
		{
			go_rotate_stack (stack_a, elem_info_a_to_b.iterations_sign_a);
			go_rotate_stack (stack_b, elem_info_a_to_b.iterations_sign_a);
			i++;
		}
		while (i < elem_info_a_to_b.min_summary_iterations)
		{
			if (elem_info_a_to_b.has_more_iterations == 'A')
			{
				go_rotate_stack (stack_a, elem_info_a_to_b.iterations_sign_a);
				go_rotate_stack (stack_b, elem_info_a_to_b.iterations_sign_a);
			}
			else if(elem_info_a_to_b.has_more_iterations == 'B')
			{
				go_rotate_stack (stack_a, elem_info_a_to_b.iterations_sign_a);
				go_rotate_stack (stack_b, elem_info_a_to_b.iterations_sign_a);
			}
			i++;
		}
	}
	else
	{
		while (i < elem_info_a_to_b.number_top_iterations_a)
		{
			go_rotate_stack (stack_a, elem_info_a_to_b.iterations_sign_a);
			i++;
		}
		i = 0;
		while (i < elem_info_a_to_b.number_top_iterations_b)
		{
			go_rotate_stack (stack_b, elem_info_a_to_b.iterations_sign_b);
			i++;
		}
	}
	push_stack (stack_b, stack_a);
}