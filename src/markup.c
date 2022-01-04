/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_markup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:54 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/26 15:16:17 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_place(t_stack *list, int head, t_markup_info *markup_info)
{
	int	i;

	i = 0;
	while (list && list->index != head)
	{
		i++;
		list = list->next;
	}
	if (!list)
	{
		markup_info->seq_size = -2;
		return (0);
	}
	markup_info->markup_head = list;
	markup_info->place = i;
	return (1);
}

void	find_seq_size(t_stack *list, t_stack *temp_list,
		t_markup_info *markup_info, int val)
{
	while (temp_list)
	{
		temp_list->keep_a = 0;
		if (temp_list->index >= val)
		{
			val = temp_list->index;
			markup_info->seq_size++;
			temp_list->keep_a = 1;
		}
		temp_list = temp_list->next;
	}
	temp_list = markup_info->markup_head;
	while (list->index != temp_list->index)
	{
		list->keep_a = 0;
		if (list->index > val)
		{
			val = list->index;
			markup_info->seq_size++;
			list->keep_a = 1;
		}
		list = list->next;
	}
}

void	find_seq_sz(t_stack *list, t_markup_info *markup_info)
{
	markup_info->seq_size = 0;
	if (!find_place (list, markup_info->temp_head, markup_info))
		return ;
	find_seq_size (list, markup_info->markup_head,
		markup_info, markup_info->temp_head);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = -1;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	markup_gt(t_stack **list, int a_sz)
{
	int				i;
	int				max;
	int				mrkp_head;
	t_markup_info	markup_info;

	i = 0;
	max = -1;
	while (i < a_sz - 1)
	{
		markup_info.temp_head = i;
		find_seq_sz (*list, &markup_info);
		if (markup_info.seq_size > max)
		{
			max = markup_info.seq_size;
			mrkp_head = i;
		}
		i++;
	}
	markup_info.temp_head = mrkp_head;
	find_seq_sz (*list, &markup_info);
}
