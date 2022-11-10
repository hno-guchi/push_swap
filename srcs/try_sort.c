/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/10 12:09:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	is_sort(int sorted, t_bidrect_circle_list *stack)
{
	t_bidrect_circle_list *node;

	node = stack->next;
	if (node == stack)
	{
		return (false);
	}
	if (node->index != sorted)
	{
		return (false);
	}
	return (true);
}

t_bidrect_circle_list *search_stack_n_node(t_bidrect_circle_list *head_p, int n)
{
	int						len;
	t_bidrect_circle_list	*node;

	len = 1;
	node = head_p->next;
	while (node != head_p && len < n)
	{
		node = node->next;
		len += 1;
	}
	return (node);
}

bool	is_sort_n_node(int sorted, t_bidrect_circle_list *head_p, int n)
{
	t_bidrect_circle_list	*node;

	node = search_stack_n_node(head_p, n);
	if (node == head_p)
	{
		return (false);
	}
	if (node->index != sorted)
	{
		return (false);
	}
	return (true);
}

t_list	*try_sort(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	bool	judge_b;

	judge_b = is_rotate_b(ranges, stack_b);
	if (is_sort(ranges->count_sorted, stack_a))
	{
		if (judge_b)
		{
			head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	else if (is_sort_n_node(ranges->count_sorted, stack_a, 2))
	{
		if (is_sort(ranges->count_sorted + 1, stack_a) || is_sort(ranges->count_sorted + 1, stack_b))
		{
			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
		else
		{
			head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
		}
		if (judge_b)
		{
			head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	return (head_p_log);
}
