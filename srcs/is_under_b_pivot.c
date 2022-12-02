/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_under_b_pivot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 12:04:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_under_b_pivot(t_sort_info *info, t_dcl_list *node)
{
	if (1 < info->stack_b_size)
	{
		if (node->index < info->b_pivot)
		{
			return (true);
		}
	}
	return (false);
}
