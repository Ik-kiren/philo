/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:45:56 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/18 13:45:57 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_dead(t_philo *philo)
{
	time_t	time;

	time = get_time();
	if ((time - philo->last_meal) >= philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->end);
		philo->table->died = 1;
		pthread_mutex_unlock(&philo->table->end);
		print_action(philo, "is dead", 0);
		pthread_mutex_unlock(&philo->eating);
		return (1);
	}
	return (0);
}

int	check_death_true(t_table *table)
{
	int	i;
	int	philos_ate;

	i = 0;
	philos_ate = 1;
	while (i < table->nbr_philos)
	{
		pthread_mutex_lock(&table->philos[i]->eating);
		if (philo_dead(table->philos[i]) == 1)
			return (1);
		if (table->total_eat != 1)
			if (table->philos[i]->nb_eat < table->total_eat)
				philos_ate = 0;
		pthread_mutex_unlock(&table->philos[i]->eating);
		i++;
	}
	if (table->total_eat != -1 && philos_ate == 1)
	{
		pthread_mutex_lock(&table->end);
		table->died = 1;
		pthread_mutex_unlock(&table->end);
		return (1);
	}
	return (0);
}

int	check_end(t_table *table)
{
	pthread_mutex_lock(&table->end);
	if (table->died == 1)
	{
		pthread_mutex_unlock(&table->end);
		return (1);
	}
	pthread_mutex_unlock(&table->end);
	return (0);
}

void	*death(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	pthread_mutex_lock(&table->end);
	table->died = 0;
	pthread_mutex_unlock(&table->end);
	start_delay(table->start_t);
	while (1 == 1)
	{
		if (check_death_true(table))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
