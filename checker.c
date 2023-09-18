/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:51:22 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/18 13:51:27 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int(long nbr)
{
	if (nbr > INT_MAX)
		return (0);
	return (1);
}

int	check_num(char *str)
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
	return (check_int(atol(str)));
}

int	checker(int argc, char **argv)
{
	int	i;
	int	check;

	i = 1;
	while (i < argc)
	{
		check = check_num(argv[i]);
		if (check == 0)
		{
			ft_printf("error\n");
			return (check);
		}
		i++;
	}
	return (check);
}
