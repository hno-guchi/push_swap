/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_under_4_descending.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/02 12:41:46 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sort_n_2_descending(t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_bidrect_circle_list	*node;

	node = stack_b->next;
	if (node->index < node->next->index)
	{
		head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}

static t_list	*sort_n_3_descending(t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_bidrect_circle_list	*node;
	t_order					order;

	node = stack_b->next;
	order = compare_3_values(node->index, node->next->index,
			node->next->next->index);
	if (order == Min_mid_max || order == Max_min_mid || order == Mid_max_min)
	{
		head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
	}
	if (order == Max_min_mid || order == Min_max_mid)
	{
		head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
	}
	if (order == Min_mid_max || order == Mid_min_max)
	{
		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b,
				head_p_log);
	}
	return (head_p_log);
}

t_list	*sort_n_under_4_descending(int n, t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	if (n == 2)
	{
		head_p_log = sort_n_2_descending(stack_a, stack_b, head_p_log);
	}
	else if (n == 3)
	{
		head_p_log = sort_n_3_descending(stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}
