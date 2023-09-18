#include "philo.h"

void	philo_thinks(t_philo *philo)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->eating);
	time_to_think = philo->table->time_to_die - (get_time() - philo->last_meal) - philo->table->time_to_eat / 2;
	pthread_mutex_unlock(&philo->eating);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think > 600)
		time_to_think = 200;
	ft_usleep(philo->table, time_to_think);
}

void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
	print_action(philo, "has taken a fork", 1);
	pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
	print_action(philo, "has taken a fork", 1);
	print_action(philo, "is eating", 1);
	pthread_mutex_lock(&philo->eating);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->eating);
	ft_usleep(philo->table, philo->table->time_to_eat);
	if (!check_end(philo->table))
	{
		pthread_mutex_lock(&philo->eating);
		philo->nb_eat += 1;
		pthread_mutex_unlock(&philo->eating);
	}
	print_action(philo, "is sleeping", 1);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	ft_usleep(philo->table, philo->table->time_to_sleep);
	philo_thinks(philo);
}

void	*activities(void *data) 
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->total_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->eating);
	philo->last_meal = philo->table->start_t;
	pthread_mutex_unlock(&philo->eating);
	start_delay(philo->table->start_t);
	if (philo->table->time_to_die == 0)
		return (NULL);
	else if (philo->id % 2)
	{
		//think_routine(philo, true);
		usleep(200);
	}
	while (!check_end(philo->table))
	{
		philo_eats(philo);
		//think_routine(philo, false);
	}
	return (NULL);
}
