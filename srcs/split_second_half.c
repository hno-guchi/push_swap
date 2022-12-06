/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_second_half.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 14:31:09 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*try_prepare_push_swap(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	info->stack_b_size = stack_len(stack_b);
	if (stack_a->next->index == info->sorted)
	{
		log = try_sort_check_exist_next(info, stack_a, stack_b, log);
		return (log);
	}
	if (is_sort_stack_b(info, stack_b))
	{
		log = try_sort_stack_b(info, stack_a, stack_b, log);
		return (log);
	}
	if (stack_a->next->index == (info->sorted + 1))
	{
		log = execute_operation(Rotate_a, stack_a, stack_b, log);
		return (log);
	}
	if (is_swap_a(info, stack_a) || is_swap_b(info, stack_b))
	{
		log = try_swap(info, stack_a, stack_b, log);
		return (log);
	}
	return (log);
}

static bool	is_prepare_push_swap(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b)
{
	info->stack_b_size = stack_len(stack_b);
	if (stack_a->next->index == info->sorted)
	{
		return (true);
	}
	if (is_sort_stack_b(info, stack_b))
	{
		return (true);
	}
	if (stack_a->next->index == (info->sorted + 1))
	{
		return (true);
	}
	if (is_swap_a(info, stack_a) || is_swap_b(info, stack_b))
	{
		return (true);
	}
	return (false);
}

t_list	*split_second_half(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	info->b_pivot = calculate_median(info->sorted + info->a_pivot);
	while (stack_a->next->index != HEAD_SORTED)
	{
		if (is_prepare_push_swap(info, stack_a, stack_b))
		{
			log = try_prepare_push_swap(info, stack_a, stack_b, log);
			continue ;
		}
		log = execute_operation(Push_b, stack_a, stack_b, log);
		if (is_under_b_pivot(info, stack_b->next))
		{
			log = execute_operation(Rotate_b, stack_a, stack_b, log);
		}
	}
	return (log);
}
