#include "push_swap.h"

static void print_list(t_list **listA)
{
	t_list *list;

	list = *listA;
	while (list)
	{
		printf("----\nindex = %d\nkeep_a = %d\ncontent = %d\n", list->index, list->keep_a, list->content);
		list = list->next;
	}
}

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
	list_sort(&listA);
	free (arr);
	return (0);
}