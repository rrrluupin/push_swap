/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:37:48 by rlupin            #+#    #+#             */
/*   Updated: 2021/10/27 17:45:06 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	takeabs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		sign;
	int		len;

	sign = (n < 0);
	ft_bzero(str, 12);
	if (n == 0)
		str[0] = '0';
	len = 0;
	while (n != 0)
	{
		str[len++] = '0' + takeabs(n % 10);
		n /= 10;
	}
	if (sign)
		str[len] = '-';
	else if (len > 0)
		len--;
	while (len >= 0)
		write (fd, &str[len--], 1);
}
