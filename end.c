/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:46:12 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/18 13:46:13 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i]->eating);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->isdead);
	pthread_mutex_destroy(&table->end);
}

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	free_mutex(table);
	free(table->forks);
	while (i < table->nbr_philos)
	{
		free(table->philos[i]);
		i++;
	}
	free(table->philos);
	free(table);
}
