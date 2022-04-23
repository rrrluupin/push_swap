/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:15 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 00:57:05 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		ft_reader(&data, ac, av);
		ft_srt_arr(&data);
		ft_fill_list_a(&data);
	}
	return (0);
}
