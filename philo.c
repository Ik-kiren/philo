/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:31:35 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/17 19:48:49 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *str, int end)
{
	pthread_mutex_lock(&philo->table->print);
	if (check_end(philo->table) && end)
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	printf("%ld %d %s\n", get_time() - philo->table->start_t, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);
}

void	start(t_table *table)
{
	int	i;

	i = 0;
	table->start_t = get_time();
	while (i < table->nbr_philos)
	{
		pthread_create(&table->philos[i]->philo_tid, NULL, &activities, table->philos[i]);
		i++;
	}
	if (table->nbr_philos > 1)
	{
		pthread_create(&table->death_tid, NULL, &death, table);
	}
}

void	end(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_join(table->philos[i]->philo_tid, NULL);
		i++;
	}
	if (table->nbr_philos > 1)
		pthread_join(table->death_tid, NULL);
	free_table(table);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!checker(argc, argv))
		return (0);
	table = init_table(argc, argv);
	start(table);
	end(table);
}
