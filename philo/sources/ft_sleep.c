/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:29:52 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/25 20:29:53 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo, unsigned int time)
{
	unsigned int	end;

	end = tm_gimme(philo->time_start) + time;
	while (!ft_chktbl(philo, -1) && tm_gimme(philo->time_start) < end)
		usleep(1000);
	return (0);
}
