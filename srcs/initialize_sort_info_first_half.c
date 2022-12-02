/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sort_info_first_half.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 14:00:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_sort_info_first_half(t_sort_info *info, int stack_size)
{
	info->size = stack_size;
	info->sorted = 0;
	initialize_array(ARRAY_SIZE, info->limits);
	info->limits_idx = 0;
	info->limit = 0;
	info->section_size = 0;
	// info->b_pivot = 0;
	info->a_pivot = calculate_median(info->size);
	// info->median = calculate_median(info->size);
	info->b_pivot = calculate_median(info->sorted + info->a_pivot);
	info->stack_b_size = 0;
	// info->position_sort = Not_position;
}
