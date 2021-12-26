/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:13 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/26 15:09:35 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_iterations_a(t_b_to_a *info_b_to_a, int stack_a_size)
{
	if ((info_b_to_a[0]).place_a <= stack_a_size / 2)
	{
		(info_b_to_a[0]).iters_a = (info_b_to_a[0]).place_a;
		if ((info_b_to_a[0]).place_a)
			(info_b_to_a[0]).sign_a = 1;
		else
			(info_b_to_a[0]).sign_a = 0;
	}
	else if ((info_b_to_a[0]).place_a > stack_a_size / 2)
	{
		(info_b_to_a[0]).iters_a = (stack_a_size - (info_b_to_a[0]).place_a);
		(info_b_to_a[0]).sign_a = -1;
	}
}

void	set_iterations_b(t_b_to_a *info_b_to_a, int stack_b_size)
{
	if (info_b_to_a[0].place_b <= stack_b_size / 2)
	{
		info_b_to_a[0].iters_b = info_b_to_a[0].place_b;
		if ((info_b_to_a[0]).place_b)
			(info_b_to_a[0]).sign_b = 1;
		else
			(info_b_to_a[0]).sign_b = 0;
	}
	else
	{
		(info_b_to_a[0]).iters_b = (stack_b_size - (info_b_to_a[0]).place_b);
		(info_b_to_a[0]).sign_b = -1;
	}
}

t_b_to_a	find_b_elem(t_list *stack_b, t_list **stack_bb, const int b_sz)
{
	int				i;
	t_list			*temp_stack_b;
	t_b_to_a		info_b_to_a;

	i = 0;
	temp_stack_b = *stack_bb;
	info_b_to_a.index_b = stack_b->index;
	while (temp_stack_b && ((temp_stack_b)->index != stack_b->index))
	{
		i++;
		temp_stack_b = (temp_stack_b)->next;
	}
	info_b_to_a.place_b = i;
	set_iterations_b (&info_b_to_a, b_sz);
	return (info_b_to_a);
}

void	find_a_elem(t_list **stack_a, t_b_to_a *info_b_to_a, int stack_a_size)
{
	int		i;
	int		min;
	int		temp;
	t_list	*temp_stack_a;

	i = 0;
	min = 2147483647;
	temp_stack_a = *stack_a;
	while (temp_stack_a && min != 1)
	{
		temp = (temp_stack_a)->index - (info_b_to_a[0]).index_b;
		if (temp > 0 && temp < min)
		{
			min = temp;
			(info_b_to_a[0]).index_a = (temp_stack_a)->index;
			(info_b_to_a[0]).place_a = i;
		}
		temp_stack_a = temp_stack_a->next;
		i++;
	}
	set_iterations_a (info_b_to_a, stack_a_size);
}

int	b_to_a(t_list **stack_a, t_list **stack_b)
{
	int				elem_numb;
	int				a_sz;
	int				b_sz;
	t_b_to_a		*info_b_to_a;

	while (*stack_b)
	{
		a_sz = ft_lstsize (*stack_a);
		b_sz = ft_lstsize (*stack_b);
		info_b_to_a = get_inf_arr(stack_a, stack_b, a_sz, b_sz);
		if (NULL == info_b_to_a)
		{
			clear_list (stack_a);
			clear_list (stack_b);
			exit (1);
		}
		elem_numb = find_min_elem_number (info_b_to_a, b_sz);
		elem_b_to_a (stack_a, stack_b, info_b_to_a[elem_numb]);
		free (info_b_to_a);
	}
	return (1);
}
