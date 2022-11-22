/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/11 19:14:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	is_swap_a(t_sort_range_index *ranges, t_bidrect_circle_list *stack)
{
	if (is_sort(ranges->count_sorted, stack))
	{
		return (false);
	}
	if (is_sort_n_node(ranges->count_sorted, stack, 2))
	{
		return (false);
	}
	if (is_under_b_pivot(ranges->b_pivot, stack->next->index) && is_under_b_pivot(ranges->b_pivot, stack->next->next->index))
	{
		if (is_head_less_than_second(stack))
		{
			return (false);
		}
	}
	if (is_head_less_than_second(stack))
	// if ((stack->next->index + 1) != stack->next->next->index)
	{
		return (false);
	}
	if (is_sorted_head(ranges->count_sorted, stack->next->next->index))
	{
		return (false);
	}
	return (true);
}

// bool	is_swap_b(int pushed, t_bidrect_circle_list *stack)
bool	is_swap_b(t_bidrect_circle_list *stack)
{
	int	elements;

	elements = stack_len(stack);
	if (elements < 2)
	{
		return (false);
	}
	if (!is_head_less_than_second(stack))
	// if (stack->next->index != (stack->next->next->index + 1))
	{
		return (false);
	}
	return (true);
}

t_list	*try_swap(t_sort_range_index *ranges,
		t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b,
		t_list *head_p_log)
{
	bool	judge_swap_a;
	bool	judge_swap_b;

	judge_swap_a = is_swap_a(ranges, stack_a);
	// judge_swap_b = is_swap_b(ranges->count_pushed, stack_b);
	judge_swap_b = is_swap_b(stack_b);
	if (judge_swap_a && judge_swap_b)
	{
		head_p_log = execute_operation(Swap_s, stack_a, stack_b, head_p_log);
	}
	else if (judge_swap_a)
	{
		head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
	}
	else if (judge_swap_b)
	{
		head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}

/*
if (1 < ranges->count_pushed || stack_a->next->next->index < stack_a->next->index)
{
	if (stack_a->next->next->index < stack_a->next->index)
	{
		if (1 < ranges->count_pushed)
		{
			if (stack_b->next->index < stack_b->next->next->index)
			{
				head_p_log = execute_operation(Swap_s, stack_a, stack_b, head_p_log);
			}
		}
		else
		{
			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
	}
	else if (1 < ranges->count_pushed)
	{
		if (stack_b->next->index < stack_b->next->next->index)
		{
			head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
		}
	}
}

if (1 < ranges->count_pushed || stack_a->next->next->index < stack_a->next->index)
{
	if (stack_a->next->next->index != 0 && stack_a->next->next->index < stack_a->next->index)
	{
		if (1 < ranges->count_pushed)
		{
			if (stack_b->next->index < stack_b->next->next->index)
			{
				head_p_log = execute_operation(Swap_s, stack_a, stack_b, head_p_log);
			}
		}
		else
		{
			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
	}
	else if (1 < ranges->count_pushed)
	{
		if (stack_b->next->index < stack_b->next->next->index)
		{
			head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
		}
	}
}

if ((stack_b->next->index < stack_b->next->next->index) || (stack_a->next->next->index < stack_a->next->index))
{
	if ((stack_b->next->index < stack_b->next->next->index) && (stack_a->next->next->index < stack_a->next->index))
	{
		if (ranges->count_sorted == 0 || (0 < ranges->count_sorted && stack_a->next->next->index != 0))
		{
			head_p_log = execute_operation(Swap_s, stack_a, stack_b, head_p_log);
		}
	}
	else if (stack_a->next->next->index < stack_a->next->index)
	{
		if (ranges->count_sorted == 0 || (0 < ranges->count_sorted && stack_a->next->next->index != 0))
		{
			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
	}
	else if (stack_b->next->index < stack_b->next->next->index)
	{
		head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
	}
}
*/
