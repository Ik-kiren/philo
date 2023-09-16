/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:31:32 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/16 16:38:07 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

# define INT_MAX 2147483647

typedef struct s_philo
{
	pthread_t				philo_tid;
	pthread_t				death_tid;
	int						id;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	int						nb_eat;
	long int				last_meal;
	struct s_table			*table;
}				t_philo;

typedef struct s_table
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				died;
	int				nb_eat;
	int				total_eat;
	long int		start_t;
	t_philo			*philos;
	pthread_mutex_t eating;
	pthread_mutex_t print;
	pthread_mutex_t isdead;
	pthread_mutex_t end;
}				t_table;

void	print_action(t_philo *philo, char *str);
int init_table(t_table *table, int argc, char **argv);
void	*activities(void *data);
int		check_death(t_philo *philo, int i);
long int	get_time(void);
int		checker(int argc, char **argv);
void	free_table(t_table *table);
void	ft_usleep(long int time_in_ms);