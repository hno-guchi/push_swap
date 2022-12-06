/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_section_size_3_util.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 10:48:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list	*try_sort_max_mid_min(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	log = execute_operation(Push_b, stack_a, stack_b, log);
	log = execute_operation(Swap_a, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	log = execute_operation(Push_a, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	return (log);
}

t_list	*try_sort_max_min_mid(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	log = execute_operation(Push_b, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	log = execute_operation(Push_a, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	return (log);
}

t_list	*try_sort_mid_max_min(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	log = execute_operation(Push_b, stack_a, stack_b, log);
	log = execute_operation(Swap_a, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	log = execute_operation(Push_a, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	return (log);
}

t_list	*try_sort_mid_min_max(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	log = execute_operation(Swap_a, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	return (log);
}

t_list	*try_sort_min_max_mid(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	log = try_sort(info, stack_a, stack_b, log);
	log = execute_operation(Swap_a, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	log = try_sort(info, stack_a, stack_b, log);
	return (log);
}
