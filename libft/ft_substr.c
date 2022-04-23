/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:38:36 by rlupin            #+#    #+#             */
/*   Updated: 2021/11/15 17:03:43 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	int		i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len - start >= len)
		new_str = (char *) malloc(len + 1);
	else
		new_str = (char *) malloc(s_len - start + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (start < s_len && len > 0 && s[start + i] != '\0')
	{
		new_str[i] = s[start + i];
		i++;
		len--;
	}
	new_str[i] = '\0';
	return (new_str);
}
