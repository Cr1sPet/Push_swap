#include "push_swap.h"

int	find_elem (t_list *stack, int elem_index)
{
	int		place_index;

	place_index = 0;
	while (stack && (elem_index != stack->index))
	{
		place_index++;
		stack = stack->next;
	}
	return (place_index);
}

void organise_stack (t_list **stack, int difference, int place_index)
{
	int	i;

	i = 0;
	if (difference > place_index)
		while (i++ < place_index)
			rotate_stack(stack);
	else
	{
		while (i++ < difference)
			reverse_rotate_stack(stack);
	}
}

void	organize_stack_a (t_list **stack_a, int stack_size)
{
	int place_index;

	print_list(stack_a);
	place_index = find_elem (*stack_a, 0);
	print_list(stack_a);
	organise_stack (stack_a, stack_size - 1 - place_index, place_index);
	print_list(stack_a);
}

void	organise_stack_b (t_list **stack_b, int stack_size)
{
	int place_index;

	print_list(stack_b);
	place_index = find_elem (*stack_b, stack_size - 1);  // need to fix dind_elem, wrong logic!
	organise_stack (stack_b, stack_size - 1 - place_index, place_index);
	print_list(stack_b);
}

void move_b_to_a(t_list **stack_a, t_list **stack_b)
{
	int elem_numb;
	// int	stack_size;

	while (*stack_b)
	{
		// stack_a_size = ft_lstsize(*stack_a);
		// stack_size = ft_lstsize(*stack_b);
		organize_stack_a (stack_a, ft_lstsize(*stack_a));
		organise_stack_b (stack_b, ft_lstsize(*stack_b)); // need to fix dind_elem, wrong logic!
		// elem_numb = find_elem_to_push (stack_a, stack_b);
	}
}