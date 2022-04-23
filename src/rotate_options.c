/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:39 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:06:20 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rr_ra_opt(t_stack *tmp, int len_a)
{
	int	final_cost;
	int	a_score;
	int	b_score;

	final_cost = 0;
	a_score = tmp->a_score;
	b_score = tmp->b_score;
	while (b_score)
	{
		final_cost += 1;
		if (a_score < 1)
			a_score = len_a - 1;
		a_score -= 1;
		b_score -= 1;
	}
	if (a_score > 0)
		final_cost += a_score;
	return (final_cost);
}

int	ft_rr_rb_opt(t_stack *tmp, int len_b)
{
	int	final_cost;
	int	a_score;
	int	b_score;

	final_cost = 0;
	a_score = tmp->a_score;
	b_score = tmp->b_score;
	while (a_score)
	{
		final_cost += 1;
		if (b_score < 1)
			b_score = len_b - 1;
		a_score -= 1;
		b_score -= 1;
	}
	if (b_score > 0)
		final_cost += b_score;
	return (final_cost);
}

int	ft_rrr_rrb_opt(t_stack *tmp, int len_b)
{
	int	final_cost;
	int	ra_score;
	int	rb_score;

	final_cost = 0;
	ra_score = tmp->ra_score;
	rb_score = tmp->rb_score;
	while (ra_score)
	{
		final_cost += 1;
		if (rb_score == 0)
			rb_score = len_b;
		ra_score -= 1;
		rb_score -= 1;
	}
	final_cost += rb_score;
	return (final_cost);
}

int	ft_rrr_rra_opt(t_stack *tmp, int len_a)
{
	int	final_cost;
	int	ra_score;
	int	rb_score;

	final_cost = 0;
	ra_score = tmp->ra_score;
	rb_score = tmp->rb_score;
	while (rb_score)
	{
		final_cost += 1;
		if (ra_score == 0)
			ra_score = len_a;
		ra_score -= 1;
		rb_score -= 1;
	}
	final_cost += ra_score;
	return (final_cost);
}

int	ft_rra_rb_opt(t_stack *tmp)
{
	int	final_cost;

	final_cost = tmp->ra_score + tmp->b_score;
	return (final_cost);
}
