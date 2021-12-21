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

void markup_by_index (t_list **listA)
{
	int	i;
	t_list *list;

	i = 0;
	list = *listA;
	while (list)
	{
		if (i == list->index)
		{
			list->keep_a = 1;
			i++;
		}
		else
			list->keep_a = 0;
		list = list->next;
	}
}

int initialisation(int *arr, t_list **listA, int arr_length)
{
	int	i;
	t_list	*temp_list;
	i = 0;
	while (i < arr_length)
	{
		temp_list = ft_lstnew(arr[i++], -1, -1);
		if (NULL == temp_list)
			return (0);
		ft_lstadd_back(listA, temp_list);
	}
	sort_arr(arr, arr_length);
	list_indexing (listA, arr, arr_length);
	my_markup_greater_then(listA);
	return (1);
}