/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:18 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:17:54 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rrb_ra_opt(t_stack *tmp)
{
	int	final_cost;

	final_cost = tmp->rb_score + tmp->a_score;
	return (final_cost);
}

void	ft_rrb_ra_move(t_stack *stack, t_data *data)
{
	while (stack->rb_score)
	{
		ft_rev_rotate_b(&data->stack_b);
		stack->rb_score -= 1;
	}
	while (stack->a_score)
	{
		ft_rotate_a(&data->stack_a);
		stack->a_score -= 1;
	}
	ft_pa(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}
