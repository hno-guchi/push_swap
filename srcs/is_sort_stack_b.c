/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 14:29:58 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_sort_stack_b_prev(t_sort_info *info, t_dcl_list *prev_node)
{
	if (1 < info->stack_b_size)
	{
		if (prev_node->index == info->sorted)
		{
			return (true);
		}
	}
	return (false);
}

static bool	is_sort_stack_b_next(t_sort_info *info, t_dcl_list *next_node)
{
	if (0 < info->stack_b_size)
	{
		if (next_node->index == info->sorted)
		{
			return (true);
		}
	}
	return (false);
}

bool	is_sort_stack_b(t_sort_info *info, t_dcl_list *stack)
{
	if (is_sort_stack_b_next(info, stack->next))
	{
		return (true);
	}
	if (is_sort_stack_b_prev(info, stack->prev))
	{
		return (true);
	}
	return (false);
}
