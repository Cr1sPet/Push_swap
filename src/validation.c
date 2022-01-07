/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:39 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/26 15:03:40 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_individuality(int **arr, int argc, char **argv)
{
	int	i;
	int	j;
	int	counter;
	int	*new_arr;

	i = 0;
	new_arr = *arr;
	while (i < argc)
	{
		j = 0;
		counter = 0;
		while (j < argc)
			if (new_arr[i] == new_arr[j++])
				counter++;
		if (1 != counter)
		{
			clear_arr(argv);
			free (new_arr);
			write_bad_message();
		}
		i++;
	}
}

static void	joiner(int argc, char *argv[], char **res)
{
	int		i;

	i = 1;
	*res = ft_strdup ("");
	if (NULL == *res)
		exit (EXIT_FAILURE);
	while (i < argc)
	{
		pre_valid(argv[i], res);
		*res = ft_strjoin (*res, " ");
		if (NULL == *res)
		{
			free (*res);
			exit(EXIT_FAILURE);
		}
		*res = ft_strjoin(*res, argv[i]);
		if (NULL == *res)
		{
			free (*res);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	splitter(char *str, char ***argv)
{
	*argv = ft_split(str, ' ');
	if (NULL == *argv)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
}

static void	is_valid(int argc, char *argv[], int **input_arr)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (argc));
	if (NULL == arr)
	{
		clear_arr(argv);
		exit (EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (!check_atoi(argv[i]))
		{
			free(arr);
			clear_arr(argv);
			write_bad_message();
		}
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	check_individuality(&arr, argc, argv);
	*input_arr = arr;
}

int	*validation(int argc, char **argv, int *arr_length)
{
	int		*arr;
	char	*res;
	char	**new_argv;

	if (argc < 3)
		exit(EXIT_SUCCESS);
	joiner (argc, argv, &res);
	if (ft_strlen(res) == 1 && res[0] == ' ')
	{
		free (res);
		exit (1);
	}
	splitter (res, &new_argv);
	free (res);
	is_valid(str_duo_len(new_argv, arr_length), new_argv, &arr);
	clear_arr(new_argv);
	return (arr);
}
