/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <chris_dupuis@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:31:32 by cdupuis           #+#    #+#             */
/*   Updated: 2023/09/18 09:50:59 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

# define INT_MAX 2147483647

typedef struct s_philo t_philo;

typedef struct s_table
{
	pthread_t			death_tid;
	int					nbr_philos;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int					died;
	int					total_eat;
	time_t				start_t;
	t_philo				**philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t 	print;
	pthread_mutex_t 	isdead;
	pthread_mutex_t 	end;
}				t_table;

typedef struct s_philo
{
	pthread_t				philo_tid;
	int						id;
	int						right_fork;
	int						left_fork;
	pthread_mutex_t			eating;
	int						nb_eat;
	long int				last_meal;
	t_table					*table;
}				t_philo;

void	print_action(t_philo *philo, char *str, int end);
t_table	*init_table(int argc, char **argv);
void	*activities(void *data);
int		check_death(t_philo *philo, int i);
time_t	get_time(void);
int		checker(int argc, char **argv);
void	free_table(t_table *table);
void	ft_usleep(t_table *table, long int time);
void	*death(void *data);
int		check_end(t_table *table);
void 	start_delay(time_t start);
int		ft_atoi(char *str);