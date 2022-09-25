/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tbl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:51:01 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/24 21:51:02 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philo.h"

int	tbl_free(t_table *table)
{
	if (table)
	{
		ft_free(table->first->data);
		while (table->size)
			lst_rmv(table, table->first);
		ft_free(table);
	}
	table = NULL;
	return (0);
}
