/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:44:28 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/28 12:24:35 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content, int index, int keep_a)
{
	t_stack	*new_list;

	new_list = (t_stack *)malloc(sizeof(t_stack));
	if ((void *)0 == new_list)
		return ((void *)0);
	new_list->content = content;
	new_list->index = index;
	new_list->keep_a = keep_a;
	new_list->next = (void *)0;
	return (new_list);
}
