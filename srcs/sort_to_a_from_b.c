/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/23 17:18:06 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_dcl_list *head_p_stack_a, t_dcl_list *head_p_stack_b);
void	print_sort_info(t_sort_info *info, char stack);
t_list	*try_push_a(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
bool	is_empty_stack_b(t_dcl_list *stack_b);

bool	is_under_b_pivot(int b_pivot, int index)
{
	return (index < b_pivot);
}

bool	is_target_push_a(int pivot, int end, int index)
{
	return (pivot <= index && index < end);
}

static int	stack_len2(t_dcl_list *stack)
{
	int			len;
	t_dcl_list	*node;

	len = 0;
	node = stack->next;
	if (node == stack)
	{
		return (0);
	}
	while (node != stack)
	{
		len += 1;
		node = node->next;
	}
	return (len);
}

void	set_ranges_stack_b(t_sort_info *info, t_dcl_list *stack_b)
{
	t_dcl_list	*node;
	int			begin_idx;
	int			end_idx;
	int			now_index;

	node = stack_b->next;
	begin_idx = node->index;
	end_idx = node->index;
	now_index = info->position_ary;
	while (node != stack_b)
	{
		if (node->next->index < begin_idx)
		{
			begin_idx = node->next->index;
		}
		if (end_idx < node->next->index)
		{
			end_idx = node->next->index;
		}
		node = node->next;
	}
	end_idx += 1;
	if (end_idx - begin_idx < 4)
	{
		info->b_pivot = 0;
		info->pushed = begin_idx;
	}
	else
	{
		info->b_pivot = calculate_median(begin_idx + end_idx);
		info->pushed = info->b_pivot;
	}
	info->begin_idxes[now_index] = info->b_pivot;
	// info->begin_idxes[now_index] = begin_idx;
	info->end_idxes[now_index] = end_idx;
	info->position_ary += 1;
}

static t_list	*try_swap2(t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	t_operation	operation;
	t_operation	a;
	t_operation	b;

	operation = Not;
	a = Not;
	b = Not;
	if ((stack_a->next->index - stack_a->next->next->index) == 1)
	{
		a = Swap_a;
	}
	if ((stack_b->next->index - stack_b->next->next->index) == -1)
	{
		b = Swap_b;
	}
	if (a == Swap_a && b == Swap_b)
	{
		operation = Swap_s;
	}
	else if (a == Swap_a && b != Swap_b)
	{
		operation = a;
	}
	else if (a != Swap_a && b == Swap_b)
	{
		operation = b;
	}
	head_p_log = execute_operation(operation, stack_a, stack_b, head_p_log);
	return (head_p_log);
}

t_list	*sort_rotate_a(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	if (stack_a->next->index == info->sorted)
	{
		if (stack_a->prev->index == (info->sorted + 1))
		{
			head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
 			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		info->sorted += 1;
	}
	else if (stack_a->next->next->index == info->sorted)
	{
 		head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		if (stack_a->prev->index == (info->sorted + 1))
		{
			head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
 			head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
		}
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		info->sorted += 1;
	}
	return (head_p_log);
}

/*
static t_list	*try_prepare_sort2(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	if (stack_a->next->index == (info->sorted + 1))
	{
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	if (stack_a->next->next->index == (info->sorted + 1) && stack_a->next->index != info->sorted)
	{
 		head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}
*/

static t_list	*prepare_sort_next_value(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	if (info->position_sort == Next)
	{
		if (is_target_push_a(info->b_pivot, info->end_idxes[info->position_ary - 1], stack_b->next->index))
		{
			info->pushed += 1;
		}
		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	 	head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	else if (info->position_sort == Prev)
	{
		if (is_target_push_a(info->b_pivot, info->end_idxes[info->position_ary - 1], stack_b->prev->index))
		{
			info->pushed += 1;
		}
	 	head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	 	head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	 	head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}

static t_list	*sort_push_a(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	if (info->position_sort == Next)
	{
		if (is_target_push_a(info->b_pivot, info->end_idxes[info->position_ary - 1], stack_b->next->index))
		{
			info->pushed += 1;
		}
	 	head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	}
	else if (info->position_sort == Prev)
	{
		if (is_target_push_a(info->b_pivot, info->end_idxes[info->position_ary - 1], stack_b->next->index))
		{
			info->pushed += 1;
		}
		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}

t_position	search_target_stack_b(int target, t_dcl_list *stack)
{
	int	stack_size;

	stack_size = stack_len2(stack);
	if (0 < stack_size)
	{
		if (stack->next->index == target)
		{
			return (Next);
		}
	}
	else if (2 < stack_size)
	{
		if (stack->prev->index == target)
		{
			return (Prev);
		}
	}
	return (Not_position);
}

bool	is_sort_stack_a(int target, t_dcl_list *stack)
{
	if (stack->next->index == target)
	{
		return (true);
	}
	else if (stack->next->next->index == target)
	{
		return (true);
	}
	return (false);
}

t_list	*push_a_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	// int	cycle = 0;
	int	end_idx;

	end_idx = info->end_idxes[info->position_ary - 1];
	while (1)
	{
		if (is_finish(info->pushed, end_idx) || is_empty_stack_b(stack_b))
		{
			break;
		}
		// print_sort_info(info, 'b');
		// output_stack(stack_a, stack_b);
		// head_p_log = try_prepare_sort2(info, stack_a, stack_b, head_p_log);
		if (is_sort_stack_a(info->sorted, stack_a))
		{
			head_p_log = sort_rotate_a(info, stack_a, stack_b, head_p_log);
			continue ;
		}
		info->position_sort = search_target_stack_b(info->sorted + 1, stack_b);
		if (info->position_sort != Not_position)
		{
			head_p_log = prepare_sort_next_value(info, stack_a, stack_b, head_p_log);
			continue ;
		}
		info->position_sort = search_target_stack_b(info->sorted, stack_b);
		if (info->position_sort != Not_position)
		{
			head_p_log = sort_push_a(info, stack_a, stack_b, head_p_log);
			continue ;
		}
		head_p_log = try_swap2(stack_a, stack_b, head_p_log);
		if (is_target_push_a(info->b_pivot, end_idx, stack_b->next->index))
		{
		 	head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
		 	info->pushed += 1;
		}
		else
		{
			head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
		}
		// putstr_log(head_p_log);
		// output_stack(stack_a, stack_b);
		// cycle += 1;
		// if (cycle == 1000)
		// {
		// 	exit(1);
			// return (head_p_log);
		// }
	}
	return (head_p_log);
}

t_list	*sort_to_a_from_b(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	while (1)
	{
		if (is_empty_stack_b(stack_b))
		{
			break ;
		}
		set_ranges_stack_b(info, stack_b);
		// print_sort_info(info, 'b');
		head_p_log = push_a_half(info, stack_a, stack_b, head_p_log);
	}
	if (is_sort_stack_a(info->sorted, stack_a))
	{
		head_p_log = sort_rotate_a(info, stack_a, stack_b, head_p_log);
	}
	// print_sort_info(info, 'b');
	return (head_p_log);
}
