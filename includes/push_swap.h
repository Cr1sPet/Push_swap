/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:46 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/29 12:55:24 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				index;
	int				keep_a;
	int				content;

}	t_stack;

typedef struct s_markup_info
{
	t_stack	*markup_head;
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

int			str_cmp(char *s1, char *s2);
char		*ft_strchr(const char *str, int ch);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_atoi(const char *str);
int			ft_isdigit(int ch);
char		*ft_strdup(const char *str);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew(int content, int index, int keep_a);
int			ft_lstsize(t_stack *lst);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);
int			*validation(int argc, char **argv, int *arr_length);
int			check_atoi(char *str);
void		clear_list(t_stack **list);
void		pre_valid(char *str, char **res);
int			str_duo_len(char **arr, int *arr_length);
int			write_bad_message(void);
int			initialisation(int *arr, t_stack **list, int arr_length);
int			b_to_a(t_stack **stack_a, t_stack **stack_b);
int			is_positive(int num);
int			get_min_num(int a, int b);
int			get_max_num(int a, int b);
int			get_num_abs(int a);
int			s_commands (char *str, t_stack **stack_a, t_stack **stack_b);
int			find_min_elem_number(t_b_to_a	*info_b_to_a, int stack_b_size);
void		markup_gt(t_stack **list, int lst_sz);
void		a_to_b(t_stack **list, t_stack **stack_b);
void		reverse_rotate_stack(t_stack **list);
void		rotate_stack(t_stack **list);
void		push_stack(t_stack **src, t_stack **dest);
void		swap_stack(t_stack **list);
void		print_stack(t_stack **list);
void		normalize(t_stack **listA, int lst_size);
void		find_a_elem(t_stack **stack_a, t_b_to_a *info_b_to_a, int a_sz);
void		elem_b_to_a(t_stack **list_a, t_stack **list_b, t_b_to_a info_b_to_a);
void		s_swap_stack(t_stack **stack_a, t_stack **stack_b);
void		s_rotate_stack (t_stack **stack_a, t_stack **stack_b);
void		s_reverse_rotate_stack (t_stack **stack_a, t_stack **stack_b);
t_b_to_a	find_b_elem(t_stack *stack_b, t_stack **stack_bb, const int b_sz);
t_b_to_a	*get_inf_arr(t_stack **list_a, t_stack **list_b, int a_sz, int b_sz);
#endif