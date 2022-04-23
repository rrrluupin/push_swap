/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:55:19 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:09:19 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_new_putendl_fd(char *s, int fd)
{
	if (!s)
		return (0);
	while (*s)
	{
		write(fd, s, 1);
		s += 1;
	}
	write(fd, "\n", 1);
	return (1);
}

long	ft_new_atoi(const char *str)
{
	long	res;
	int		negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len += 1;
	return (len);
}
