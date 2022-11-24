/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_under_4_descending.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/24 12:28:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sort_n_2_descending(t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node;

	node = stack_b->next;
	if (node->index < node->next->index)
	{
		log = execute_operation(Swap_b, stack_a, stack_b, log);
	}
	return (log);
}

static t_list	*sort_n_3_descending(t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node;
	t_order		order;

	node = stack_b->next;
	order = compare_3_values(node->index, node->next->index,
			node->next->next->index);
	if (order == Min_mid_max)
	{
		log = execute_operation(Swap_b, stack_a, stack_b, log);
		log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
	}
	else if (order == Min_max_mid)
	{
		log = execute_operation(Rotate_b, stack_a, stack_b, log);
	}
	else if (order == Mid_min_max)
	{
		log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
	}
	else if (order == Mid_max_min)
	{
		log = execute_operation(Swap_b, stack_a, stack_b, log);
	}
	else if (order == Max_min_mid)
	{
		log = execute_operation(Swap_b, stack_a, stack_b, log);
		log = execute_operation(Rotate_b, stack_a, stack_b, log);
	}
	return (log);
}

t_list	*sort_n_under_4_descending(int n, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	if (n == 2)
	{
		log = sort_n_2_descending(stack_a, stack_b, log);
	}
	else if (n == 3)
	{
		log = sort_n_3_descending(stack_a, stack_b, log);
	}
	return (log);
}
