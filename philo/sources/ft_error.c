/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:47:57 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:47:58 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(const char *funct, const char *error, int (*close)(), void *zone)
{
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(":\t", 2);
	ft_putstr_fd(funct, 2);
	ft_putstr_fd(":\t", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	if (zone)
		close(zone);
	return (-1);
}
