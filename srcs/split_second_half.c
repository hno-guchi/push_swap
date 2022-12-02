/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_second_half.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 12:26:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*split_second_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	info->b_pivot = calculate_median(info->sorted + info->a_pivot);
	while (stack_a->next->index != HEAD_SORTED)
	{
		// i += 1;
		// if (i == 1000)
		// 	exit(1);
		// print_ranges_info(info, 'a');
		// output_stack(stack_a, stack_b);
		info->stack_b_size = stack_len(stack_b);
		if (stack_a->next->index == info->sorted)
		{
			log = try_sort_check_exist_next(info, stack_a, stack_b, log);
			continue ;
		}
		if (is_sort_stack_b_next(info, stack_b->next) || is_sort_stack_b_prev(info, stack_b->prev))
		{
			log = try_sort_stack_b(info, stack_a, stack_b, log);
			continue ;
		}
		if (stack_a->next->index == (info->sorted + 1))
		{
			log = execute_operation(Rotate_a, stack_a, stack_b, log);
			continue ;
		}
		if (is_swap_a(info, stack_a) || is_swap_b(info, stack_b))
		{
			log = try_swap(info, stack_a, stack_b, log);
			continue ;
		}
		log = execute_operation(Push_b, stack_a, stack_b, log);
		if (is_under_b_pivot(info, stack_b->next))
		{
			log = execute_operation(Rotate_b, stack_a, stack_b, log);
		}
		// putstr_log(log);
		// output_stack(stack_a, stack_b);
	}
	return (log);
}
