/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:50:29 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/24 21:50:30 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	tm_to(t_philo *philo, unsigned int time_to)
{
	unsigned int	time;

	time = philo->data->time_die - tm_gimme(philo->left_die);
	if (time <= time_to)
	{
		usleep(time * 1000);
		return (-1);
	}
	else
	{
		usleep(time_to * 1000);
		return (0);
	}
}

int	tm_toeat(t_philo *philo)
{
	int	ret;

	if (ft_chktbl(philo, 1) == -1)
		ret = -1;
	else if (gettimeofday(&philo->left_die, NULL) == -1)
		ret = ft_error("routine", "gettimeofday error", tbl_free, NULL);
	else if (tm_to(philo, philo->data->time_eat) == -1)
		ret = ft_chktbl(philo, 0);
	else
		ret = 0;
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	return (ret);
}

int	tm_tosleep(t_philo *philo)
{
	if (ft_chktbl(philo, 2) == -1)
		return (-1);
	if (tm_to(philo, philo->data->time_sleep) == -1)
		return (ft_chktbl(philo, 0));
	if (ft_chktbl(philo, 3) == -1)
		return (-1);
	return (0);
}

ssize_t	tm_gimme(struct timeval start)
{
	struct timeval	end;

	if (gettimeofday(&end, NULL) == -1)
		return (ft_error("tm_toeat", "gettimeofday error", tbl_free, NULL));
	return ((1e3 * ((&end)->tv_sec - (&start)->tv_sec))
		+ (1e-3 * ((&end)->tv_usec - (&start)->tv_usec)));
}
