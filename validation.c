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

static void	check_individuality(int **arr, int argc)
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
			free (new_arr);
			write_bad_message();
		}
		i++;
	}
}

static void	joiner(int argc, char *argv[], char **res)
{
	int		i;
	char	*temp;

	i = 1;
	*res = ft_strdup (" ");
	if (NULL == *res)
		exit (1);
	while (i < argc)
	{
		pre_valid(argv[i], res);
		temp = *res;
		*res = ft_strjoin (temp, " ");
		free (temp);
		temp = *res;
		*res = ft_strjoin(temp, argv[i]);
		if (NULL == *res)
		{
			free (temp);
			exit(1);
		}	
		free (temp);
		i++;
	}
}

static int	splitter(char *str, char ***argv)
{
	int	i;
	int	ok;
	int	str_len;

	i = 0;
	ok = 0;
	str_len = ft_strlen(str);
	while (i < str_len)
		if (ft_isdigit(str[i++]))
			ok = 1;
	if (!ok)
		return (0);
	*argv = ft_split(str, ' ');
	if (NULL == *argv)
		exit (1);
	return (ok);
}

static void	is_valid(int argc, char *argv[], int **input_arr)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (argc));
	if (NULL == arr)
		exit (1);
	while (i < argc)
	{
		if (!check_atoi(argv[i]))
		{
			free(arr);
			write_bad_message();
		}
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	check_individuality(&arr, argc);
	*input_arr = arr;
}

int	*validation(int argc, char **argv, int *arr_length)
{
	int		i;
	int		*arr;
	char	*res;
	char	**new_argv;

	i = 0;
	joiner (argc, argv, &res);
	if (ft_strlen(res) == 1 && res[0] == ' ')
	{
		free (res);
		exit (1);
	}
	splitter (res, &new_argv);
	free (res);
	is_valid(str_duo_len(new_argv, arr_length), new_argv, &arr);
	while (new_argv[i])
	{
		free (new_argv[i]);
		i++;
	}
	free (new_argv);
	return (arr);
}
