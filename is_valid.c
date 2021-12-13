#include "push_swap.h"

static int check_individuality(int **arr, int argc)
{
	int	i;
	int j;
	int counter;
	int *new_arr = *arr;
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		counter = 0;
		while (j < argc - 1)
		{
			int a = new_arr[i];
			int b = new_arr[j];
			if (new_arr[i] == new_arr[j])
				counter++;
			j++;
		}
		if (1 != counter)
		{
			free (new_arr);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_atoi(char *str)
{
	long long	res;

	res = ft_atoi(str);
	if ((2 < ft_strlen(str)) && (-1 == ft_atoi(str) || 0 == ft_atoi(str)))
		return (0);
	return (1);
}

static int	check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
				return (0);
	return (check_atoi(str));
}

int try_split(char *str, char ***argv)
{
	int	i;
	int	ok;
	int	str_len;


	i = 0;
	ok = 0;
	str_len = ft_strlen(str);
	while (i < str_len)
		if (ft_isdigit(str[i++]))
			ok = 1;
	if (!ok)
		return (0);
	*argv = ft_split(str, ' ');
	if (NULL == *argv)
		return (0);
	return (ok);
}

int is_valid(int argc, char *argv[], int **input_arr, int fa)
{
	int	i;
	int	ok;
	int	*arr;

	i = 1;
	ok = 1;
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (NULL == arr)
		return (0);	
	while (i < argc)
	{
		if (!check_argv(argv[-fa + i]))
		{
			free(arr);
			return (0);
		}
		arr [i - 1] = ft_atoi(argv[-fa + i]);
		i++;
	}
	ok = check_individuality(&arr, argc);
	if (ok)
		*input_arr = arr;
	return (ok);
}