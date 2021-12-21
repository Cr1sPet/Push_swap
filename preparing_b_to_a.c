#include "push_swap.h"

void	set_iterations_a (t_info_a_to_b *elem_info_a_to_b, int stack_a_size)
{
	if ((elem_info_a_to_b[0]).place_a <= stack_a_size / 2)
	{
		(elem_info_a_to_b[0]).number_top_iterations_a = (elem_info_a_to_b[0]).place_a;
		if ((elem_info_a_to_b[0]).place_a)
			(elem_info_a_to_b[0]).iterations_sign_a = 1;
		else
			(elem_info_a_to_b[0]).iterations_sign_a = 0;
	}
	else if ((elem_info_a_to_b[0]).place_a > stack_a_size / 2)
	{
		(elem_info_a_to_b[0]).number_top_iterations_a = (stack_a_size - (elem_info_a_to_b[0]).place_a);
		(elem_info_a_to_b[0]).iterations_sign_a = -1;
	}
}

void	set_iterations_b (t_info_a_to_b *elem_info_a_to_b, int stack_b_size)
{
	if ((elem_info_a_to_b[0]).place_b <= stack_b_size / 2)
	{
		(elem_info_a_to_b[0]).number_top_iterations_b = (elem_info_a_to_b[0]).place_b;
		if ((elem_info_a_to_b[0]).place_b)
			(elem_info_a_to_b[0]).iterations_sign_b  = 1;
		else
			(elem_info_a_to_b[0]).iterations_sign_b  = 0;
	}
	else
	{
		(elem_info_a_to_b[0]).number_top_iterations_b = (stack_b_size - (elem_info_a_to_b[0]).place_b);
		(elem_info_a_to_b[0]).iterations_sign_b  = -1;
	}
}

t_info_a_to_b find_stack_b_elem (t_list *stack_b ,t_list **stack_bb, const int stack_b_size)
{
	int				i;
	t_list			*temp_stack_b;
	t_info_a_to_b	elem_info_a_to_b;

	i = 0;
	temp_stack_b = *stack_bb;
	elem_info_a_to_b.index_b = stack_b->index;
	while (temp_stack_b && ((temp_stack_b)->index != stack_b->index))
	{
		i++;
		temp_stack_b = (temp_stack_b)->next;
	}
	elem_info_a_to_b.place_b  = i;
	set_iterations_b (&elem_info_a_to_b, stack_b_size);
	return (elem_info_a_to_b);
}

void	find_stack_a_elem (t_list **stack_a, t_info_a_to_b *elem_info_a_to_b, int stack_a_size)
{
	int	i;
	int	min;
	int temp;
	t_list *temp_stack_a;

	i = 0;
	min = 2147483647;
	temp_stack_a = *stack_a;
	while (temp_stack_a && min != 1)
	{
		temp = (temp_stack_a)->index - (elem_info_a_to_b[0]).index_b;
		if (temp > 0 && temp < min)
		{
			min = temp;
			(elem_info_a_to_b[0]).index_a = (temp_stack_a)->index;
			(elem_info_a_to_b[0]).place_a  = i;
		}
		temp_stack_a = temp_stack_a->next;
		i++;
	}
	set_iterations_a (elem_info_a_to_b, stack_a_size);
}

void	find_min_summary_iterations (t_info_a_to_b	*elem, int stack_b_size)
{
	(elem[0]).min_iterations = get_min_num ((elem[0]).number_top_iterations_a, 
			(elem[0]).number_top_iterations_b);	
	if (((elem[0]).iterations_sign_a == (elem[0]).iterations_sign_b) && (elem[0]).iterations_sign_b)
	{
		(elem[0]).min_summary_iterations
			= get_max_num((elem[0]).number_top_iterations_a, (elem[0]).number_top_iterations_b);
		
		(elem[0]).reverse_same_time = 1;
	}	
	else
	{
		(elem[0]).min_summary_iterations = (elem[0]).number_top_iterations_a + (elem[0]).number_top_iterations_b;
		(elem[0]).reverse_same_time = 0;
	}
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
		find_min_summary_iterations (&(elems_info_a_to_b[i]), stack_b_size);
		i++;
		stack_b = stack_b->next;
	}
	return (elems_info_a_to_b);
}

int find_min_elem_number (t_info_a_to_b	*elems_info_a_to_b, int stack_b_size)
{
	int	i;
	int min;
	int num;

	i = 0;
	num = 0;
	min = (elems_info_a_to_b[i]).min_summary_iterations;
	while (i < stack_b_size - 1)
	{
		i++;
		if ((elems_info_a_to_b[i]).min_summary_iterations < min)
		{
			num = i;
			min = (elems_info_a_to_b[i]).min_summary_iterations;
		}
	}
	return (num);
}

void print_elems_info_a_to_b (t_info_a_to_b *elems_info_a_to_b, int stack_b_size)
{
	int	i;
	static int counter = 0;

	i = 0;
	printf("\n\nCOUNTER == %d\n\nelems_info_a_to_b:\n", counter);
	while (i < stack_b_size)
	{
		printf ("~~~~~\nelems_info_a_to_b[%d]:\nindex_a = %d\nindex_b = %d\nplace_a = %d\nplace_b = %d\nnumber_top_iterations_a = %d\nnumber_top_iterations_b = %d\niterations_sign_a = %d\niterations_sign_b = %d\nmin_summary_iterations = %d\nmin_iterations = %d\n reverse_same_time = %d\n", i, (elems_info_a_to_b[i]).index_a, (elems_info_a_to_b[i]).index_b, (elems_info_a_to_b[i]).place_a, (elems_info_a_to_b[i]).place_b, (elems_info_a_to_b[i]).number_top_iterations_a, (elems_info_a_to_b[i]).number_top_iterations_b, (elems_info_a_to_b[i]).iterations_sign_a, (elems_info_a_to_b[i]).iterations_sign_b, (elems_info_a_to_b[i]).min_summary_iterations,(elems_info_a_to_b[i]).min_iterations, (elems_info_a_to_b[i]).reverse_same_time);
		// printf ("~~~~~\nelems_info_a_to_b[]:\nindex_a = %d\n",(elems_info_a_to_b[i]).index_a);
		i++;
	}
	counter++;
}

int preparing_b_to_a(t_list **stack_a, t_list **stack_b)
{
	int				elem_numb;
	int				stack_a_size;
	int				stack_b_size;
	t_info_a_to_b	*elems_info_a_to_b;

	while (*stack_b)
	{
		stack_a_size = ft_lstsize (*stack_a);
		stack_b_size = ft_lstsize (*stack_b);
		elems_info_a_to_b = get_info_array (stack_a, stack_b, stack_a_size, stack_b_size);
		if (NULL == elems_info_a_to_b)
			return (0);
		elem_numb = find_min_elem_number (elems_info_a_to_b, stack_b_size);
		elem_b_to_a (stack_a, stack_b, elems_info_a_to_b[elem_numb]);
	}
	return (0);
}