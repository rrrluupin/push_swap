/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:43 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:06:24 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_a(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = NULL;
	ft_new_lstadd_back(stack_a, tmp);
	ft_new_putendl_fd("ra", 1);
}

void	ft_rotate_b(t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = NULL;
	ft_new_lstadd_back(stack_b, tmp);
	ft_new_putendl_fd("rb", 1);
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		tmp->next = NULL;
		ft_new_lstadd_back(stack_a, tmp);
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		tmp->next = NULL;
		ft_new_lstadd_back(stack_b, tmp);
	}
	ft_new_putendl_fd("rr", 1);
}
