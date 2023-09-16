#include "philo.h"

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		table->philos[i].id = i;
		table->philos[i].last_meal = get_time();
		table->philos[i].right_fork = NULL;
		pthread_mutex_init(&table->philos[i].left_fork, NULL);
		table->philos[i].table = table;
		table->philos[i].nb_eat = 0;
		table->philos[i].last_meal = 0;
		if (i == table->nbr_philos - 1)
			table->philos[i].right_fork = &table->philos[0].left_fork;
		else
			table->philos[i].right_fork = &table->philos[i + 1].left_fork;
		i++;
	}
}

void	init_mutex(t_table *table)
{
	pthread_mutex_init(&table->eating, NULL);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->isdead, NULL);
	pthread_mutex_init(&table->end, NULL);
}

int init_table(t_table *table, int argc, char **argv)
{
	table->nbr_philos = atoi(argv[1]);
	table->time_to_die = atoi(argv[2]);
	table->time_to_eat = atoi(argv[3]);
	table->time_to_sleep = atoi(argv[4]);
	table->died = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_philos);
	table->nb_eat = -1;
	table->total_eat = 0;
	if (argc == 6)
		table->nb_eat = atoi(argv[5]);
	init_mutex(table);
	init_philos(table);
	return (0);
}
