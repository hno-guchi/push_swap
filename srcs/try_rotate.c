/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/09 20:16:07 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	is_rotate_a(int pivot, int index)
{
	if (pivot <= index)
	{
		return (true);
	}
	return (false);
}

bool	is_rotate_b(t_sort_range_index *ranges, int index)
{
	if (1 < ranges->count_pushed)
	{
		if (index < ranges->b_pivot)
		{
			return (true);
		}
	}
	return (false);
}

t_list	*try_rotate(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a,
		t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	bool	judge_rotate_a;
	bool	judge_rotate_b;

	judge_rotate_a = is_rotate_a(ranges->a_pivot, stack_a->next->index);
	judge_rotate_b = is_rotate_b(ranges, stack_b->next->index);
	if (judge_rotate_a && judge_rotate_b)
	{
		head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
	}
	else if (judge_rotate_a)
	{
		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	else if (judge_rotate_b)
	{
		head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}

bool	is_sort(int sorted, int index)
{
	if (index != sorted)
	{
		return (false);
	}
	return (true);
}

t_list	*try_sort(t_sort_range_index *ranges,
		t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b,
		t_list *head_p_log)
{
	bool	judge_rotate_b;

	judge_rotate_b = is_rotate_b(ranges, stack_b->next->index);
	if (is_sort(ranges->count_sorted, stack_a->next->index))
	{
		if (judge_rotate_b)
		{
			head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
		// ranges->count_sorted += 1;
	}
	else if (is_sort(ranges->count_sorted, stack_a->next->next->index))
	{
		head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		if (judge_rotate_b)
		{
			head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
		// ranges->count_sorted += 1;
	}
	return (head_p_log);
}

/*
t_list	*split_half();
if (1 < ranges->count_pushed || ranges->a_pivot <= stack_a->next->index)
{
	if (ranges->a_pivot <= stack_a->next->index)
		{
			if (1 < ranges->count_pushed)
			{
				if (stack_b->next->index < ranges->b_pivot)
				{
					head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
				}
			}
			else
			{
				head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			}
		}
		else if (1 < ranges->count_pushed)
		{
			if (stack_b->next->index < ranges->b_pivot)
			{
				head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
			}
		}
	}
}

t_list	*sort_under_median();

if (1 < ranges->count_pushed || stack_a->next->index == ranges->count_sorted || stack_a->next->next->index == ranges->count_sorted)
{
	if ((stack_a->next->index == ranges->count_sorted || stack_a->next->next->index == ranges->count_sorted))
	{
		if (stack_a->next->next->index == ranges->count_sorted)
		{
			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
		if (1 < ranges->count_pushed)
		{
			if (stack_b->next->index < ranges->b_pivot)
			{
				head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
				ranges->count_sorted += 1;
				continue ;
			}
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			ranges->count_sorted += 1;
			continue ;
		}
	}
	else if (1 < ranges->count_pushed)
	{
		if (stack_b->next->index < ranges->b_pivot)
		{
			head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
		}
	}
}

t_list	*sort_over_median();
if (1 < ranges->count_pushed || stack_a->next->index == ranges->count_sorted || stack_a->next->next->index == ranges->count_sorted)
{
	if ((stack_a->next->index == ranges->count_sorted || stack_a->next->next->index == ranges->count_sorted))
	{
		if (stack_a->next->next->index == ranges->count_sorted)
		{
			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
		if (1 < ranges->count_pushed)
		{
			if (stack_b->next->index < ranges->b_pivot)
			{
				head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
				ranges->count_sorted += 1;
				continue ;
			}
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			ranges->count_sorted += 1;
			continue ;
		}
	}
	else if (1 < ranges->count_pushed && stack_b->next->index < ranges->b_pivot)
	{
		head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
	}
}

t_list	*push_a_half();
if (ranges->b_pivot <= stack_b->next->index)
{
	head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	ranges->count_pushed += 1;
}
else
{
	if (stack_a->next->index == ranges->count_sorted)
	{
		head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
		ranges->count_sorted += 1;
	}
	else
	{
		head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
	}
}
*/

/*
// rotate_a
// t_list	*split_half();
if (ranges->a_pivot <= stack_a->next->index)
{
	head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
}
// t_list	*sort_under_median();
if (stack_a->next->index == ranges->count_sorted || stack_a->next->next->index == ranges->count_sorted)
{
	head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	ranges->count_sorted += 1;
	continue ;
}
// t_list	*sort_over_median();
if (stack_a->next->index == ranges->count_sorted || stack_a->next->next->index == ranges->count_sorted)
{
	head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
	head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	ranges->count_sorted += 1;
	continue ;
}
// t_list	*push_a_half();
if (stack_a->next->index == ranges->count_sorted)
{
	head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
	ranges->count_sorted += 1;
}
else
{
	head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
}

// rotate_b
// t_list	*split_half();
if (1 < ranges->count_pushed)
{
	if (stack_b->next->index < ranges->b_pivot)
	{
		head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
	}
}
// t_list	*sort_under_median();
if (1 < ranges->count_pushed)
{
	if (stack_b->next->index < ranges->b_pivot)
	{
		head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
	}
}
// t_list	*sort_over_median();
if (1 < ranges->count_pushed)
{
	else if (1 < ranges->count_pushed && stack_b->next->index < ranges->b_pivot)
	{
		head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
	}
}
// t_list	*push_a_half();
if (stack_a->next->index == ranges->count_sorted)
{
	head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
	ranges->count_sorted += 1;
}
else
{
	head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
}
*/
