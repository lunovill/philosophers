#include "philo.h"

static int	chk_args(char **args)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-')
			return (ft_error("chk_args", "negative number(s)", tbl_free, NULL));
		while (args[i][j])
			if (ft_strichr("0123456789", args[i][j++]) == -1)
				return (ft_error("chk_args", "invalid charactere(s)", tbl_free, NULL));
		i++;
	}
	return (0);
}

static int	chk_overflow(char **args)
{
	unsigned int	i;
	size_t			len;

	i = -1;
	while (args[++i])
	{
		len = ft_strlen(args[i]);
		if (len > 10)
			return (ft_error("chk_overflow", "number(s) is too big. Max is 4294967294", tbl_free, NULL));
		if ((len == 10 && args[i][0] > '4') || (len == 10 &&
			(args[i][0] == '4' && ft_atoui(args[i] + 1) > 294967295)))
			return (ft_error("chk_overflow", "number(s) is too big. Max is 4294967294", tbl_free, NULL));
	}
	return (0);
}

int	chk_all(char **args)
{
	int error;

	error = 0;
	if (chk_args(args) == -1)
		error++;
	if (chk_overflow(args) == -1)
		error++;
	if (error)
		return (ft_error("chk_all", "invalid argument(s)", tbl_free, NULL));
	else if (ft_atoui(args[0]) == 0)
		return (ft_error("chk_all", "numbre of philosophers is null", tbl_free, NULL),
			ft_error("chk_all", "invalid argument(s)", tbl_free, NULL));
	return (0);
}
