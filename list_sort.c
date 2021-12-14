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
	static int i = 0;

	list = *listA;
	printf("#################################\n------>%d<------\n", i);
	while (list)
	{
		printf("----\nindex = %d\nkeep_a = %d\ncontent = %d\n", list->index, list->keep_a, list->content);
		list = list->next;
	}
	printf("\n");
	i++;
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

void	copy_list(t_list **dest, t_list **src)
{
	t_list	*hello;

	hello = *src;
	while (hello)
	{
		ft_lstadd_back(dest, ft_lstnew(hello->content, hello->index, hello->keep_a));
		hello = hello->next;
	}
}

int check_swap_need(t_list **list, int false_count_before)
{
	int		ok;
	t_list	*temp_list;

	temp_list = NULL;
	copy_list (&temp_list, list);
	swap_stack (&temp_list);
	markup_by_index(&temp_list);
	if (false_count_before > false_counter(&temp_list))
		ok = 1;
	else
		ok = 0;
	swap_stack (&temp_list);
	markup_by_index(&temp_list);
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

void reverse_rotate_stack (t_list **list)
{
	int		i;
	int		lst_size;
	t_list	*la_list;
	t_list	*pre_last;

	i = 0;
	la_list = *list;
	lst_size = ft_lstsize(*list);
	while (i < lst_size)
	{

		if (i == lst_size - 2)
		{
			pre_last = la_list;
			la_list = pre_last->next;
			break;
		}
		la_list = la_list->next;
		i++;
	}
	la_list->next = (*list);
	pre_last->next = NULL;
	(*list) = la_list;
}

void list_sort(t_list **list, t_list **stack_b)
{
	// t_list  *stack_b;
	int		false_count;

	*stack_b = NULL;
	print_list (list);
	false_count = false_counter(list);
	while (false_count)
	{
		if (check_swap_need(list, false_count))
		{
			swap_stack (list);
			markup_by_index(list);
		}
		else if (0 == (*list)->keep_a)
		{
			push_stack (list, stack_b);
		}
		else
		{
			rotate_stack (list);
		}
		false_count = false_counter(list);
	}
	print_list (list);
	reverse_rotate_stack(list);
	print_list (list);
	print_list (stack_b);
}