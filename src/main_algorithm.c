/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:07 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:11:31 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_if_five(t_data *data)
{
	while (data->len_a > 3)
	{
		if (data->stack_a->num == data->min || data->stack_a->num < data->med)
			ft_pb(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
		else
			ft_rotate_a(&data->stack_a);
	}
	if (!ft_if_sorted(data->stack_a) && data->stack_b->num == data->min)
		ft_swap_ab(&data->stack_a, &data->stack_b);
	if (!ft_if_sorted(data->stack_a))
		ft_triple_sorting(data);
	if (data->stack_b->num == data->min)
		ft_swap_b(&data->stack_b);
	while (data->stack_a->num != data->med)
		ft_rotate_a(&data->stack_a);
	ft_pa(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
	ft_pa(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
	ft_stop5(data);
}

void	ft_distribut(t_stack *stack, t_data *data)
{
	if (stack->rotate_variants == RR_RA)
		ft_rr_ra_move(stack, data);
	else if (stack->rotate_variants == RR_RB)
		ft_rr_rb_move(stack, data);
	else if (stack->rotate_variants == RRR_RRA)
		ft_rrr_rra_move(stack, data);
	else if (stack->rotate_variants == RRR_RRB)
		ft_rrr_rrb_move(stack, data);
	else if (stack->rotate_variants == RRA_RB)
		ft_rra_rb_move(stack, data);
	else if (stack->rotate_variants == RRB_RA)
		ft_rrb_ra_move(stack, data);
}

void	ft_main_algorithm(t_data *data)
{
	t_stack	*move;

	ft_fill_list_b(data);
	if (!ft_if_sorted(data->stack_a))
		ft_triple_sorting(data);
	while (data->len_b)
	{
		ft_scoring(data);
		move = ft_elem_to_push(data->stack_b);
		ft_distribut(move, data);
	}
	ft_final_sorting(data);
	ft_stop5(data);
}

void	ft_fill_list_b(t_data *data)
{
	while (data->len_a > 3 && !ft_if_sorted(data->stack_a))
	{
		if (data->stack_a->num == data->max || data->stack_a->num == data->min
			|| data->stack_a->num == data->med)
			ft_rotate_a(&data->stack_a);
		else
			ft_pb(&data->stack_a, &data->stack_b, &data->len_a, &data->len_b);
	}
}

void	ft_fill_list_a(t_data *data)
{
	int	i;

	data->stack_a = NULL;
	data->stack_b = NULL;
	i = -1;
	while (++i < data->len)
		ft_new_lstadd_back(&data->stack_a, ft_new_lstnew(data, i));
	free(data->num_arr);
	data->num_arr = NULL;
	data->len_a = data->len;
	data->len_b = 0;
	if (data->len == 1 || data->len == 0)
		ft_stop5(data);
	else if (data->len_a == 5)
		ft_sort_if_five(data);
	else
		ft_main_algorithm(data);
}
