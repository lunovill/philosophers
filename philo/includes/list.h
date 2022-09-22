/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:25:23 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 01:31:32 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <pthread.h>
#include "utils.h"

typedef	struct s_table	t_table;
typedef	struct s_philo	t_philo;

struct	s_philo
{
	pthread_t		thread;
	unsigned int	id;
	struct timeval	time_start;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	have_eat;
	ssize_t			must_eat;
	pthread_mutex_t fork;
	t_philo			*next;
	t_table			*table;
};

struct	s_table
{
	t_philo			*first;
	pthread_mutex_t print;
	size_t			size;
};	

t_philo			*lst_new();
t_table			*lst_init(t_philo *init);
int				lst_add(t_table *list, t_philo *befor, t_philo *add);
int				lst_rmv(t_table *list, t_philo *remove);
// int				lst_print(t_table *list);

#endif
