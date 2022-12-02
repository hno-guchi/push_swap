/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 12:24:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_list	*try_prepare_push_swap(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	info->stack_b_size = stack_len(stack_b);
	if (stack_a->next->index == info->sorted)
	{
		log = try_sort_check_exist_next(info, stack_a, stack_b, log);
		return (log);
	}
	if (is_sort_stack_b_next(info, stack_b->next) || is_sort_stack_b_prev(info, stack_b->prev))
	{
		log = try_sort_stack_b(info, stack_a, stack_b, log);
		return (log);
	}
	if (stack_a->next->index == (info->sorted + 1))
	{
		log = execute_operation(Rotate_a, stack_a, stack_b, log);
		return (log);
	}
	if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
	{
		log = try_swap(info, stack_a, stack_b, log);
		return (log);
	}
	return (log);
}

static bool	is_prepare_push_swap(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b)
{
	info->stack_b_size = stack_len(stack_b);
	if (stack_a->next->index == info->sorted)
	{
		return (true);
	}
	if (is_sort_stack_b_next(info, stack_b->next) || is_sort_stack_b_prev(info, stack_b->prev))
	{
		return (true);
	}
	if (stack_a->next->index == (info->sorted + 1))
	{
		return (true);
	}
	if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
	{
		return (true);
	}
	return (false);
}

t_list	*push_swap_stack_a(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	info->section_size = calculate_section_size(info, stack_a);
	if (info->section_size < SORT_MINIMAM_SIZE)
	{
		log = sort_section_size_under_4(info, stack_a, stack_b, log);
	}
	else
	{
		while (info->sorted <= stack_a->next->index && stack_a->next->index < info->limit)
		{
			// if (i == 1000)
			// 	exit(1) ;
			// i += 1;
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
	}
	return (log);
}
