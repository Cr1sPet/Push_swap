#include "push_swap.h"

int main (int argc, char *argv[])
{
	int ok;
	int arr_length;
	int *arr;
	t_list *listA;

	listA = NULL;
	ok = validation(argc, argv, &arr, &arr_length);
	if (-1 == ok)
		return (0);
	if (!ok)
		return (0);
	ft_putendl_fd("OK", 1);
	initialisation(arr, &listA, arr_length - 1);
	free (arr);
	return (0);
}