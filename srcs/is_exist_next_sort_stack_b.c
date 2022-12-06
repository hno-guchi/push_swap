/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist_next_sort_stack_b.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 16:41:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_exist_next_sort_stack_b(t_sort_info *info, t_dcl_list *stack)
{
	if (1 < info->stack_b_size)
	{
		if (stack->next->index == (info->sorted + 1))
		{
			return (true);
		}
	}
	if (2 < info->stack_b_size)
	{
		if (stack->prev->index == (info->sorted + 1))
		{
			if (!is_exist_sort(info->sorted, stack))
			{
				return (true);
			}
		}
	}
	return (false);
}
