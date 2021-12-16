#include "push_swap.h"

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

t_info_a_to_b find_stack_b_elem (t_list *stack_b ,t_list **stack_bb, const int stack_b_size)
{
	int	i;
	t_info_a_to_b	elem_info_a_to_b;

	i = 0;
	elem_info_a_to_b.index_b = stack_b->index;
	while (*stack_bb && ((*stack_bb)->index != stack_b->index))
	{
		i++;
		*stack_bb = (*stack_bb)->next;
	}
	elem_info_a_to_b.place_b  = i;
	if (stack_b_size - 1 - i > i)
		elem_info_a_to_b.number_top_iterations_b = i;
	else
		elem_info_a_to_b.number_top_iterations_b = -(stack_b_size - 1 - i);
	return (elem_info_a_to_b);
}

void	find_stack_a_elem (t_list **stack_a, t_info_a_to_b *elem_info_a_to_b, int stack_a_size)
{
	int	i;
	int	min;
	t_list *temp_stack_a;

	i = 0;
	temp_stack_a = *stack_a;
	min = (elem_info_a_to_b[0]).index_b - (temp_stack_a)->index;
	(elem_info_a_to_b[0]).index_a = (temp_stack_a)->index;
	while (i < stack_a_size && min != 1)
	{
		i++;
		temp_stack_a = temp_stack_a->next;
		if (((elem_info_a_to_b[0]).index_b - (temp_stack_a)->index) < min)
		{
			min = (elem_info_a_to_b[0]).index_b - (temp_stack_a)->index);
			(elem_info_a_to_b[0]).index_a = (temp_stack_a)->index;
		}
	}
	(elem_info_a_to_b[0]).place_a  = i;
	if (stack_a_size - 1 - i > i)
		(elem_info_a_to_b[0]).number_top_iterations_a = i;
	else
		(elem_info_a_to_b[0]).number_top_iterations_a = -(stack_a_size - 1 - i);
}

t_info_a_to_b	*get_info_array (t_list **stack_aa, t_list **stack_bb, int stack_a_size, int stack_b_size)
{
	int				i;
	t_list			*stack_a;
	t_list			*stack_b;
	t_info_a_to_b	*elems_info_a_to_b;


	i = 0;
	stack_b = *stack_bb;
	elems_info_a_to_b = (t_info_a_to_b *)malloc (sizeof(t_info_a_to_b) * stack_b_size);
	if (NULL == elems_info_a_to_b)
		return ((void *)0);
	while (i < stack_b_size)
	{
		elems_info_a_to_b[i] = find_stack_b_elem (stack_b, stack_bb, stack_b_size);
		find_stack_a_elem (stack_aa, &(elems_info_a_to_b[i]), stack_a_size);
		i++;
		stack_b = stack_b->next;
	}
	return (elem_info_a_to_b);
}

int	find_elem_number (t_info_a_to_b	*elems_info_a_to_b, int stack_b_size)
{
	int	min;

	if ((elem_info_a_to_b[0].number_top_iterations_a > 0 && elem_info_a_to_b[0].number_top_iterations_b > 0)
		|| (elem_info_a_to_b[0].number_top_iterations_a < 0 && elem_info_a_to_b[0].number_top_iterations_b < 0))
	{
		if (elem_info_a_to_b[0].number_top_iterations_a < 0)
			min = 
	}
}

int move_b_to_a(t_list **stack_a, t_list **stack_b)
{
	int				stack_a_size;
	int				stack_b_size;
	int				elem_numb;
	t_info_a_to_b	*elems_info_a_to_b;

	while (*stack_b)
	{
		stack_a_size = ft_lstsize (*stack_a);
		stack_b_size = ft_lstsize (*stack_b);
		elems_info_a_to_b = get_info_array (stack_a, stack_b, stack_a_size, stack_b_size);
		if (NULL == elem_info_a_to_b)
			return (0);
		elem_numb = find_elem_number (elems_info_a_to_b, stack_b_size);
	}
}