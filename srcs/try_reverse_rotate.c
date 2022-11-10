/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/10 18:12:41 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	is_reverse_rotate_a(t_sort_range_index *ranges, int index)
{
	if (ranges->count_sorted)
	{
		return (false);
	}
	if (ranges->a_pivot <= index)
	{
		return (false);
	}
	return (true);
}

// bool	is_reverse_rotate_b(t_sort_range_index *ranges, t_bidrect_circle_list *stack)
bool	is_reverse_rotate_b(t_bidrect_circle_list *stack)
{
	int	elements;

	elements = stack_len(stack);
	if (elements < 2)
	{
		return (false);
	}
	// if (stack_b->next->index < stack_b->prev->index)
	if (!is_head_less_than_tail(stack))
	{
		return (false);
	}
	/*
	// if (ranges->b_pivot <= stack->next->index)
	if (!is_under_b_pivot(ranges->b_pivot, stack->next->index))
	{
		return (false);
	}
	if (stack->next->next->index < stack->next->index)
	{
		return (false);
	}
	*/
	return (true);
}

t_list	*try_reverse_rotate_b(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	(void)ranges;
	// if (is_reverse_rotate_b(ranges, stack_b))
	if (is_reverse_rotate_b(stack_b))
	{
		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}

t_list	*try_reverse_rotate(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a,
		t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	bool	judge_a;
	bool	judge_b;

	judge_a = is_reverse_rotate_a(ranges, stack_a->next->index);
	// judge_b = is_reverse_rotate_b(ranges, stack_b);
	judge_b = is_reverse_rotate_b(stack_b);
	if (judge_a && judge_b)
	{
		head_p_log = execute_operation(Reverse_rotate_r, stack_a, stack_b, head_p_log);
	}
	else if (judge_a)
	{
		head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
	}
	else if (judge_b)
	{
		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}
