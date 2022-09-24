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

t_philo	*lst_new(t_data *data)
{
	t_philo	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->have_eat = 0;
	if (pthread_mutex_init(&new->fork, NULL))
		return (ft_free(new), NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
