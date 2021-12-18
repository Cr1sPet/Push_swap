/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:35:01 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/12/14 12:08:04 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	helper(t_stack *stk_i, t_stack *stk_j)
{
	int		count;

	count = 1;
	while (stk_j)
	{
		if (stk_j->index == (stk_i->index + count))
			count++;
		stk_j = stk_j->next;
	}
	return (count);
}

int	find_markup_head_ind(t_stack *stk)
{
	t_stack	*stk_i;
	t_stack	*stk_j;
	int		count;
	int		max_count;
	int		markup_head_ind;

	stk_i = stk;
	max_count = 0;
	markup_head_ind = -1;
	while (stk_i)
	{
		stk_j = stk_i->next;
		count = helper(stk_i, stk_j);
		if (count > max_count)
		{
			max_count = count;
			markup_head_ind = stk_i->index;
		}
		stk_i = stk_i->next;
	}
	return (markup_head_ind);
}

t_stack	*markup(t_stack *stk)
{
	int		markup_head_ind;
	t_stack	*current;

	markup_head_ind = find_markup_head_ind(stk);
	current = stk;
	while (current->index != markup_head_ind)
	{
		current->keep_in_a = FALSE;
		current = current->next;
	}
	current->keep_in_a = TRUE;
	current = current->next;
	while (current)
	{
		if (current->index == markup_head_ind + 1)
		{
			current->keep_in_a = TRUE;
			markup_head_ind++;
		}
		else
			current->keep_in_a = FALSE;
		current = current->next;
	}
	return (stk);
}
