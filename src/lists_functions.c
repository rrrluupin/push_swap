/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:53:33 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 00:55:44 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_new_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new -> next = (*lst);
	(*lst) = new;
}

void	ft_new_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lst_copy;

	lst_copy = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (lst_copy -> next)
			lst_copy = lst_copy -> next;
		lst_copy -> next = new;
	}
}

t_stack	*ft_new_lstnew(t_data *data, int i)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		ft_stop4(data);
	node->num = data->num_arr[i];
	node->a_score = 0;
	node->b_score = 0;
	node->ra_score = 0;
	node->rb_score = 0;
	node->cheapest_score = 0;
	node -> next = NULL;
	return (node);
}
