/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:44:46 by jchopped          #+#    #+#             */
/*   Updated: 2022/01/08 10:59:53 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack **list_a, int *arr, int arr_len)
{
	int		i;
	t_stack	*temp_list;

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

int	parse_command(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!str_cmp("ra\n", str))
		rotate_stack (stack_a);
	else if (!str_cmp("rb\n", str))
		rotate_stack (stack_b);
	else if (!str_cmp("pb\n", str))
		push_stack (stack_a, stack_b);
	else if (!str_cmp("pa\n", str))
		push_stack (stack_b, stack_a);
	else if (!str_cmp("rra\n", str))
		reverse_rotate_stack (stack_a);
	else if (!str_cmp("rrb\n", str))
		reverse_rotate_stack (stack_b);
	else if (!str_cmp("sa\n", str))
		swap_stack (stack_a);
	else if (!str_cmp("sb\n", str))
		swap_stack (stack_b);
	else if (!s_commands (str, stack_a, stack_b))
		return (0);
	return (1);
}

int	check_sort(t_stack **stack_a)
{
	t_stack	*cur;

	cur = *stack_a;
	while (cur->next)
	{
		if (cur->content > cur->next->content)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		ok;
	char	*str;

	i = 0;
	ok = 1;
	str = get_next_line (0);
	while (str)
	{
		ok = parse_command (str, stack_a, stack_b);
		free (str);
		if (!ok)
			return (0);
		i++;
		str = get_next_line (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		*arr;
	int		arr_len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	arr = validation(argc, argv, &arr_len);
	init(&stack_a, arr, arr_len);
	free (arr);
	if (ft_lstsize(stack_a) != arr_len
		|| !sort(&stack_a, &stack_b) || !check_sort (&stack_a))
		ft_putendl_fd ("KO", 1);
	else
		ft_putendl_fd ("OK", 1);
	clear_list (&stack_a);
	clear_list (&stack_b);
	return (0);
}
