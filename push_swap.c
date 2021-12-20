#include "push_swap.h"

void normalize (t_list *cpylistA, t_list **listA, int lst_size)
{
	int	i;
	int	num;

	i = 0;
	while (cpylistA->index != 0)
	{
		i++;
		cpylistA = cpylistA->next;
	}
	if (lst_size / 2 >= i)
		while ((*listA)->index != 0)
		{
			rotate_stack (listA);
			ft_putendl_fd("ra", 1);
		}
	else if (lst_size / 2 <  i)
	{
		num = lst_size - i;
		i = 0;
		while (i < num)
		{
			reverse_rotate_stack (listA);
			ft_putendl_fd("rra", 1);
			i++;
		}
	}
}

int main (int argc, char *argv[])
{
	int ok;
	int arr_length;
	int *arr;
	t_list	*listA;
	t_list	*listB;

	listA = NULL;
	listB = NULL;
	ok = validation(argc, argv, &arr, &arr_length);
	if (-1 == ok)
		return (0);
	if (!ok)
		return (0);
	// print_list (&listA);
	initialisation(arr, &listA, arr_length - 1);
	// print_list (&listA);
	list_sort(&listA, &listB);
	// print_list (&listA);
	preparing_b_to_a(&listA, &listB);
	// print_list (&listB);
	normalize (listA, &listA, ft_lstsize(listA));
	// print_list (&listA);
	free (arr);
	return (0);
}