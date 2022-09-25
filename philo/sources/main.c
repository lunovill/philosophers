/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:49:06 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/24 21:49:07 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc == 1)
	{
		ft_error("main", "missing operand", tbl_free, NULL);
		ft_putstr_fd("philo:\tuse:\t./philo number_of_philosophers", 2);
		ft_putstr_fd(" time_to_die time_to_eat time_to_sleep", 2);
		ft_putstr_fd(" [number_of_times_each_philosopher_must_eat]\n", 2);
		return (EXIT_FAILURE);
	}
	else if (argc != 5 && argc != 6)
		return (ft_error("main", "invalid number of arguments",
				tbl_free, NULL), EXIT_FAILURE);
	if (chk_all(argv + 1) == -1)
		return (EXIT_FAILURE);
	table = ft_init(table, argv + 1, argc);
	if (!table)
		return (ft_error("main", "variable(s) are not initalized",
				tbl_free, NULL), EXIT_FAILURE);
	return (philosophers(table), EXIT_SUCCESS);
}
