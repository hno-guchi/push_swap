/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_under_7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/02 12:49:52 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*push_b_n_times(int n, t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	int						i;
	t_bidrect_circle_list	*node;

	i = 0;
	while (i < n)
	{
		node = stack_a->next;
		if (node->index < n)
		{
			head_p_log = execute_operation(Push_b, stack_a, stack_b,
					head_p_log);
			i += 1;
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
					head_p_log);
		}
	}
	return (head_p_log);
}

static t_list	*push_a_and_swap_a(t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_bidrect_circle_list	*node_a;
	t_bidrect_circle_list	*node_b;

	node_a = NULL;
	node_b = stack_b->next;
	while (node_b != stack_b)
	{
		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
		node_a = stack_a->next;
		if (node_a->next->index < node_a->index)
		{
			head_p_log = execute_operation(Swap_a, stack_a, stack_b,
					head_p_log);
		}
		node_b = stack_b->next;
	}
	return (head_p_log);
}

t_list	*sort_n_under_7(int n, t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	head_p_log = push_b_n_times(n - 3, stack_a, stack_b, head_p_log);
	if (!is_ascending_sorted(stack_a))
	{
		head_p_log = sort_n_under_4(3, stack_a, stack_b, head_p_log);
	}
	if (!is_descending_sorted(stack_b))
	{
		head_p_log = sort_n_under_4_descending(n - 3, stack_a, stack_b,
				head_p_log);
	}
	head_p_log = push_a_and_swap_a(stack_a, stack_b, head_p_log);
	return (head_p_log);
}
