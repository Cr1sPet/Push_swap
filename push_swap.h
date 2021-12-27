/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:46 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/26 15:15:35 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_markup_info
{
	t_list	*markup_head;
	int		temp_head;
	int		seq_size;
	int		place;	
	int		border;
}	t_markup_info;
typedef struct s_b_to_a
{
	int	index_a;
	int	place_a;
	int	index_b;
	int	place_b;
	int	iters_a;
	int	iters_b;
	int	sign_a;
	int	sign_b;
	int	min_sum_iters;
	int	min_iterations;
	int	reverse_same_time;
}	t_b_to_a;


char		*get_next_line(int fd);
int			*validation(int argc, char **argv, int *arr_length);
int			check_atoi(char *str);
void		clear_list(t_list **list);
void		pre_valid(char *str, char **res);
int			str_duo_len(char **arr, int *arr_length);
int			write_bad_message(void);
int			initialisation(int *arr, t_list **list, int arr_length);
int			b_to_a(t_list **stack_a, t_list **stack_b);
int			is_positive(int num);
int			get_min_num(int a, int b);
int			get_max_num(int a, int b);
int			get_num_abs(int a);
int			s_commands (char *str, t_list **stack_a, t_list **stack_b);
int			find_min_elem_number(t_b_to_a	*info_b_to_a, int stack_b_size);
void		markup_gt(t_list **list, int lst_sz);
void		a_to_b(t_list **list, t_list **stack_b);
void		reverse_rotate_stack(t_list **list);
void		rotate_stack(t_list **list);
void		push_stack(t_list **src, t_list **dest);
void		swap_stack(t_list **list);
void		print_list(t_list **list);
void		find_a_elem(t_list **stack_a, t_b_to_a *info_b_to_a, int a_sz);
void		elem_b_to_a(t_list **list_a, t_list **list_b, t_b_to_a info_b_to_a);
void		s_swap_stack (t_list **stack_a, t_list **stack_b);
void		s_rotate_stack (t_list **stack_a, t_list **stack_b);
void		s_reverse_rotate_stack (t_list **stack_a, t_list **stack_b);
t_b_to_a	find_b_elem(t_list *stack_b, t_list **stack_bb, const int b_sz);
t_b_to_a	*get_inf_arr(t_list **list_a, t_list **list_b, int a_sz, int b_sz);
#endif