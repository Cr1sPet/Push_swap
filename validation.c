#include "push_swap.h"

static int	check_individuality(int **arr, int argc)
{
	int	i;
	int	j;
	int	counter;
	int	*new_arr;

	i = 0;
	new_arr = *arr;
	while (i < argc - 1)
	{
		j = 0;
		counter = 0;
		while (j < argc - 1)
			if (new_arr[i] == new_arr[j++])
				counter++;
		if (1 != counter)
		{
			free (new_arr);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	try_split(char *str, char ***argv)
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

static int	is_valid(int argc, char *argv[], int **input_arr, int fa)
{
	int	i;
	int	ok;
	int	*arr;

	i = 1;
	ok = 1;
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (NULL == arr)
		return (0);	
	while (i < argc - fa)
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

// int	validation(int argc, char **argv, int **arr, int *arr_length)
// {
// 	int		ok;
// 	int		i;
// 	char	**new_argv;

// 	i = 0;
// 	*arr_length = argc;
// 	if (1 == argc)
// 		return (0);
// 	else if (2 == argc && ft_strchr(argv[1], ' '))
// 	{
// 		ok = try_split(argv[1], &new_argv);
// 		if (!ok)
// 			return (write_bad_message());
// 		if (!is_valid(str_duo_len(new_argv, arr_length) + 1, new_argv, arr, 1))
// 			return (write_bad_message());
// 		while (new_argv[i])
// 			free (new_argv[i++]);
// 		free (new_argv);
// 	}
// 	else if (!is_valid(argc, argv, arr, 0))
// 		return (write_bad_message());
// 	return (1);
// }

int	validation(int argc, char **argv, int **arr, int *arr_length)
{
	
}
