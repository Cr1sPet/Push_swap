#include "push_swap.h"


void go_rotate_stack (t_list **stack, int sign)
{
	if (1 == sign)
		rotate_stack(stack);
	else if (-1 == sign)
		reverse_rotate_stack(stack);
}

void	print_command (int sign, char correct)
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

void	prepare_diff_time (t_list **stack_a, t_list **stack_b, t_info_a_to_b elem_info_a_to_b)
{
	int	i;

	i = 0;
	while (i < elem_info_a_to_b.number_top_iterations_a)
		{
			go_rotate_stack (stack_a, elem_info_a_to_b.iterations_sign_a);
			print_command (elem_info_a_to_b.iterations_sign_a, 'a');
			i++;
		}
		i = 0;
		while (i < elem_info_a_to_b.number_top_iterations_b)
		{
			go_rotate_stack (stack_b, elem_info_a_to_b.iterations_sign_b);
			print_command (elem_info_a_to_b.iterations_sign_b, 'b');
			i++;
		}
}

void	prepare_same_time (t_list **stack_a, t_list **stack_b, t_info_a_to_b elem_info_a_to_b)
{
	int i;

	i = 0;
	while (i < elem_info_a_to_b.min_iterations)
	{
		go_rotate_stack (stack_a, elem_info_a_to_b.iterations_sign_a);
		go_rotate_stack (stack_b, elem_info_a_to_b.iterations_sign_a);
		print_command (elem_info_a_to_b.iterations_sign_a, 'r');
		i++;
	}
	while (i < elem_info_a_to_b.min_summary_iterations)
	{
		if (elem_info_a_to_b.has_more_iterations == 'A')
		{
			go_rotate_stack (stack_a, elem_info_a_to_b.iterations_sign_a);
			print_command (elem_info_a_to_b.iterations_sign_a, 'a');
		}
		else if(elem_info_a_to_b.has_more_iterations == 'B')
		{
			go_rotate_stack (stack_b, elem_info_a_to_b.iterations_sign_b);
			print_command (elem_info_a_to_b.iterations_sign_b, 'b');
		}
		i++;
	}
}

void    elem_b_to_a (t_list **stack_a, t_list **stack_b, t_info_a_to_b elem_info_a_to_b)
{
	if (elem_info_a_to_b.reverse_same_time)
		prepare_same_time (stack_a, stack_b, elem_info_a_to_b);
	else
		prepare_diff_time (stack_a, stack_b, elem_info_a_to_b);
	push_stack (stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}