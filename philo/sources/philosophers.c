#include "philo.h"

// static void	*routine(void *zone)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)zone;
// 	while (philo->must_eat != -1 && philo->have_eat != philo->must_eat)
// 	{
// 		usleep(philo->time_eat * 1000);
// 		pthread_mutex_lock(&philo->table->print);
// 		printf("%u : J'ai fini de manger !\n", philo->id);
// 		pthread_mutex_unlock(&philo->table->print);
// 		philo->have_eat++;
// 		usleep(philo->time_sleep * 1000);
// 		pthread_mutex_lock(&philo->table->print);
// 		printf("%u : J'ai bien dormi !\n", philo->id);
// 		pthread_mutex_unlock(&philo->table->print);
// 	}
// 	return (zone);
// }

static void	tk_afork(t_philo *philo, pthread_mutex_t *right, pthread_mutex_t *left)
{
	if (philo->id % 2)
		pthread_mutex_lock(right);
	else
		pthread_mutex_lock(left);
	ft_logs(philo, 4);
	if (philo->id % 2)
		pthread_mutex_lock(left);
	else
		pthread_mutex_lock(right);
	ft_logs(philo, 4);
}

static void	*routine(void *zone)
{
	t_philo	*philo;
	struct timeval	left_die;

	philo = (t_philo *)zone;
	if (gettimeofday(&philo->time_start, NULL) == -1)
		return (ft_error("routine", "gettimeofday error", tbl_free, NULL), NULL);
	if (philo->id % 2 == 0)
		usleep(900);
	while (1)
	{
		if (philo->must_eat == 0)
			break;
		tk_afork(philo, &philo->next->fork, &philo->fork);
		if (gettimeofday(&left_die, NULL) == -1)
			return (ft_error("routine", "gettimeofday error", tbl_free, NULL), NULL);
		if (tm_toeat(philo, left_die) == -1)
			break;
		if (philo->have_eat == philo->must_eat)
			break;
		if (tm_tosleep(philo, left_die) == -1)
			break;
	}
	return (NULL);
}

int	philosophers(t_table *table)
{
	t_philo			*philo;
	unsigned int	i;

	philo = table->first;
	i = 0;
	while (i++ < table->size)
	{
		if (pthread_create(&philo->thread, NULL, &routine, (void *)philo))
			return (ft_error("philosophers", "pthread_create error", tbl_free, table));
		philo = philo->next;
	}
	philo = table->first;
	i = 0;
	while(i++ < table->size)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
	return (tbl_free(table), 0);
}