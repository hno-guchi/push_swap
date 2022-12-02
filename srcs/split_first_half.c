/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_first_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 12:06:19 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*try_rotate_under_b_pivot(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_operation	operation;

	operation = Rotate_b;
	if (info->a_pivot <= stack_a->next->index)
	{
		operation = Rotate_r;
	}
	log = execute_operation(operation, stack_a, stack_b, log);
	return (log);
}

t_list	*split_first_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	int	pushed;

	pushed = 0;
	while (pushed != info->a_pivot)
	{
		// i += 1;
		// if (i == 1000)
		// 	exit(1);
		// print_ranges_info(info, 'a');
		// output_stack(stack_a, stack_b);
		info->stack_b_size = stack_len(stack_b);
		if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
		{
			log = try_swap(info, stack_a, stack_b, log);
			continue ;
		}
		if (stack_a->next->index < info->a_pivot)
		{
			log = execute_operation(Push_b, stack_a, stack_b, log);
			pushed += 1;
			if (is_under_b_pivot(info, stack_b->next))
			{
				log = try_rotate_under_b_pivot(info, stack_a, stack_b, log);
			}
			continue ;
		}
		log = execute_operation(Rotate_a, stack_a, stack_b, log);
		// putstr_log(log);
		// output_stack(stack_a, stack_b);
	}
	return (log);
}
