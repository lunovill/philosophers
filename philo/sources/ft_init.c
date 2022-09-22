#include "philo.h"

t_table	*ft_init(t_table *table, char **args, int set)
{
	t_philo			*philo;
	unsigned int	i;

	if (set == 5)
		set = -1;
	else if (set == 6)
		set = ft_atoui(args[4]);
	philo = lst_new(args + 1, set);
	if (!philo)
		return (ft_error("ft_init", "malloc error", tbl_free, NULL), NULL);
	philo->id = 1;
	philo->next = philo;
	table = lst_init(philo);
	if (!table)
		return (lst_rmv(NULL, philo), ft_error("ft_init", "malloc error", tbl_free, NULL), NULL);
	philo->table = table;
	i = ft_atoui(args[0]) + 1;
	while (--i > 1)
	{
		philo = lst_new(args + 1, set);
		if (!philo)
			return (ft_error("ft_init", "malloc error", tbl_free, table), NULL);
		philo->id = i;
		philo->table = table;
		lst_add(table, table->first, philo);
	}
	return (table);
}