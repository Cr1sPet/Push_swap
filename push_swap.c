#include "push_swap.h"

int main (int argc, char *argv[])
{
	int	*arr;

	 if (1 == argc)
	 	return (0);
	 if (!is_valid(argc, argv, &arr))
	 {
	 	ft_putendl_fd("Error2", 2);
	 	return (0);
	 }
	 ft_putendl_fd("OK", 1);
		ft_putendl_fd("hello",1);
	return (0);
}