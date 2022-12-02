/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 18:16:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_swap_b(t_sort_info *info, t_dcl_list *node)
{
	if (1 < info->stack_b_size)
	{
		if ((node->index - node->next->index) == -1)
		{
			return (true);
		}
	}
	return (false);
}

bool	is_swap_a(t_sort_info *info, t_dcl_list *node)
{
	if ((node->index - node->next->index) == 1)
	{
		if (info->b_pivot <= node->index && info->b_pivot <= node->next->index)
		{
			return (true);
		}
	}
	return (false);
}

static t_operation	judge_operation_swap(t_sort_info *info,
		t_dcl_list *stack_a, t_dcl_list *stack_b)
{
	if (is_swap_a(info, stack_a->next) && is_swap_b(info, stack_b->next))
	{
		return (Swap_s);
	}
	else if (is_swap_a(info, stack_a->next) && !is_swap_b(info, stack_b->next))
	{
		return (Swap_a);
	}
	else if (!is_swap_a(info, stack_a->next) && is_swap_b(info, stack_b->next))
	{
		return (Swap_b);
	}
	return (Not);
}

t_list	*try_swap(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b,
		t_list *log)
{
	t_operation	operation;

	operation = judge_operation_swap(info, stack_a, stack_b);
	log = execute_operation(operation, stack_a, stack_b, log);
	return (log);
}
