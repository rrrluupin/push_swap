/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:56 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:08:42 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stop1(char **arr, int flag)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	if (flag == MALL_ERR)
		ft_new_putendl_fd("malloc_err", 2);
	else if (flag == ARG_ERR)
		ft_new_putendl_fd("Error", 2);
	exit (1);
}

void	ft_stop2(char **arr, t_data *data, int flag)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
	free(data->num_arr);
	data->num_arr = NULL;
	if (flag == MALL_ERR)
		ft_new_putendl_fd("malloc_err", 2);
	else if (flag == ARG_ERR)
		ft_new_putendl_fd("Error", 2);
	exit (1);
}

void	ft_stop3(t_data *data)
{
	free(data->num_arr);
	data->num_arr = NULL;
	ft_new_putendl_fd("malloc_err", 2);
	exit (1);
}

void	ft_stop4(t_data *data)
{
	t_stack	*tmp;

	free(data->num_arr);
	data->num_arr = NULL;
	while (data->stack_a)
	{
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		free(tmp);
		tmp = NULL;
	}
	data->stack_a = NULL;
	ft_new_putendl_fd("malloc_err", 2);
	exit(1);
}

void	ft_stop5(t_data *data)
{
	t_stack	*tmp;

	while (data->stack_a)
	{
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		free(tmp);
		tmp = NULL;
	}
	data->stack_a = NULL;
	while (data->stack_b)
	{
		tmp = data->stack_b;
		data->stack_b = data->stack_b->next;
		free(tmp);
		tmp = NULL;
	}
	data->stack_b = NULL;
	exit(0);
}
