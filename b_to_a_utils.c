#include "push_swap.h"

int get_max_num (int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int get_min_num (int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int get_num_abs (int a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}