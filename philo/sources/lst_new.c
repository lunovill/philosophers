/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:34:24 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 01:34:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_philo	*lst_new(char **args, int set)
{
	t_philo	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->time_die = ft_atoui(args[0]);
	new->time_eat = ft_atoui(args[1]);
	new->time_sleep = ft_atoui(args[2]);
	new->have_eat = 0;
	new->must_eat = set;
	if (pthread_mutex_init(&new->fork, NULL))
		return (ft_free(new), NULL);
	new->next = NULL;
	return (new);
}
