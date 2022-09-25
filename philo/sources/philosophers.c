/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:49:17 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/24 21:49:18 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	tk_afork(t_philo *philo,
pthread_mutex_t *right, pthread_mutex_t *left)
{
	if (philo->id % 2)
		pthread_mutex_lock(right);
	else
		pthread_mutex_lock(left);
	if (ft_chktbl(philo, 4) == -1)
	{
		if (philo->id % 2)
			pthread_mutex_unlock(right);
		else
			pthread_mutex_unlock(left);
		return (-1);
	}
	if (philo->id % 2)
		pthread_mutex_lock(left);
	else
		pthread_mutex_lock(right);
	if (ft_chktbl(philo, 4) == -1)
	{
		pthread_mutex_unlock(right);
		pthread_mutex_unlock(left);
		return (-1);
	}
	return (0);
}

static void	*routine(void *zone)
{
	t_philo			*philo;

	philo = (t_philo *)zone;
	if (gettimeofday(&philo->time_start, NULL) == -1
		|| gettimeofday(&philo->left_die, NULL) == -1)
		return (ft_error("routine", "gettimeofday error",
				tbl_free, NULL), NULL);
	if (philo->data->must_eat == 0)
		return (NULL);
	if (philo->id % 2 == 0)
	{
		if (ft_chktbl(philo, 3) == -1)
			return (NULL);
		usleep(philo->data->time_eat * 1000);
	}
	while (1)
	{
		if (tk_afork(philo, &philo->next->fork, &philo->fork) == -1)
			break ;
		if (tm_toeat(philo) == -1)
			break ;
		if (tm_tosleep(philo) == -1)
			break ;
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
			return (ft_error("philosophers", "pthread_create error",
					tbl_free, table));
		philo = philo->next;
	}
	philo = table->first;
	i = 0;
	while (i++ < table->size)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
	}
	return (tbl_free(table), 0);
}
