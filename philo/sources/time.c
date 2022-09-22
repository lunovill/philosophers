#include "philo.h"

static int	tm_to(t_philo *philo, unsigned int time_to, struct timeval left_die)
{
	unsigned int	time_die;

	time_die = philo->time_die - tm_gimme(left_die);
	if (time_die <= time_to)
	{
		usleep(time_die * 1000);
		return (ft_logs(philo, 0), -1);
	}
	else
	{
		usleep(time_to * 1000);
		return (0);
	}
}


int	tm_toeat(t_philo *philo, struct timeval left_die)
{
	ft_logs(philo, 1);
	if (tm_to(philo, philo->time_eat, left_die) == -1)
		return (-1);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	philo->have_eat++;
	return (0);
}

int	tm_tosleep(t_philo *philo, struct timeval left_die)
{
	ft_logs(philo, 2);
	if (tm_to(philo, philo->time_sleep, left_die) == -1)
		return (-1);
	ft_logs(philo, 3);
	return (0);
}

ssize_t tm_gimme(struct timeval start)
{
	struct timeval	end;
	if (gettimeofday(&end, NULL) == -1)
		return (ft_error("tm_toeat", "gettimeofday error", tbl_free, NULL));
	return ((1e3 * ((&end)->tv_sec - (&start)->tv_sec))
	+ (1e-3 * ((&end)->tv_usec - (&start)->tv_usec)));
}
