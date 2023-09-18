/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:31:35 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/18 14:58:25 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *str, int end)
{
	int	time;

	pthread_mutex_lock(&philo->table->print);
	if (check_end(philo->table) && end)
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	time = get_time() - philo->table->start_t;
	ft_printf("%d %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);
}

void	start(t_table *t)
{
	int	i;

	i = 0;
	t->start_t = get_time();
	while (i < t->nbr_philos)
	{
		pthread_create(&t->philos[i]->tid, NULL, &activities, t->philos[i]);
		i++;
	}
	if (t->nbr_philos > 1)
		pthread_create(&t->death_tid, NULL, &death, t);
}

void	end(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_join(table->philos[i]->tid, NULL);
		i++;
	}
	if (table->nbr_philos > 1)
		pthread_join(table->death_tid, NULL);
	if (table->total_eat != -1)
		ft_printf("everyone ate %d times\n", table->total_eat);
	free_table(table);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5)
	{
		ft_printf("error\n");
		return (0);
	}
	if (!checker(argc, argv))
		return (0);
	table = init_table(argc, argv);
	start(table);
	end(table);
}
