/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 17:55:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static bool	is_exist_push_a(t_sort_info *info, t_dcl_list *stack)
{
	t_dcl_list	*node;

	node = stack->next;
	if (info->stack_b_size == 0)
	{
		return (false);
	}
	while (node != stack)
	{
		if (is_push_a_next(info, node->index))
		{
			return (true);
		}
		node = node->next;
	}
	return (false);
}

static bool	is_sort_stack_a(t_sort_info *info, t_dcl_list *stack)
{
	if (stack->next->index == info->sorted)
	{
		return (true);
	}
	if (stack->next->next->index == info->sorted)
	{
		return (true);
	}
	return (false);
}

static bool	is_prepare_push_swap(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b)
{
	if (is_sort_stack_a(info, stack_a))
	{
		return (true);
	}
	if (is_sort_stack_b(info, stack_b))
	{
		return (true);
	}
	if (is_exist_next_sort(info, stack_a, stack_b))
	{
		return (true);
	}
	if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
	{
		return (true);
	}
	return (false);
}

static t_list	*try_prepare_push_swap(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	if (is_sort_stack_a(info, stack_a))
	{
		log = try_sort_stack_a(info, stack_a, stack_b, log);
		return (log);
	}
	if (is_sort_stack_b(info, stack_b))
	{
		log = try_sort_stack_b(info, stack_a, stack_b, log);
		return (log);
	}
	if (is_exist_next_sort(info, stack_a, stack_b))
	{
		log = try_next_sort(info, stack_a, stack_b, log);
		return (log);
	}
	if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
	{
		log = try_swap(info, stack_a, stack_b, log);
		return (log);
	}
	return (log);
}

t_list	*push_swap_stack_b(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	while (!is_empty_stack_b(stack_b))
	{
		set_sort_info_stack_b(info, stack_b);
		while (is_exist_push_a(info, stack_b) && !is_empty_stack_b(stack_b))
		{
			info->stack_b_size = stack_len(stack_b);
			if (is_complete_descending_sort(info, stack_b))
			{
				log = try_all_push_a(stack_a, stack_b, log);
				break ;
			}
			if (is_prepare_push_swap(info, stack_a, stack_b))
			{
				try_prepare_push_swap(info, stack_a, stack_b, log);
				continue ;
			}
			if (is_push_a(info, stack_b))
			{
				log = try_push_a(info, stack_a, stack_b, log);
				continue ;
			}
			log = execute_operation(Rotate_b, stack_a, stack_b, log);
		}
	}
	return (log);
}
