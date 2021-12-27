#include "push_swap.h"

void s_swap_stack (t_list **stack_a, t_list **stack_b)
{
	swap_stack (stack_a);
	swap_stack (stack_b);
}
void s_rotate_stack (t_list **stack_a, t_list **stack_b)
{
	rotate_stack (stack_a);
	rotate_stack (stack_b);
}

void s_reverse_rotate_stack (t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_stack (stack_a);
	reverse_rotate_stack (stack_b);
}