#include "push_swap.h"

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

static int	find_head(t_stack *cpylistA)
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

void	normalize(t_stack **listA, int lst_size)
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