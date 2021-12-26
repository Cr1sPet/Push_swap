#include "push_swap.h"

int	get_max_num(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	get_min_num(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

// int	find_best_elem(t_b_to_a	*info_b_to_a, int stack_b_size, int min)
// {
// 	int	i;
// 	int	min1;
// 	int	num;

// 	i = 0;
// 	num = 0;
// 	min1 = 2000000000;
// 	while (i < stack_b_size)
// 	{
// 		if ((info_b_to_a[i]).min_sum_iters == min)
// 		{
// 			if ((info_b_to_a[i]).iters_a < min1)
// 			{
// 				num = i;
// 				min1 = (info_b_to_a[i]).iters_a;
// 				if ((info_b_to_a[i]).iters_a == 0)
// 					return (i);
// 			}
// 		}
// 		i++;
// 	}
// 	return (num);
// }

int	find_min_elem_number(t_b_to_a	*info_b_to_a, int stack_b_size)
{
	int	i;
	int	min;
	int	num;

	i = 0;
	num = 0;
	min = (info_b_to_a[i]).min_sum_iters;
	while (i < stack_b_size - 1)
	{
		i++;
		if ((info_b_to_a[i]).min_sum_iters < min)
		{
			num = i;
			min = (info_b_to_a[i]).min_sum_iters;
		}
	}
	return (find_best_elem(info_b_to_a, stack_b_size, min));
}

void	find_min_summary_iterations(t_b_to_a	*elem, int stack_b_size)
{
	(elem[0]).min_iterations
		= get_min_num ((elem[0]).iters_a,
			(elem[0]).iters_b);
	if (((elem[0]).sign_a == (elem[0]).sign_b)
		&& (elem[0]).sign_b)
	{
		elem[0].min_sum_iters = get_max_num(elem[0].iters_a, elem[0].iters_b);
		(elem[0]).reverse_same_time = 1;
	}	
	else
	{
		(elem[0]).min_sum_iters
			= (elem[0]).iters_a
			+ (elem[0]).iters_b;
		(elem[0]).reverse_same_time = 0;
	}
}

t_b_to_a	*get_inf_arr(t_list **list_a, t_list **list_b, int a_sz, int b_sz)
{
	int				i;
	t_list			*stack_a;
	t_list			*stack_b;
	t_b_to_a		*info_b_to_a;

	i = 0;
	stack_b = *list_b;
	info_b_to_a = (t_b_to_a *)malloc (sizeof(t_b_to_a) * b_sz);
	if (NULL == info_b_to_a)
		return ((void *)0);
	while (i < b_sz)
	{
		info_b_to_a[i] = find_b_elem (stack_b, list_b, b_sz);
		find_a_elem (list_a, &(info_b_to_a[i]), a_sz);
		find_min_summary_iterations (&(info_b_to_a[i]), b_sz);
		i++;
		stack_b = stack_b->next;
	}
	return (info_b_to_a);
}
