#include "philo.h"

void	*death_thread(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	ft_usleep(table->time_to_die + 1);
	pthread_mutex_lock(&table->eating);
	pthread_mutex_lock(&table->end);
	if (!check_death(philo, 0) && get_time() - philo->last_meal > table->time_to_die && table->died == 0)
	{
		pthread_mutex_unlock(&table->eating);
		pthread_mutex_unlock(&table->end);
		print_action(philo, "has died");
		printf("pk2 %d\n", table->died);
		check_death(philo, 1);
	}
	pthread_mutex_unlock(&table->eating);
	pthread_mutex_unlock(&table->end);
	return (NULL);
}

void	philo_eats(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&table->eating);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&table->eating);
	ft_usleep(table->time_to_eat);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*activities(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	if (philo->id % 2)
		ft_usleep(table->time_to_die / 10);
	while (!check_death(philo, 0))
	{
		pthread_create(&philo->death_tid, NULL, death_thread, philo);
		philo_eats(table, philo);
		print_action(philo, "is sleeping");
		ft_usleep(table->time_to_sleep);
		print_action(philo, "is thinking");
		pthread_detach(philo->death_tid);
		philo->nb_eat++;
		if (philo->nb_eat == table->nb_eat)
		{
			pthread_mutex_lock(&table->end);
			table->total_eat++;
			if (table->total_eat == table->nbr_philos)
			{
				pthread_mutex_unlock(&table->end);
				check_death(philo, 2);
			}
			pthread_mutex_unlock(&table->end);
			return (NULL);
		}
	}
	return (NULL);
}
