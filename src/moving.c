/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:21 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:18:46 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rr_ra_move(t_stack *stack, t_data *data)
{
	while (stack->b_score)
	{
		if (stack->a_score < 1)
			stack->a_score = data->len_a - 1;
		ft_rotate_ab(&data->stack_a, &data->stack_b);
		stack->a_score -= 1;
		stack->b_score -= 1;
	}
	while (stack->a_score > 0)
	{
		ft_rotate_a(&data->stack_a);
		stack->a_score -= 1;
	}
	ft_pa(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}

void	ft_rr_rb_move(t_stack *stack, t_data *data)
{
	while (stack->a_score)
	{
		if (stack->b_score < 1)
			stack->b_score = data->len_b - 1;
		ft_rotate_ab(&data->stack_a, &data->stack_b);
		stack->a_score -= 1;
		stack->b_score -= 1;
	}
	while (stack->b_score > 0)
	{
		ft_rotate_b(&data->stack_b);
		stack->b_score -= 1;
	}
	ft_pa(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}

void	ft_rrr_rrb_move(t_stack *stack, t_data *data)
{
	while (stack->ra_score)
	{
		if (stack->rb_score == 0)
			stack->rb_score = data->len_b;
		ft_rev_rotate_ab(&data->stack_a, &data->stack_b);
		stack->ra_score -= 1;
		stack->rb_score -= 1;
	}
	while (stack->rb_score)
	{
		ft_rev_rotate_b(&data->stack_b);
		stack->rb_score -= 1;
	}
	ft_pa(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}

void	ft_rrr_rra_move(t_stack *stack, t_data *data)
{
	while (stack->rb_score)
	{
		if (stack->ra_score == 0)
			stack->ra_score = data->len_a;
		ft_rev_rotate_ab(&data->stack_a, &data->stack_b);
		stack->ra_score -= 1;
		stack->rb_score -= 1;
	}
	while (stack->ra_score)
	{
		ft_rev_rotate_a(&data->stack_a);
		stack->ra_score -= 1;
	}
	ft_pa(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}

void	ft_rra_rb_move(t_stack *stack, t_data *data)
{
	while (stack->ra_score)
	{
		ft_rev_rotate_a(&data->stack_a);
		stack->ra_score -= 1;
	}
	while (stack->b_score)
	{
		ft_rotate_b(&data->stack_b);
		stack->b_score -= 1;
	}
	ft_pa(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
}
