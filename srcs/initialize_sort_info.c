/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sort_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/22 19:46:25 by hnoguchi         ###   ########.fr       */
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
	initialize_array(100, info->begin_idxes);
	initialize_array(100, info->end_idxes);
	info->position_ary = 0;
	// info->a_pivot = calculate_median(ranges->begin + ranges->end);
	info->a_pivot = 0;
	info->b_pivot = 0;
	// info->median = ranges->a_pivot;
	info->median = 0;
	info->pushed = 0;
	// info->cycle = 0;
}
