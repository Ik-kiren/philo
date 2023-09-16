#include "philo.h"

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

long int	get_time(void)
{
	struct timeval	tv;
	long int		time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
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
