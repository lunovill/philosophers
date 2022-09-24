/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:33:38 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 01:33:58 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_table	*lst_init(t_philo *init)
{
	t_table	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->first = init;
	list->size = 1;
	list->dead = 0;
	list->have_eat = 0;
	return (list);
}
