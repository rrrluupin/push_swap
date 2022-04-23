/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:50 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:08:07 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sorted_inner(t_stack *stack, t_stack *tmp)
{
	t_stack	*tmp_next;
	int		num;

	num = tmp->num;
	if (!tmp->next)
		tmp_next = stack;
	else
		tmp_next = tmp->next;
	while (tmp_next->num != num)
	{
		if (tmp_next->num < tmp->num)
			return (0);
		tmp = tmp->next;
		if (!tmp)
			tmp = stack;
		tmp_next = tmp_next->next;
		if (!tmp_next)
			tmp_next = stack;
	}
	return (1);
}

int	ft_if_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (ft_sorted_inner(stack, tmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_rotate_dir(t_data *data)
{
	t_stack	*tmp;
	int		pre_num;
	int		i;

	tmp = data->stack_a;
	pre_num = MIN_INT;
	i = 0;
	while (tmp && pre_num < tmp->num)
	{
		i += 1;
		pre_num = tmp->num;
		tmp = tmp->next;
	}
	if (i > data->len_a / 2)
		return (BACKWARD);
	else
		return (FORWARD);
}

void	ft_final_sorting(t_data *data)
{
	if (ft_rotate_dir(data) == FORWARD)
	{
		while (data->stack_a->num != data->min)
			ft_rotate_a(&data->stack_a);
	}
	else
	{
		while (data->stack_a->num != data->min)
			ft_rev_rotate_a(&data->stack_a);
	}
}

void	ft_triple_sorting(t_data *data)
{
	ft_swap_a(&data->stack_a);
}
