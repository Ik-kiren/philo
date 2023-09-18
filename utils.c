/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:46:01 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/18 13:53:21 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

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

void	start_delay(time_t start)
{
	while (get_time() < start)
		continue ;
}

void	ft_usleep(t_table *table, long int time)
{
	time_t	sleeps;

	sleeps = get_time() + time;
	while (get_time() < sleeps)
	{
		if (check_end(table))
			break ;
		usleep(100);
	}
}

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
