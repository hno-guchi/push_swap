/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist_next_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 14:57:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_exist_next_sort_stack_a(t_sort_info *info, t_dcl_list *stack)
{
	if (stack->next->index == (info->sorted + 1))
	{
		return (true);
	}
	return (false);
}

bool	is_exist_sort(int sorted, t_dcl_list *stack)
{
	t_dcl_list	*node;

	node = stack->next;
	while (node != stack)
	{
		if (node->index == sorted)
		{
			return (true);
		}
		node = node->next;
	}
	return (false);
}

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

bool	is_exist_next_sort(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b)
{
	if (is_exist_next_sort_stack_a(info, stack_a))
	{
		return (true);
	}
	if (is_exist_next_sort_stack_b(info, stack_b))
	{
		return (true);
	}
	return (false);
}
