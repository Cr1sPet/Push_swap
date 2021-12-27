#include "push_swap.h"

void init(t_list **list_a, int *arr, int arr_len)
{
	int		i;
	t_list	*temp_list;

	i = arr_len - 1;
	temp_list = *list_a;
	while (i >= 0)
	{
		temp_list = ft_lstnew(arr[i--], -1, -1);
		if (NULL == temp_list)
		{
			clear_list (list_a);
			exit (1);
		}
		ft_lstadd_front(list_a, temp_list);
	}
}

int parse_command (char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp("ra", str, ft_strlen (str)))
			rotate_stack (stack_a);
	else if (!ft_strncmp("rb", str, ft_strlen (str)))
		rotate_stack (stack_b);
	else if (!ft_strncmp("pb", str, ft_strlen (str)))
		push_stack (stack_a, stack_b);
	else if (!ft_strncmp("pa", str, ft_strlen (str)))
		push_stack (stack_b, stack_a);
	else if (!ft_strncmp("rra", str, ft_strlen (str)))
		reverse_rotate_stack (stack_a);
	else if (!ft_strncmp("rrb", str, ft_strlen (str)))
		reverse_rotate_stack (stack_b);
	else if (!ft_strncmp("sa", str, ft_strlen (str)))
		swap_stack (stack_a);
	else if (!ft_strncmp("sb", str, ft_strlen (str)))
		swap_stack (stack_b);
	else if (!s_commands (str, stack_a, stack_b))
		return (0);
	return (1);
}

int	check_sort (t_list **stack__a)
{
	int	temp;
	t_list	*stack_a;

	stack_a = *stack__a;
	temp = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content < temp)
			return (0);
		temp = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}

int	sort(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	ok;
	char *str;

	i = 0;
	ok = 1;
	while ((str = get_next_line (0)))
	{
		ok = parse_command (str, stack_a, stack_b);
		free (str);
		if (!ok)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int	*arr;
	int	arr_len;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	arr = validation(argc, argv, &arr_len);
	init(&stack_a, arr, arr_len);
	if (ft_lstsize(stack_a) != arr_len || !sort(&stack_a, &stack_b) || !check_sort (&stack_a))
		ft_putendl_fd ("KO", 1);
	else
		ft_putendl_fd ("OK", 1);
	clear_list (&stack_a);
	clear_list (&stack_b);
	free (arr);
	return (0);
}