#include    "philo.h"

int tbl_free(t_table *table)
{
    if (table)
    {
        while (table->size)
            lst_rmv(table, table->first);
        ft_free(table);
    }
    table = NULL;
    return (0);
}
