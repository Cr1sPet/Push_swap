#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
// typedef struct s_list 
// {
// 	int		index;
// 	void	*next;
// 	int		content;

// } t_list;
int		validation (int argc, char **argv, int **arr, int *arr_length);
int		check_argv(char *str);
int		check_atoi(char *str);
int		str_duo_len(char **arr, int *arr_length);
int		write_bad_message();
int		initialisation(int *arr, t_list **list, int arr_length);
void	list_sort(t_list **list);
void	markup_by_index (t_list **listA);
#endif