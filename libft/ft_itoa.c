/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:35:04 by rlupin            #+#    #+#             */
/*   Updated: 2021/11/13 20:42:08 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	makediv(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

static int	len_of_nbr(int nbr)
{
	int	dig;

	dig = 1;
	if (nbr < 0)
	{
		dig++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		dig++;
	}
	return (dig);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	int		len;
	int		permanent_len;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len = len_of_nbr(nbr);
	permanent_len = len;
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
		i++;
		len--;
	}
	while (i < permanent_len)
		str[i++] = (nbr / makediv(len--) % 10) + 48;
	str[i] = '\0';
	return (str);
}
