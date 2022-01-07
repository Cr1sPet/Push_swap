#include "push_swap.h"

void	clear_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	clear_list(t_stack **list)
{
	t_stack	*temp_list;

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

static int	find_head(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a->index != 0)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void	normalize(t_stack **stack_a, int lst_size)
{
	int	i;
	int	num;

	i = find_head (*stack_a);
	if (!i)
		return ;
	if (lst_size / 2 >= i)
	{
		while ((*stack_a)->index != 0)
		{
			rotate_stack (stack_a);
			ft_putendl_fd("ra", 1);
		}
	}
	else if (lst_size / 2 < i)
	{
		num = lst_size - i;
		i = 0;
		while (i++ < num)
		{
			reverse_rotate_stack (stack_a);
			ft_putendl_fd("rra", 1);
		}
	}
}
