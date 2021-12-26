/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:09 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/26 15:15:19 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	false_counter(t_list **list)
{
	int		counter;
	t_list	*stack_a;

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

int	check_swap_need(t_list **list, int false_count_before, int a_sz)
{
	int		ok;

	swap_stack (list);
	markup_gt(list, a_sz);
	if (false_count_before > false_counter(list))
		ok = 1;
	else
		ok = 0;
	swap_stack (list);
	markup_gt(list, a_sz);
	return (ok);
}

void	a_to_b(t_list **list, t_list **stack_b)
{
	int		false_count;
	int		a_sz;

	a_sz = ft_lstsize (*list);
	false_count = false_counter(list);
	while (false_count)
	{
		if (check_swap_need(list, false_count, a_sz))
		{
			swap_stack (list);
			ft_putendl_fd("sa", 1);
			markup_gt(list, a_sz);
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
