/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:49:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/24 21:49:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*ft_data(char **args, ssize_t must_eat)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->time_die = ft_atoui(args[0]);
	data->time_eat = ft_atoui(args[1]);
	data->time_sleep = ft_atoui(args[2]);
	data->must_eat = must_eat;
	if (pthread_mutex_init(&data->padlock, NULL))
		return (ft_free(data), NULL);
	return (data);
}

t_table	*ft_init(t_table *table, char **args, int set)
{
	t_philo			*philo;
	t_data			*data;
	unsigned int	i;

	if (set == 5)
		data = ft_data(args + 1, -1);
	else if (set == 6)
		data = ft_data(args + 1, ft_atoui(args[4]));
	if (!data)
		return (ft_error("ft_init", "malloc error", tbl_free, NULL), NULL);
	philo = lst_new(data);
	if (!philo)
		return (pthread_mutex_destroy(&data->padlock), ft_free(data), ft_error("ft_init", "malloc error", tbl_free, NULL), NULL);
	philo->id = 1;
	philo->next = philo;
	table = lst_init(philo);
	if (!table)
		return (pthread_mutex_destroy(&data->padlock), ft_free(data), lst_rmv(NULL, philo), ft_error("ft_init", "malloc error", tbl_free, NULL), NULL);
	data->table = table;
	i = ft_atoui(args[0]) + 1;
	while (--i > 1)
	{
		philo = lst_new(data);
		if (!philo)
			return (ft_error("ft_init", "malloc error", tbl_free, table), NULL);
		philo->id = i;
		lst_add(table, table->first, philo);
	}
	return (table);
}
