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

void print_list(t_list **listA)
{
	t_list *list;
	static int i = 0;
	int j = 0;

	list = *listA;
	printf("#################################\n------>%d<------\n", i);
	while (list)
	{
		printf("----\nindex = %d keep_a = %d content = %d\n", list->index, list->keep_a, list->content);
		// printf("\nindex = %2d	number = %d", list->index, j++);
		list = list->next;
	}
	printf("\n");
	i++;
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
	my_markup_greater_then(&temp_list);
	if (false_count_before > false_counter(&temp_list))
		ok = 1;
	else
		ok = 0;
	return (ok);
}

void list_sort(t_list **list, t_list **stack_b)
{
	int		false_count;

	false_count = false_counter(list);
	while (false_count)
	{
		if (check_swap_need(list, false_count))
		{
			swap_stack (list);
			ft_putendl_fd("sa", 1);
			my_markup_greater_then(list);
		}
		else if (0 == (*list)->keep_a)
		{
			push_stack (list, stack_b);
			ft_putendl_fd("pb", 1);
		}
		else
		{
			rotate_stack (list);
			ft_putendl_fd("ra", 1);
		}
		false_count = false_counter(list);
	}
}