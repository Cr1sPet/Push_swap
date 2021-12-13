#include "push_swap.h"

static void sort_arr(int *arr, int arr_length)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < arr_length - 1)
	{
		j = 0;
		while (j < arr_length - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
    }
}

static void list_indexing(t_list **listA, int *arr, int arr_length)
{
	int	i;
	int	ok;
	t_list *list;

	list = *listA;
	while (list)
	{
		i = 0;
		ok = 1;
		while (i < arr_length && ok)
		{
			if (list->content == arr[i])
			{
				list->index = i;
				ok = 0;
			}
			i++;
		}
		list = list->next;
	}
}


void print_arr(int *arr, int arr_length)
{
	int	i;

	i = 0;
	while (i < arr_length)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void print_list(t_list **listA)
{
	t_list *list;

	list = *listA;
	while (list)
	{
		printf("----\nindex = %d\ncontent = %d\n", list->index, list->content);
		list = list->next;
	}
}

int initialisation(int *arr, t_list **listA, int arr_length)
{
	int	i;

	i = 0;
	while (i < arr_length)
		ft_lstadd_back(listA, ft_lstnew(arr[i++]));
	sort_arr(arr, arr_length);
	list_indexing (listA, arr, arr_length);
	print_list(listA);
	return (0);
}