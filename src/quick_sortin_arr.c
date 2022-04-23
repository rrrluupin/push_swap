/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sortin_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:54:32 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:06:03 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_srt_arr(t_data *data)
{
	int	i;

	data->srt_num_arr = (int *)malloc(data->len * sizeof(int));
	if (!data->srt_num_arr)
		ft_stop3(data);
	i = -1;
	while (++i < data->len)
		data->srt_num_arr[i] = data->num_arr[i];
	ft_quick_sort_recursive(data->srt_num_arr, data->len);
	data->min = data->srt_num_arr[0];
	data->max = data->srt_num_arr[data->len - 1];
	data->med = data->srt_num_arr[data->len / 2];
	free(data->srt_num_arr);
}

void	ft_quick_sort_recursive(int *mas, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	mid;

	i = 0;
	j = size - 1;
	mid = mas[size / 2];
	while (i <= j)
	{
		while (mas[i] < mid)
			i++;
		while (mas[j] > mid)
			j--;
		if (i <= j)
		{
			tmp = mas[i];
			mas[i++] = mas[j];
			mas[j--] = tmp;
		}
	}
	if (j > 0)
		ft_quick_sort_recursive(mas, j + 1);
	if (i < size)
		ft_quick_sort_recursive(&mas[i], size - i);
}
