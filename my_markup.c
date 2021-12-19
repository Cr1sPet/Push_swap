#include "push_swap.h"

int find_place (t_list *list, int head, t_markup_info *markup_info)
{
	int i;

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

void find_sequence_size (t_list *list, int lst_size, t_markup_info *markup_info)
{
	int		val;
	t_list	*temp_list;

	val = markup_info->temp_head;
	markup_info->seq_size = 0;
	if (!find_place (list, val, markup_info))
		return ;
	temp_list = markup_info->markup_head;
	while (temp_list)
	{
		if (temp_list->index >= val)
		{
			val = temp_list->index;
			markup_info->seq_size++;
		}
		temp_list = temp_list->next;
	}
	temp_list = markup_info->markup_head;
	while (list->index != temp_list->index)
	{
		if (list->index > val)
		{
			val = list->index;
			markup_info->seq_size++;
		}
		list = list->next;
	}
}

void set_mark_up (t_list *list, t_markup_info *markup_info, int mrkp_head)
{
	int		val;
	t_list	*temp_list;

	val = mrkp_head;
	find_place (list, val, markup_info);
	temp_list = markup_info->markup_head;
	while (temp_list)
	{
		if (temp_list->index >= val)
		{
			val = temp_list->index;
			temp_list->keep_a = 1;
		}
		else
			temp_list->keep_a = 0;
		temp_list = temp_list->next;
	}
	temp_list = markup_info->markup_head;
	while (list->index != temp_list->index)
	{
		if (list->index > val)
		{
			val = list->index;
			list->keep_a = 1;
		}
		else
			list->keep_a = 0;
		list = list->next;
	}
}

void my_markup_greater_then (t_list **list, int lst_size)
{
	int				i;
	int				max;
	int				mrkp_head;
	t_markup_info	markup_info;

	i = 0;
	max = -1;
	while (i < lst_size)
	{
		markup_info.temp_head = i;
		find_sequence_size(*list, lst_size, &markup_info);
		if (markup_info.seq_size > max)
		{
			max = markup_info.seq_size;
			mrkp_head = i;
		}
		i++;
	}
	set_mark_up (*list, &markup_info, mrkp_head);
	// print_list (list);
}