/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ranges.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/10 16:19:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_ranges(t_sort_range_index *ranges, int stack_size)
{
	ranges->size = stack_size;
	ranges->count_sorted = 0;
	ranges->begin = 0;
	ranges->end = stack_size;
	ranges->a_pivot = calculate_median(ranges->begin + ranges->end);
	ranges->b_pivot = 0;
	ranges->median = ranges->a_pivot;
	ranges->count_pushed = 0;
	ranges->cycle = 0;
}
