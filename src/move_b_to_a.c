/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:11 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/26 15:03:12 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_rotate_stack(t_stack **stack, int sign)
{
	if (1 == sign)
		rotate_stack(stack);
	else if (-1 == sign)
		reverse_rotate_stack(stack);
}

void	print_command(int sign, char correct)
{
	if (sign == 1)
	{
		ft_putchar_fd ('r', 1);
		ft_putchar_fd (correct, 1);
		ft_putchar_fd ('\n', 1);
	}
	else if (sign == -1)
	{
		ft_putstr_fd ("rr", 1);
		ft_putchar_fd (correct, 1);
		ft_putchar_fd ('\n', 1);
	}
}

void	prepare_diff_time(t_stack **stack_a, t_stack **stack_b,
	t_b_to_a elem_info_a_to_b)
{
	int	i;

	i = 0;
	while (i < elem_info_a_to_b.iters_a)
	{
		go_rotate_stack (stack_a, elem_info_a_to_b.sign_a);
		print_command (elem_info_a_to_b.sign_a, 'a');
		i++;
	}
	i = 0;
	while (i < elem_info_a_to_b.iters_b)
	{
		go_rotate_stack (stack_b, elem_info_a_to_b.sign_b);
		print_command (elem_info_a_to_b.sign_b, 'b');
		i++;
	}
}

void	prepare_same_time(t_stack **stack_a,
	t_stack **stack_b, t_b_to_a elem_info_a_to_b)
{
	int	i;

	i = 0;
	while (i < elem_info_a_to_b.min_iterations)
	{
		go_rotate_stack (stack_a, elem_info_a_to_b.sign_a);
		go_rotate_stack (stack_b, elem_info_a_to_b.sign_a);
		print_command (elem_info_a_to_b.sign_a, 'r');
		i++;
	}
	while (i < elem_info_a_to_b.iters_a)
	{
		go_rotate_stack (stack_a, elem_info_a_to_b.sign_a);
		print_command (elem_info_a_to_b.sign_a, 'a');
		i++;
	}
	while (i < elem_info_a_to_b.iters_b)
	{
		go_rotate_stack (stack_b, elem_info_a_to_b.sign_b);
		print_command (elem_info_a_to_b.sign_b, 'b');
		i++;
	}
}

void	elem_b_to_a(t_stack **stack_a, t_stack **stack_b, t_b_to_a info_b_to_a)
{
	if (info_b_to_a.reverse_same_time)
		prepare_same_time (stack_a, stack_b, info_b_to_a);
	else
		prepare_diff_time (stack_a, stack_b, info_b_to_a);
	push_stack (stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}
