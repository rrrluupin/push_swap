/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:26 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:05:52 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_int_check(t_data *data, long number, int last, char **arr)
{
	int	i;

	if ((number > MAX_INT || number < MIN_INT))
		ft_stop2(arr, data, ARG_ERR);
	i = -1;
	while (++i < last)
	{
		if (number == data->num_arr[i])
			ft_stop2(arr, data, ARG_ERR);
	}
}

void	ft_to_int(t_data *data, char **arr)
{
	int	i;

	data->num_arr = (int *)malloc(data->len * sizeof(int));
	if (!data->num_arr)
		ft_stop1(arr, MALL_ERR);
	i = -1;
	while (arr[++i])
	{
		ft_int_check(data, ft_new_atoi(arr[i]), i, arr);
		data->num_arr[i] = ft_new_atoi(arr[i]);
	}
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	ft_char_check(char **arr)
{
	int	i;
	int	j;
	int	sign;

	sign = 0;
	i = -1;
	while (arr[++i])
	{
		if ((arr[i][0] == '-' && arr[i][1] == '-')
			|| (arr[i][0] == '0' && arr[i][1] != '\0'))
			ft_stop1(arr, ARG_ERR);
		if ((arr[i][0] == '-' || arr[i][0] == '+') && (arr[i][1] == '\0'))
			ft_stop1(arr, ARG_ERR);
		j = -1;
		while (arr[i][++j])
		{
			if (arr[i][j] == '-')
				sign++;
			if ((arr[i][j] < '0' || arr[i][j] > '9') && arr[i][j] != '-')
				ft_stop1(arr, ARG_ERR);
		}
		if (sign > 1)
			ft_stop1(arr, ARG_ERR);
		sign = 0;
	}
}

char	**ft_divided_args(int ac, char **av)
{
	int		i;
	char	**arr;

	arr = (char **)calloc(ac, sizeof(char *));
	if (!arr && ft_new_putendl_fd("malloc_err", 2))
		exit(1);
	i = 0;
	while (av[++i])
	{
		arr[i - 1] = (char *)calloc(ft_strlen(av[i]) + 1, sizeof(char));
		if (!arr[i - 1])
			ft_stop1(arr, MALL_ERR);
		ft_memmove(arr[i - 1], av[i], ft_strlen(av[i]));
	}
	return (arr);
}

void	ft_reader(t_data *data, int ac, char **av)
{
	char	**arr;

	if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		if (!arr && ft_new_putendl_fd("malloc_err", 2))
			exit(1);
		data->len = arr_len(arr);
	}
	else
	{
		data->len = ac - 1;
		arr = ft_divided_args(ac, av);
	}
	ft_char_check(arr);
	ft_to_int(data, arr);
}
