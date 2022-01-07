/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchopped <jchopped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:03:42 by jchopped          #+#    #+#             */
/*   Updated: 2021/12/28 13:20:00 by jchopped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	str_duo_len(char **arr, int *arr_length)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	*arr_length = i;
	return (i);
}

int	write_bad_message(void)
{
	ft_putendl_fd("Error", 2);
	exit (1);
}

int	check_atoi(char *str)
{
	int			i;
	long long	res;

	i = 0;
	while (str[i])
	{
		if ('-' == str[i] && i != 0)
			return (0);
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	res = ft_atoi(str);
	if ((2 < ft_strlen(str)) && (-1 == res || 0 == res))
		return (0);
	return (1);
}

void	pre_valid(char *str, char **res)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			ok = 1;
		i++;
	}
	if (!ok || !str[0])
	{
			free (*res);
		write_bad_message();
	}
}
