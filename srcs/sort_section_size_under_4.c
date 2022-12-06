/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_section_size_under_4.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 10:59:40 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_list	*sort_section_size_2(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	int		i;

	i = 0;
	if ((stack_a->next->index - stack_a->next->next->index) == 1)
	{
		log = execute_operation(Swap_a, stack_a, stack_b, log);
	}
	while (i < info->section_size)
	{
		log = try_sort(info, stack_a, stack_b, log);
		i += 1;
	}
	return (log);
}

static bool	is_ascending_sorted_section(t_dcl_list *stack)
{
	t_order	order;

	order = compare_3_values(stack->next->index,
			stack->next->next->index,
			stack->next->next->next->index);
	if (order == Min_mid_max)
	{
		return (true);
	}
	return (false);
}

static t_list	*try_sort_min_mid_max(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	int	i;

	i = 0;
	while (i < info->section_size)
	{
		log = try_sort(info, stack_a, stack_b, log);
		i += 1;
	}
	return (log);
}

static t_list	*sort_section_size_3(t_sort_info *info, t_dcl_list *stack_a,
		t_dcl_list *stack_b, t_list *log)
{
	t_order	order;

	order = compare_3_values(stack_a->next->index, stack_a->next->next->index,
			stack_a->next->next->next->index);
	if (order == Min_max_mid)
	{
		log = try_sort_min_max_mid(info, stack_a, stack_b, log);
	}
	else if (order == Mid_min_max)
	{
		log = try_sort_mid_min_max(info, stack_a, stack_b, log);
	}
	else if (order == Mid_max_min)
	{
		log = try_sort_mid_max_min(info, stack_a, stack_b, log);
	}
	else if (order == Max_min_mid)
	{
		log = try_sort_max_min_mid(info, stack_a, stack_b, log);
	}
	else if (order == Max_mid_min)
	{
		log = try_sort_max_mid_min(info, stack_a, stack_b, log);
	}
	return (log);
}

t_list	*sort_section_size_under_4(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	if (info->section_size == 1)
	{
		log = try_sort(info, stack_a, stack_b, log);
	}
	else if (info->section_size == 2)
	{
		log = sort_section_size_2(info, stack_a, stack_b, log);
	}
	else if (info->section_size == 3)
	{
		if (is_ascending_sorted_section(stack_a))
		{
			log = try_sort_min_mid_max(info, stack_a, stack_b, log);
		}
		else
		{
			log = sort_section_size_3(info, stack_a, stack_b, log);
		}
	}
	return (log);
}
