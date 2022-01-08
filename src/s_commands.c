/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:44:03 by jchopped          #+#    #+#             */
/*   Updated: 2022/01/08 10:44:12 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	s_swap_stack(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack (stack_a);
	swap_stack (stack_b);
}

void	s_rotate_stack(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack (stack_a);
	rotate_stack (stack_b);
}

void	s_reverse_rotate_stack(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_stack (stack_a);
	reverse_rotate_stack (stack_b);
}

int	s_commands(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!str_cmp("ss\n", str))
		s_swap_stack (stack_a, stack_b);
	else if (!str_cmp("rr\n", str))
		s_rotate_stack (stack_a, stack_b);
	else if (!str_cmp("rrr\n", str))
		s_reverse_rotate_stack (stack_a, stack_b);
	else
		return (0);
	return (1);
}
