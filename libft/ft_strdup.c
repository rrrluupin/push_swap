/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:37:59 by rlupin            #+#    #+#             */
/*   Updated: 2021/10/27 18:16:11 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s2;
	size_t	len;

	len = 0;
	while (src[len] != 0)
		len++;
	s2 = (char *)malloc(len + 1);
	if (s2 == 0)
		return (0);
	len = 0;
	while (src[len] != 0)
	{
		s2[len] = src[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}
