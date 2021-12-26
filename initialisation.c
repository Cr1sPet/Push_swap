/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:59 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/26 15:24:17 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int *arr, int arr_length)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < arr_length - 1)
	{
		j = 0;
		while (j < arr_length - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	list_indexing(t_list *list_a, int *arr, int arr_len)
{
	int		i;
	int		ok;

	while (list_a)
	{
		i = 0;
		ok = 1;
		while (i < arr_len && ok)
		{
			if (list_a->content == arr[i])
			{
				list_a->index = i;
				ok = 0;
			}
			i++;
		}
		list_a = list_a->next;
	}
}

int	initialisation(int *arr, t_list **list_a, int arr_len)
{
	int		i;
	int		a_sz;
	t_list	*temp_list;

	i = arr_len - 1;
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
	sort_arr(arr, arr_len);
	list_indexing(*list_a, arr, arr_len);
	a_sz = ft_lstsize (*list_a);
	markup_gt(list_a, a_sz);
	return (1);
}
