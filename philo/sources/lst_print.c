/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:35:13 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 04:37:19 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

int	lst_print(t_table *list)
{
	unsigned int	i;
	t_philo			*current;

	if (list == NULL)
		return (-1);
	current = list->first;
	i = list->size;
	while ((current != NULL) && i--)
	{
		printf("philo n°%lu\n", list->size - i);
		printf("id\t\t| %u\n", current->id);
		printf("tm_to_die\t| %u\n", current->time_die);
		printf("tm_to_eat\t| %u\n", current->time_eat);
		printf("tm_to_sleep\t| %u\n", current->time_sleep);
		printf("have_eat\t| %u\n", current->have_eat);
		printf("must_eat\t| %li\n\n", current->must_eat);
		current = current->next;
	}
	printf("(null)\n");
	printf("\nphilo\t\t| %lu\n", list->size);
	return (0);
}
