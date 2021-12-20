#include "push_swap.h"

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