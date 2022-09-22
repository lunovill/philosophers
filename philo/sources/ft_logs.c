#include "philo.h"

void	ft_logs(t_philo *philo, int set)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%li %u ", tm_gimme(philo->time_start), philo->id);
	if (set == 0)
		printf("died\n");
	else if (set == 1)
		printf("is eating\n");
	else if (set == 2)
		printf("is sleeping\n");
	else if (set == 3)
		printf("is thinking\n");
	else if (set == 4)
		printf("has take a fork\n");
	pthread_mutex_unlock(&philo->table->print);
}
