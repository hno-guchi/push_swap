/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort_info_next_section.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 14:12:36 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_limit(t_sort_info *info)
{
	int	limit;

	limit = 0;
	if (info->limits_idx <= 0)
	{
		return (-1);
	}
	info->limits_idx -= 1;
	limit = info->limits[info->limits_idx];
	info->limits[info->limits_idx] = 0;
	return (limit);
}

static int	get_next_limit(t_sort_info *info)
{
	int	limit;

	limit = get_limit(info);
	if (limit == -1)
	{
		return (-1);
	}
	while (limit <= info->sorted)
	{
		limit = get_limit(info);
		if (limit == -1)
		{
			return (-1);
		}
	}
	return (limit);
}

void	set_sort_info_next_section(t_sort_info *info, t_dcl_list *stack)
{
	info->limit = get_next_limit(info);
	if (info->limit == -1)
	{
		return ;
	}
	info->section_size = calculate_section_size(info, stack);
	info->b_pivot = calculate_median(info->sorted + info->limit);
}
