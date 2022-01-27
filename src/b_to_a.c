/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:48:31 by jchopped          #+#    #+#             */
/*   Updated: 2022/01/08 10:55:44 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_iters_a(t_b_to_a *elem, int a_sz)
{
	if (elem->place_a <= a_sz / 2)
	{
		elem->iters_a = elem->place_a;
		if (elem->place_a)
			elem->sign_a = 1;
		else
			elem->sign_a = 0;
	}
	else if (elem->place_a > a_sz / 2)
	{
		elem->iters_a = (a_sz - elem->place_a);
		elem->sign_a = -1;
	}
}

void	set_iters_b(t_b_to_a *elem, int b_sz)
{
	if (elem->place_b <= b_sz / 2)
	{
		elem->iters_b = elem->place_b;
		if (elem->place_b)
			elem->sign_b = 1;
		else
			elem->sign_b = 0;
	}
	else
	{
		elem->iters_b = (b_sz - elem->place_b);
		elem->sign_b = -1;
	}
}

t_b_to_a	find_b_elem(t_stack *stack_b, t_stack **stack_bb, const int b_sz)
{
	int				i;
	t_stack			*temp_stack_b;
	t_b_to_a		elem;

	i = 0;
	temp_stack_b = *stack_bb;
	elem.index_b = stack_b->index;
	while (temp_stack_b && ((temp_stack_b)->index != stack_b->index))
	{
		i++;
		temp_stack_b = (temp_stack_b)->next;
	}
	elem.place_b = i;
	set_iters_b (&elem, b_sz);
	return (elem);
}

void	find_a_elem(t_stack **stack_a, t_b_to_a *elem, int stack_a_size)
{
	int		i;
	int		min;
	int		temp;
	t_stack	*temp_stack_a;

	i = 0;
	min = 2147483647;
	temp_stack_a = *stack_a;
	while (temp_stack_a && min != 1)
	{
		temp = (temp_stack_a)->index - elem->index_b;
		if (temp > 0 && temp < min)
		{
			min = temp;
			elem->index_a = (temp_stack_a)->index;
			elem->place_a = i;
		}
		temp_stack_a = temp_stack_a->next;
		i++;
	}
	set_iters_a (elem, stack_a_size);
}

void	b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int				elem_numb;
	int				a_sz;
	int				b_sz;
	t_b_to_a		*elem;

	while (*stack_b)
	{
		a_sz = ft_lstsize (*stack_a);
		b_sz = ft_lstsize (*stack_b);
		elem = get_inf_arr(stack_a, stack_b, a_sz, b_sz);
		if (NULL == elem)
		{
			clear_list (stack_a);
			clear_list (stack_b);
			exit (EXIT_FAILURE);
		}
		elem_numb = find_min_elem_number (elem, b_sz);
		elem_b_to_a (stack_a, stack_b, elem[elem_numb]);
		free (elem);
	}
}
