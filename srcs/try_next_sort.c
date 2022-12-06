/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_next_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 16:55:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*try_push_next_sort(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node;

	node = stack_b->next;
	while (node != stack_b)
	{
		if (node->index == info->sorted)
		{
			log = execute_operation(Rotate_b, stack_a, stack_b, log);
			return (log);
		}
		node = node->next;
	}
	log = execute_operation(Push_a, stack_a, stack_b, log);
	return (log);
}

static t_list	*try_next_sort_stack_b(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	if (1 < info->stack_b_size)
	{
		if (stack_b->next->index == (info->sorted + 1))
		{
			log = try_push_next_sort(info, stack_a, stack_b, log);
			return (log);
		}
	}
	if (2 < info->stack_b_size)
	{
		if (stack_b->prev->index == (info->sorted + 1))
		{
			if (!is_exist_sort(info->sorted, stack_b))
			{
				log = execute_operation(Reverse_rotate_b, stack_a, stack_b,
						log);
				return (log);
			}
		}
	}
	return (log);
}

t_list	*try_next_sort(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	if (stack_a->next->index == (info->sorted + 1))
	{
		log = execute_operation(Rotate_a, stack_a, stack_b, log);
		return (log);
	}
	if (is_exist_next_sort_stack_b(info, stack_b))
	{
		log = try_next_sort_stack_b(info, stack_a, stack_b, log);
		return (log);
	}
	return (log);
}
