/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort_info_stack_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 14:10:43 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_begin_idx(t_dcl_list *stack)
{
	t_dcl_list	*node;
	int			begin_idx;

	node = stack->next;
	begin_idx = node->index;
	while (node != stack)
	{
		if (node->next != stack)
		{
			if (node->next->index < begin_idx)
			{
				begin_idx = node->next->index;
			}
		}
		node = node->next;
	}
	return (begin_idx);
}

static int	search_end_idx(t_dcl_list *stack)
{
	t_dcl_list	*node;
	int			end_idx;

	node = stack->next;
	end_idx = node->index;
	while (node != stack)
	{
		if (node->next != stack)
		{
			if (end_idx < node->next->index)
			{
				end_idx = node->next->index;
			}
		}
		node = node->next;
	}
	end_idx += 1;
	return (end_idx);
}

void	set_sort_info_stack_b(t_sort_info *info, t_dcl_list *stack)
{
	int			begin_idx;
	int			end_idx;

	begin_idx = search_begin_idx(stack);
	end_idx = search_end_idx(stack);
	if (end_idx - begin_idx < 4)
	{
		info->b_pivot = info->sorted;
	}
	else
	{
		info->b_pivot = calculate_median(begin_idx + end_idx);
	}
	info->limits[info->limits_idx] = end_idx;
	info->limits_idx += 1;
	info->limit = end_idx;
	info->stack_b_size = stack_len(stack);
}
