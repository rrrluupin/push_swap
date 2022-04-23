/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverce_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:36 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:06:16 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rev_rotate_a(t_stack **stack_a)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp_1 = (*stack_a);
	tmp_2 = (*stack_a);
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	while (tmp_2->next != tmp_1)
		tmp_2 = tmp_2->next;
	tmp_2->next = NULL;
	tmp_1->next = (*stack_a);
	(*stack_a) = tmp_1;
	ft_new_putendl_fd("rra", 1);
}

void	ft_rev_rotate_b(t_stack **stack_b)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp_1 = (*stack_b);
	tmp_2 = (*stack_b);
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	while (tmp_2->next != tmp_1)
		tmp_2 = tmp_2->next;
	tmp_2->next = NULL;
	tmp_1->next = (*stack_b);
	(*stack_b) = tmp_1;
	ft_new_putendl_fd("rrb", 1);
}

void	ft_rr_ab_a(t_stack **stack_a)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp_1 = (*stack_a);
	tmp_2 = (*stack_a);
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	while (tmp_2->next != tmp_1)
		tmp_2 = tmp_2->next;
	tmp_2->next = NULL;
	tmp_1->next = (*stack_a);
	(*stack_a) = tmp_1;
}

void	ft_rr_ab_b(t_stack **stack_b)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp_1 = (*stack_b);
	tmp_2 = (*stack_b);
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	while (tmp_2->next != tmp_1)
		tmp_2 = tmp_2->next;
	tmp_2->next = NULL;
	tmp_1->next = (*stack_b);
	(*stack_b) = tmp_1;
}

void	ft_rev_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rr_ab_a(stack_a);
	ft_rr_ab_b(stack_b);
	ft_new_putendl_fd("rrr", 1);
}
