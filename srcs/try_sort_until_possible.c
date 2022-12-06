/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_sort_until_possible.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 10:16:35 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	is_exist_sorted_over_2(t_sort_info *info, t_dcl_list *stack)
{
	int			count;
	t_dcl_list	*node;

	count = 0;
	node = stack->next;
	while (node != stack)
	{
		if (node->index != (info->sorted + count))
		{
			break ;
		}
		count += 1;
		node = node->next;
	}
	if (2 < count)
	{
		return (true);
	}
	return (false);
}

static t_list	*try_sort_check_over_2(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	if (is_exist_sorted_over_2(info, stack_a->next))
	{
		log = execute_operation(Push_b, stack_a, stack_b, log);
		while (info->sorted == stack_a->next->index)
		{
			log = try_sort_check_exist_next(info, stack_a, stack_b, log);
		}
		log = execute_operation(Push_a, stack_a, stack_b, log);
	}
	else
	{
		log = try_swap_next_sort_stack_b(info, stack_a, stack_b, log);
	}
	return (log);
}

t_list	*try_sort_until_possible(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	while (stack_a->next->index == info->sorted
		|| stack_a->next->next->index == info->sorted)
	{
		if (stack_a->next->index == info->sorted)
		{
			log = try_sort_check_exist_next(info, stack_a, stack_b, log);
			continue ;
		}
		if (stack_a->next->next->index == info->sorted)
		{
			log = try_sort_check_over_2(info, stack_a, stack_b, log);
			continue ;
		}
	}
	return (log);
}
