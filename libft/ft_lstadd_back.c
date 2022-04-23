/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:12:48 by rlupin            #+#    #+#             */
/*   Updated: 2021/11/24 17:48:27 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	if (lst)
	{
		if (*lst)
			*lst = new;
		if (!new)
			return ;
		last_elem = *lst;
		while (last_elem->next)
			last_elem = last_elem->next;
		last_elem->next = new;
	}
}
