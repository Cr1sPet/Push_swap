void	three_sort_helper (t_list **list, int *arr)
{
	if (arr[1] > arr[2] && arr[2] > arr[0])
	{
		swap_stack (list);
		ft_putendl("sa", 1);
		rotate_stack (list)
		ft_putendl("ra", 1);
	}
	else if (arr[1] > arr[0] && arr[0] > arr[2])
	{
		reverse_rotate_stack (list);
		ft_putendl("rra", 1);
	}
	else if (arr[0] > arr[2] && arr[2] > arr[1])
	{
		reverse_rotate_stack (list);
		ft_putendl("ra", 1);
	}
}
void	three_sort (t_list **list)
{
	int	i;
	int	arr[3];

	i = 0;
	while (*list)
	{
		arr[i++] = (*list)->index;
		(*list) = (*list)->next;
	}
	if (arr[2] > arr[0] && arr[0] > arr[1]])
	{
		swap_stack (list);
		ft_putendl("sa", 1);
	}
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		swap_stack (list);
		ft_putendl("sa", 1);
		reverse_rotate (list)
		ft_putendl("rra", 1);
	}
	three_sort_helper (list, arr);
}


void five_sort (t_list **listA, t_list **listB)
{
	push_stack (listA, listB);
	ft_putendl ("pa", 1);
	push_stack (listA, listB);
	ft_putendl ("pa", 1);
	three_sort (listA);
	push_stack (listB, listA);
	ft_putendl ("pb", 1);
	normalize_list(listA);
	push_stack (listB, listA);
	ft_putendl ("pb", 1);
	normalize_list(listA);
}