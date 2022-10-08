/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 05:46:58 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/25 05:46:59 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define NAME "philo"

# include <stdio.h> //printf
# include <sys/time.h>
# include "list.h"

int			chk_all(char **args);
int			tbl_free(t_table *table);
int			ft_error(const char *funct, const char *error,
				int (*close)(), void *zone);
void		ft_logs(t_philo *philo, int set);
t_table		*ft_init(t_table *table, char **args, int set);

int			ft_sleep(t_philo *philo, unsigned int time);
int			ft_chktbl(t_philo *philo, int set);
int			tm_to(t_philo *philo, unsigned int time_to);
int			tm_toeat(t_philo *philo);
int			tm_tosleep(t_philo *philo);
int			tm_tothink(t_philo *philo);
ssize_t		tm_gimme(struct timeval start);
int			philosophers(t_table *table);

#endif
