/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:47 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:08:00 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_elem_to_push(t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp_ret;
	int		num;

	tmp = stack_b;
	tmp_ret = stack_b;
	num = tmp->cheapest_score;
	while (tmp)
	{
		if (tmp->cheapest_score < num)
		{
			num = tmp->cheapest_score;
			tmp_ret = tmp;
		}
		tmp = tmp->next;
	}
	return (tmp_ret);
}

void	sawe_options(t_stack *stack, int cheapest, int option)
{
	stack->cheapest_score = cheapest;
	stack->rotate_variants = option;
}

void	ft_find_option(t_stack *tmp, int len_a, int len_b)
{
	int	tmp_cost;

	tmp->cheapest_score = ft_rr_ra_opt(tmp, len_a);
	tmp->rotate_variants = RR_RA;
	tmp_cost = ft_rr_rb_opt(tmp, len_b);
	if (tmp_cost < tmp->cheapest_score)
		sawe_options(tmp, tmp_cost, RR_RB);
	tmp_cost = ft_rrr_rrb_opt(tmp, len_b);
	if (tmp_cost < tmp->cheapest_score)
		sawe_options(tmp, tmp_cost, RRR_RRB);
	tmp_cost = ft_rrr_rra_opt(tmp, len_a);
	if (tmp_cost < tmp->cheapest_score)
		sawe_options(tmp, tmp_cost, RRR_RRA);
	tmp_cost = ft_rra_rb_opt(tmp);
	if (tmp_cost < tmp->cheapest_score)
		sawe_options(tmp, tmp_cost, RRA_RB);
	tmp_cost = ft_rrb_ra_opt(tmp);
	if (tmp_cost < tmp->cheapest_score)
		sawe_options(tmp, tmp_cost, RRB_RA);
}

int	ft_scoring_a(t_stack *stack_a, int num)
{
	t_stack	*tmp;
	t_stack	*tmp_next;
	int		a_score;

	tmp = stack_a;
	tmp_next = tmp->next;
	a_score = 1;
	while (tmp_next)
	{
		if (tmp->num < num && tmp->next->num > num)
			return (a_score);
		tmp = tmp->next;
		tmp_next = tmp_next->next;
		a_score += 1;
	}
	return (0);
}

void	ft_scoring(t_data *data)
{
	t_stack	*tmp;
	int		score_b;

	score_b = 0;
	tmp = data->stack_b;
	while (tmp)
	{
		tmp->b_score = score_b;
		tmp->rb_score = (data->len_b - score_b) * (score_b > 0);
		tmp->a_score = ft_scoring_a(data->stack_a, tmp->num);
		tmp->ra_score = data->len_a - tmp->a_score * (tmp->a_score > 0);
		ft_find_option(tmp, data->len_a, data->len_b);
		score_b += 1;
		tmp = tmp->next;
	}
}
