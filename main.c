/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:23 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/26 15:34:08 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_list(t_list **list)
{
	t_list	*temp_list;

	if (*list)
	{
		while (*list)
		{
			temp_list = (*list)->next;
			free (*list);
			(*list) = temp_list;
		}
	}
}

int	find_head(t_list *cpylistA)
{
	int	i;

	i = 0;
	while (cpylistA->index != 0)
	{
		i++;
		cpylistA = cpylistA->next;
	}
	return (i);
}

void	normalize(t_list **listA, int lst_size)
{
	int	i;
	int	num;

	i = find_head (*listA);
	if (!i)
		return ;
	if (lst_size / 2 >= i)
	{
		while ((*listA)->index != 0)
		{
			rotate_stack (listA);
			ft_putendl_fd("ra", 1);
		}
	}
	else if (lst_size / 2 < i)
	{
		num = lst_size - i;
		i = 0;
		while (i++ < num)
		{
			reverse_rotate_stack (listA);
			ft_putendl_fd("rra", 1);
		}
	}
}

int	main(int argc, char *argv[])
{
	int		arr_length;
	int		*arr;
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	arr = validation(argc, argv, &arr_length);
	initialisation(arr, &list_a, arr_length);
	a_to_b(&list_a, &list_b);
	b_to_a(&list_a, &list_b);
	normalize (&list_a, ft_lstsize(list_a));
	free (arr);
	clear_list (&list_a);
	return (0);
}
