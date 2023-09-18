#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '+')
			i++;
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

void	start_delay(time_t start)
{
	while (get_time() < start)
		continue ;
}

void	ft_usleep(t_table *table, long int time)
{
	time_t	sleeps;

	sleeps = get_time() + time;
	while (get_time() < sleeps)
	{
		if (check_end(table))
			break ;
		usleep(100);
	}
}

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	check_int(long nbr)
{
	if (nbr > INT_MAX)
		return (0);
	return (1);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (check_int(atol(str)));
}

int	checker(int argc, char **argv)
{
	int	i;
	int	check;

	i = 1;
	while (i < argc)
	{
		check = check_num(argv[i]);
		if (check == 0)
		{
			printf("error\n");
			return (check);
		}
		i++;
	}
	return (check);
}
