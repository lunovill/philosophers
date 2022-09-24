/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chktbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:48:40 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/24 21:48:42 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_chktbl(t_philo *philo, int set)
{
	int				ret;

	pthread_mutex_lock(&philo->data->padlock);
	if (philo->data->table->dead)
		ret = -1;
	else if (philo->data->time_die <= tm_gimme(philo->left_die))
	{
		ft_logs(philo, 0);
		ret = -1;
	}
	else if (philo->data->table->have_eat == philo->data->table->size)
		ret = -1;
	else
	{
		ft_logs(philo, set);
		if (set == 1 && philo->have_eat == philo->data->must_eat)
			philo->data->table->have_eat++;
		// else if (set == 4)
		// 	ft_logs(philo, set);
		ret = 0;
	}
	pthread_mutex_unlock(&philo->data->padlock);
	return (ret);
}
