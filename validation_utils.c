#include "push_swap.h"
int str_duo_len (char **arr, int *arr_length)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	*arr_length = ++i;
	return (i);
}

int  write_bad_message()
{
	ft_putendl_fd("Error", 2);
	return (0);
}

int	check_atoi(char *str)
{
	long long	res;

	res = ft_atoi(str);
	if ((2 < ft_strlen(str)) && (-1 == ft_atoi(str) || 0 == ft_atoi(str)))
		return (0);
	return (1);
}

int	check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
				return (0);
	return (check_atoi(str));
}