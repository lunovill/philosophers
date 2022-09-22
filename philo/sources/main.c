#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc == 1)
	{
		ft_error("main", "missing operand", tbl_free, NULL);
		ft_error("use", "./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]", tbl_free, NULL);
		return (EXIT_FAILURE);
	}
	else if (argc != 5 && argc != 6)
		return (ft_error("main", "invalid number of arguments", tbl_free, NULL), EXIT_FAILURE);
	if (chk_all(argv + 1) == -1)
		return (EXIT_FAILURE);
	table = ft_init(table, argv + 1, argc);
	if (!table)
		return (ft_error("main", "variable(s) are not initalized", tbl_free, NULL), EXIT_FAILURE);
	// lst_print(table);
	return (philosophers(table), EXIT_SUCCESS);
}
