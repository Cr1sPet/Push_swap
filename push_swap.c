#include "push_swap.h"

int main (int argc, char *argv[])
{
	int		ok;
	int		*arr;
	char	**new_argv;

	ok = 2;
	if (1 == argc)
	 	return (0);
	if (2 == argc && ft_strchr(argv[1], ' '))
	{
		ok = try_split(argv[1], &new_argv);
	if(!ok)
	{
		ft_putendl_fd("Error2", 2);
		return (0);
	}
	if (1 == ok)
	{
		int j = 0;
		while (new_argv[j])
			j++;
		if (!is_valid(j + 1, new_argv, &arr, 1))
		{
			ft_putendl_fd("Error2", 2);
			return (0);
		}
	}
	}
	else if (!is_valid(argc, argv, &arr, 0))
	{
		ft_putendl_fd("Error2", 2);
		return (0);
	}
	ft_putendl_fd("OK", 1);
	if (1 == ok)
	{
		int i = 0;

		while (new_argv[i])
		{
			free (new_argv[i]);
			i++;
		}
		free (new_argv);
	}
	free (arr);
	return (0);
}