/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 17:58:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	is_descending_sorted_until_x(t_dcl_list *head_p)
{
	int			count;
	t_dcl_list	*node;

	count = 0;
	node = head_p->next;
	while (node->next != head_p)
	{
		if ((node->index - node->next->index) != 1)
		{
			break ;
		}
		count += 1;
		node = node->next;
	}
	if (0 < count)
	{
		return (true);
	}
	return (false);
}

static t_list	*try_rotate_b_check_descending_sorted(t_sort_info *info
		, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	if (info->stack_b_size < 1)
	{
		return (log);
	}
	if (is_descending_sorted_until_x(stack_b))
	{
		return (log);
	}
	log = execute_operation(Rotate_b, stack_a, stack_b, log);
	return (log);
}

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
	if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
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
	if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
	{
		return (true);
	}
	return (false);
}

t_list	*push_swap_stack_a(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	info->section_size = calculate_section_size(info, stack_a);
	if (info->section_size < SORT_MINIMAM_SIZE)
	{
		log = sort_section_size_under_4(info, stack_a, stack_b, log);
	}
	else
	{
		while (info->sorted <= stack_a->next->index
			&& stack_a->next->index < info->limit)
		{
			if (is_prepare_push_swap(info, stack_a, stack_b))
			{
				log = try_prepare_push_swap(info, stack_a, stack_b, log);
				continue ;
			}
			log = execute_operation(Push_b, stack_a, stack_b, log);
			if (is_under_b_pivot(info, stack_b->next))
			{
				log = try_rotate_b_check_descending_sorted(info, stack_a,
						stack_b, log);
			}
		}
	}
	return (log);
}
