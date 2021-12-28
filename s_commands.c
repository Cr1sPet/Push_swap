#include "push_swap.h"

void	s_swap_stack(t_list **stack_a, t_list **stack_b)
{
	swap_stack (stack_a);
	swap_stack (stack_b);
}

void	s_rotate_stack(t_list **stack_a, t_list **stack_b)
{
	rotate_stack (stack_a);
	rotate_stack (stack_b);
}

void	s_reverse_rotate_stack(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_stack (stack_a);
	reverse_rotate_stack (stack_b);
}

int	s_commands(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp("ss", str, ft_strlen (str)))
		s_swap_stack (stack_a, stack_b);
	else if (!ft_strncmp("rr", str, ft_strlen (str)))
		s_rotate_stack (stack_a, stack_b);
	else if (!ft_strncmp("rrr", str, ft_strlen (str)))
		s_reverse_rotate_stack (stack_a, stack_b);
	else
		return (0);
	return (1);
}