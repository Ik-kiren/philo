/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:31:35 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/16 16:38:36 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->table->isdead);
	if (i)
		philo->table->died = i;
	if (philo->table->died)
	{
		pthread_mutex_unlock(&philo->table->isdead);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->isdead);
	return (0);
}

void	print_action(t_philo *philo, char *str)
{
	if (!check_death(philo, 0))
	{
		pthread_mutex_lock(&philo->table->print);
		printf("%ld %d %s\n", get_time(), philo->id, str);
		pthread_mutex_unlock(&philo->table->print);
	}
}

int	check_end(t_table *table)
{
	pthread_mutex_lock(&table->isdead);
	if (table->died)
	{
		pthread_mutex_unlock(&table->isdead);
		return (1);
	}
	pthread_mutex_unlock(&table->isdead);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	i = 0;
	if (!checker(argc, argv))
		return (0);
	init_table(&table, argc, argv);
	while (i <= table.nbr_philos - 1)
	{
		pthread_create(&table.philos[i].philo_tid, NULL, activities, &table.philos[i]);
		i++;
	}
	i = 0;
	while (!check_end(&table))
		ft_usleep(1);
	while (i < table.nbr_philos)
	{
		pthread_join(table.philos[i].philo_tid, NULL);
		i++;
	}
	if (table.died == 2)
		printf("%ld everyone ate %d time\n", get_time(), table.nb_eat);
	free_table(&table);
}
