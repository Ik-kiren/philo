/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:46:09 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/18 13:52:57 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(t_philo *philo)
{
	philo->left_fork = philo->id;
	philo->right_fork = (philo->id + 1) % philo->table->nbr_philos;
	if (philo->id % 2)
	{
		philo->right_fork = philo->id;
		philo->left_fork = (philo->id + 1) % philo->table->nbr_philos;
	}
}

t_philo	**init_philos(t_table *table)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * table->nbr_philos);
	while (i < table->nbr_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->id = i;
		philos[i]->table = table;
		philos[i]->nb_eat = 0;
		pthread_mutex_init(&philos[i]->eating, NULL);
		get_forks(philos[i]);
		i++;
	}
	return (philos);
}

pthread_mutex_t	*init_mutex_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philos);
	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

void	init_mutex(t_table *table)
{
	table->forks = init_mutex_forks(table);
	pthread_mutex_init(&table->end, NULL);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->isdead, NULL);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	table->nbr_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->died = 0;
	table->total_eat = -1;
	if (argc == 6)
		table->total_eat = ft_atoi(argv[5]);
	table->philos = init_philos(table);
	init_mutex(table);
	return (table);
}
