/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_under_7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 14:55:49 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*push_b_n_times(int n, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	int						i;
	t_dcl_list	*node;

	i = 0;
	while (i < n)
	{
		node = stack_a->next;
		if (node->index < n)
		{
			log = execute_operation(Push_b, stack_a, stack_b,
					log);
			i += 1;
		}
		else
		{
			log = execute_operation(Rotate_a, stack_a, stack_b,
					log);
		}
	}
	return (log);
}

static t_list	*push_a_and_swap_a(t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node_a;
	t_dcl_list	*node_b;

	node_a = NULL;
	node_b = stack_b->next;
	while (node_b != stack_b)
	{
		log = execute_operation(Push_a, stack_a, stack_b, log);
		node_a = stack_a->next;
		if (node_a->next->index < node_a->index)
		{
			log = execute_operation(Swap_a, stack_a, stack_b,
					log);
		}
		node_b = stack_b->next;
	}
	return (log);
}

t_list	*sort_n_under_7(int n, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	log = push_b_n_times(n - 3, stack_a, stack_b, log);
	if (!is_ascending_sorted(stack_a))
	{
		log = sort_n_under_4(3, stack_a, stack_b, log);
	}
	if (!is_descending_sorted(stack_b, 0))
	{
		log = sort_n_under_4_descending(n - 3, stack_a, stack_b, log);
	}
	log = push_a_and_swap_a(stack_a, stack_b, log);
	return (log);
}
