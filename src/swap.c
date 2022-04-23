/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:55:16 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:09:06 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_a(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	ft_new_putendl_fd("sa", 1);
}

void	ft_swap_b(t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	ft_new_putendl_fd("sb", 1);
}

void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		tmp->next = (*stack_a);
		(*stack_a) = tmp;
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		tmp->next = (*stack_b);
		(*stack_b) = tmp;
	}
	ft_new_putendl_fd("ss", 1);
}
