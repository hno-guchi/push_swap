/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sort_info_second_half.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 11:36:41 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_sort_info_second_half(t_sort_info *info)
{
	initialize_array(ARRAY_SIZE, info->limits);
	info->limits_idx = 0;
	info->limit = 0;
	info->section_size = 0;
	info->b_pivot = 0;
	info->stack_b_size = 0;
	info->position_sort = Not_position;
}
