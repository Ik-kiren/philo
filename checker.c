/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:51:22 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/18 15:04:28 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int(long nbr, int i)
{
	if (nbr > INT_MAX)
		return (0);
	else if (nbr >= INT_MAX && i == 1)
		return (0);
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '+')
			i++;
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

int	check_num(char *str, int j)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (check_int(ft_atol(str), j));
}

int	checker(int argc, char **argv)
{
	int	i;
	int	check;

	i = 1;
	while (i < argc)
	{
		check = check_num(argv[i], i);
		if (check == 0)
		{
			ft_printf("error\n");
			return (check);
		}
		i++;
	}
	return (check);
}
