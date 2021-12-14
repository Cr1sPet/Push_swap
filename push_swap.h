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
void	list_sort(t_list **list, t_list **stack_b);
void	markup_by_index (t_list **listA);
void reverse_rotate_stack (t_list **list);
void rotate_stack (t_list **list);
void push_stack (t_list **stack_a, t_list **stack_b);
void swap_stack (t_list **list);
void move_b_to_a(t_list **stack_a, t_list **stack_b);
void print_list(t_list **list);
#endif