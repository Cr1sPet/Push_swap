#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
typedef struct s_markup_info
{
	t_list *markup_head;
	int	temp_head;
	int	seq_size;
	int	place;	
} t_markup_info;
typedef struct s_info_a_to_b
{
	int index_a;
	int place_a;
	int index_b;
	int place_b;
	int number_top_iterations_a;
	int number_top_iterations_b;
	int iterations_sign_a;
	int iterations_sign_b;
	int min_summary_iterations;
	int min_iterations;
	char has_more_iterations;
	int reverse_same_time;
	char	has_bigger_index;
} t_info_a_to_b;
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
void push_stack (t_list **src, t_list **dest);
void swap_stack (t_list **list);
int preparing_b_to_a(t_list **stack_a, t_list **stack_b);
void print_list(t_list **list);
int is_positive (int num);
int get_min_num (int a, int b);
int get_max_num (int a, int b);
void    elem_b_to_a (t_list **stack_a, t_list **stack_b, t_info_a_to_b elem_info_a_to_b);
int get_num_abs (int a);
void my_markup_greater_then (t_list **list);
#endif