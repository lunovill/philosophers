/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:50:42 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/24 21:50:43 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free(void *zone)
{
	if (zone)
	{
		free(zone);
		zone = NULL;
	}
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	ft_atoui(const char *str)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += str[i++] - '0';
	}
	return (n);
}

size_t	ft_putstr_fd(const char *s, int fd)
{
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size])
		write(fd, &s[size++], 1);
	return (size);
}

ssize_t	ft_strichr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (i);
	return (-1);
}
