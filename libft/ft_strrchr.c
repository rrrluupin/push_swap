/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:38:28 by rlupin            #+#    #+#             */
/*   Updated: 2021/11/15 15:53:23 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	pos;

	i = 0;
	pos = -1;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			pos = i;
		i++;
	}
	if (str[i] == (unsigned char)c && (unsigned char)c == '\0')
		return ((char *)str + i);
	if (pos == -1)
		return (NULL);
	return ((char *)str + pos);
}
