/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:04:07 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/26 15:49:06 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_num(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	get_min_num(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	find_min_elem_number(t_b_to_a	*info_b_to_a, int stack_b_size)
{
	int	i;
	int	min;
	int	num;

	i = 0;
	num = 0;
	min = (info_b_to_a[i]).min_sum_iters;
	while (i < stack_b_size - 1)
	{
		i++;
		if ((info_b_to_a[i]).min_sum_iters < min)
		{
			num = i;
			min = (info_b_to_a[i]).min_sum_iters;
		}
	}
	return (num);
}

void	find_min_sum_iters(t_b_to_a	*elem)
{
	elem->min_iterations
		= get_min_num (elem->iters_a,
			elem->iters_b);
	if ((elem->sign_a == elem->sign_b)
		&& elem->sign_b)
	{
		elem->min_sum_iters = get_max_num(elem->iters_a, elem->iters_b);
		elem->reverse_same_time = 1;
	}	
	else
	{
		elem->min_sum_iters
			= elem->iters_a
			+ elem->iters_b;
		elem->reverse_same_time = 0;
	}
}

t_b_to_a	*get_inf_arr(t_stack **list_a, t_stack **list_b, int a_sz, int b_sz)
{
	int				i;
	t_stack			*stack_b;
	t_b_to_a		*info_b_to_a;

	i = 0;
	stack_b = *list_b;
	info_b_to_a = (t_b_to_a *)malloc(sizeof(t_b_to_a) * b_sz);
	if (NULL == info_b_to_a)
		return ((void *)0);
	while (i < b_sz)
	{
		info_b_to_a[i] = find_b_elem(stack_b, list_b, b_sz);
		find_a_elem(list_a, &info_b_to_a[i], a_sz);
		find_min_sum_iters(&(info_b_to_a[i]));
		i++;
		stack_b = stack_b->next;
	}
	return (info_b_to_a);
}
