/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_under_4_descending.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 11:14:02 by hnoguchi         ###   ########.fr       */
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

static t_list	*sort_descending_min_mid_max(t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	log = execute_operation(Swap_b, stack_a, stack_b, log);
	log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
	return (log);
}

static t_list	*sort_descending_max_min_mid(t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	log = execute_operation(Swap_b, stack_a, stack_b, log);
	log = execute_operation(Rotate_b, stack_a, stack_b, log);
	return (log);
}

static t_list	*sort_n_3_descending(t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	t_order		order;

	order = compare_3_values(stack_b->next->index, stack_b->next->next->index,
			stack_b->next->next->next->index);
	if (order == Min_mid_max)
	{
		log = sort_descending_min_mid_max(stack_a, stack_b, log);
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
		log = sort_descending_max_min_mid(stack_a, stack_b, log);
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
