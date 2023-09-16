#include "philo.h"

void	free_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		pthread_mutex_destroy(&table->philos[i].left_fork);
		i++;
	}
}

void	free_table(t_table *table)
{
	free(table->philos);
	free_forks(table);
	pthread_mutex_destroy(&table->eating);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->isdead);
	pthread_mutex_destroy(&table->end);
}
