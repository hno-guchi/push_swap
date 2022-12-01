/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sort_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/01 15:16:15 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_array(int array_size, int *array)
{
	int	i;

	i = 0;
	while (i < array_size)
	{
		array[i] = 0;
		i += 1;
	}
}

void	initialize_sort_info(t_sort_info *info, int stack_size)
{
	info->size = stack_size;
	info->sorted = 0;
	initialize_array(100, info->limits);
	info->limits_idx = 0;
	info->limit = 0;
	info->section_size = 0;
	// info->b_pivot = 0;
	info->a_pivot = calculate_median(info->size);
	// info->median = calculate_median(info->size);
	info->b_pivot = calculate_median(info->sorted + info->a_pivot);
	info->stack_b_size = 0;
	info->position_sort = Not_position;
}

void	initialize_sort_info_second(t_sort_info *info)
{
	initialize_array(100, info->limits);
	info->limits_idx = 0;
	info->limit = 0;
	info->section_size = 0;
	info->b_pivot = 0;
	info->stack_b_size = 0;
	info->position_sort = Not_position;
}
