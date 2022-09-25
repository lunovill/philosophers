/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 05:46:30 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/25 05:46:32 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

void			ft_free(void *zone);

size_t			ft_strlen(const char *s);

unsigned int	ft_atoui(const char *str);

size_t			ft_putstr_fd(const char *s, int fd);

ssize_t			ft_strichr(const char *s, int c);

#endif
