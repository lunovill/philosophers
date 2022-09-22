#ifndef PHILO_H
# define PHILO_H
# define NAME "philo"

#include <stdio.h> //printf
#include <sys/time.h>
#include "list.h"

int			chk_all(char **args);
int			tbl_free(t_table *table);
int			ft_error(const char *funct, const char *error, int (*close)(), void *zone);
void		ft_logs(t_philo *philo, int set);
t_table		*ft_init(t_table *table, char **args, int set);

int			tm_toeat(t_philo *philo, struct timeval left_die);
int			tm_tosleep(t_philo *philo, struct timeval left_die);
ssize_t 	tm_gimme(struct timeval start);
int			philosophers(t_table *table);

#endif
