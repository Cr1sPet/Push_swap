#include "push_swap.h"

int main (int argc, char *argv[])
{
	int ok;
	int arr_length;
	int *arr;
	t_list	*listA;
	t_list	*listB;

	listA = NULL;
	ok = validation(argc, argv, &arr, &arr_length);
	if (-1 == ok)
		return (0);
	if (!ok)
		return (0);
	initialisation(arr, &listA, arr_length - 1);
	list_sort(&listA, &listB);
	preparing_b_to_a(&listA, &listB);
	// print_list (&listB);
	while (listA->index != 0)
	{
		rotate_stack (&listA);
		ft_putendl_fd("ra", 1);
	}
	// print_list (&listA);
	free (arr);
	return (0);
}