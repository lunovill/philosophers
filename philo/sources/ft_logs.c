/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:50:14 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/24 21:50:15 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_logs(t_philo *philo, int set)
{
	printf("%li %u ", tm_gimme(philo->time_start), philo->id);
	if (set == 0)
	{
		printf("died\n");
		philo->data->table->dead++;
	}
	else if (set == 1)
	{
		printf("is eating\n");
		philo->have_eat++;
	}
	else if (set == 2)
		printf("is sleeping\n");
	else if (set == 3)
		printf("is thinking\n");
	else if (set == 4)
		printf("has take a fork\n");
}
