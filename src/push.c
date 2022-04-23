/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:29 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:17:29 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int *len_a, int *len_b)
{
	t_stack	*tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	*len_a += 1;
	*len_b -= 1;
	ft_new_putendl_fd("pa", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, int *len_a, int *len_b)
{
	t_stack	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	*len_a -= 1;
	*len_b += 1;
	ft_new_putendl_fd("pb", 1);
}
