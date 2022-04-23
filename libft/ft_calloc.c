/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:34:40 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/21 16:32:02 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	sizemem;
	void	*dst;

	sizemem = size * count;
	dst = malloc(sizemem);
	if (!dst)
	{
		exit(EXIT_FAILURE);
	}
	ft_memset(dst, 0, sizemem);
	return (dst);
}
