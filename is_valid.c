#include "push_swap.h"

static int check_individuality(int **arr, int argc)
{
	int	i;
	int j;
	int counter;

	i = 0;
	while (i < argc - 2)
	{
		j = 0;
		counter = 0;
		while (j < argc - 2)
		{
			if (arr[i] == arr[j])
				counter++;
			j++;
		}
		if (1 != counter)
		{
			free (*arr);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_argv(char *str)
{
	int	i;
	long long	res;


	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
				return (0);
	if ((2 < ft_strlen(str)) && (-1 == ft_atoi(str) || 0 == ft_atoi(str)))
		return (0);
	res = ft_atoi(str);
	if (2147483647 < res || -2147483648 > res)
		return (0);
	// arr[0] = (int)res;
	return (1);
}

int is_valid(int argc, char *argv[], int **input_arr)
{
	int	i;
	int	ok;
	int	*arr;

	i = 1;
	ok = 1;
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (NULL == arr)
		return (0);	
	while (i < argc - 1)
	{
		if (!check_argv(argv[i]))
		{
			free(arr);
			return (0);
		}
		arr [i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ok = check_individuality(&arr, argc);
	if (ok)
		*input_arr = arr;
	return (ok);
}