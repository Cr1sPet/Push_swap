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

int	main(int argc, char *argv[])
{
	int		arr_length;
	int		*arr;
	t_stack	*list_a;
	t_stack	*list_b;

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
