/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rmv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:36:51 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 01:37:18 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	lst_rmv(t_table *list, t_philo *remove)
{
	t_philo	*previous;

	if (remove == NULL)
		return (-1);
	if (list)
	{
		if (remove == list->first)
			list->first = list->first->next;
		else
		{
			previous = list->first;
			while ((previous->next != remove) && (previous != NULL))
				previous = previous->next;
			if (previous == NULL)
				return (-1);
			previous->next = remove->next;
		}
		list->size--;
	}
	pthread_mutex_destroy(&remove->fork);
	free(remove);
	return (0);
}
