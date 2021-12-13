#include "push_swap.h"

int  false_counter(t_list **list)
{
	int		counter;
	t_list  *stack_a;

	counter = 0;
	stack_a = *list;
	while (stack_a)
	{
		if (0 == stack_a->keep_a)
			counter++;
		stack_a = stack_a->next;
	}
	return (counter);
}

static void print_list(t_list **listA)
{
	t_list *list;

	list = *listA;
	while (list)
	{
		printf("----\nindex = %d\ncontent = %d\n", list->index, list->content);
		list = list->next;
	}
	printf("\n");
}

void swap_stack (t_list **list)
{
	t_list  *stack_a;
	t_list  *temp_list;

	stack_a = (*list)->next;
	temp_list = stack_a->next;
	stack_a->next = (*list);
	(*list)->next = temp_list;
	(*list) = stack_a;
}

int check_swap_need(t_list **list, int false_count_before)
{
	int	ok;

	swap_stack (list);
	markup_by_index(list);
	if (false_count_before > false_counter(list))
		ok = 1;
	else
		ok = 0;
	swap_stack (list);
	markup_by_index(list);
	return (ok);
}

void push_stack (t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_list;

	temp_list = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lstadd_front(stack_b, *stack_a);
	(*stack_a) = temp_list;
}

void rotate_stack (t_list **list)
{
	t_list	*temp_list;

	temp_list = (*list);
	(*list) = temp_list->next;
	temp_list->next = NULL;
	ft_lstadd_back(list, temp_list);
}

void list_sort(t_list **list)
{
	t_list  *stack_b;

	stack_b = NULL;
	// t_list  *stack_a;
	// int		false_count;

	// false_count = false_counter(list);
	// while (false_counter)
	// {
	// 	if (check_swap_need(list))
	// 	{
			// swap_stack (list);
	// 		markup_by_index(list);
	// 	}
	// 	else if (0 == (*list)->keep_a)
	// 		push_b (list);
	// 	else
	// 		rotate_a (list);
	// 	false_counter = false_counter(stack_a);
	// }
	print_list (list);
	// check_swap_need(list, false_count);
	// swap_stack (list);
	// push_stack (list, &stack_b);
	rotate_stack (list);
	print_list (list);
	// print_list(&stack_b);
}