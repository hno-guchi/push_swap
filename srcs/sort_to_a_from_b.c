/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/22 20:45:13 by hnoguchi         ###   ########.fr       */
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
	// info->begin_idxes[now_index] = info->b_pivot;
	info->begin_idxes[now_index] = begin_idx;
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

bool	is_exist_sort_index_until_n_th(int n, t_sort_info *info, t_dcl_list *stack)
{
	int	i;
	t_dcl_list *head;
	t_dcl_list *tail;

	i = 0;
	head = stack->next;
	tail = stack->prev;
	if (head == stack || tail == stack || head == tail)
	{
		return (false);
	}
	if ((info->pushed - info->end_idxes[info->position_ary - 1]) < n)
	{
		n = info->pushed - info->end_idxes[info->position_ary - 1];
	}
	while (i < n && head != tail)
	{
		if (head->index == info->sorted || tail->index == info->sorted)
		{
			return (true);
		}
		i += 1;
		head = head->next;
		tail = tail->prev;
	}
	return (false);
}

static t_list	*try_sort2(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	int	stack_size;

	stack_size = stack_len2(stack_b);
	if (5 < stack_size)
	{
		if (stack_b->prev->prev->index == info->sorted)
		{
			// if (stack_a->prev->index == (info->sorted + 1))
			// {
			// 	head_p_log = execute_operation(Reverse_rotate_r, stack_a, stack_b, head_p_log);
			// }
			// else
			// {
				head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			// }
			head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			info->pushed += 1;
			info->sorted += 1;
		}
	}
	if (3 < stack_size)
	{
		if (stack_b->prev->prev->index == info->sorted)
		{
			// if (stack_a->prev->index == (info->sorted + 1))
			// {
			// 	head_p_log = execute_operation(Reverse_rotate_r, stack_a, stack_b, head_p_log);
			// }
			// else
			// {
				head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			// }
	 		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			info->pushed += 1;
			info->sorted += 1;
		}
	}
	if (2 < stack_size)
	{
		if (stack_b->prev->index == info->sorted)
		{
			// if (stack_a->prev->index == (info->sorted + 1))
			// {
			// 	head_p_log = execute_operation(Reverse_rotate_r, stack_a, stack_b, head_p_log);
			// }
			// else
			// {
				head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			// }
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			info->pushed += 1;
			info->sorted += 1;
		}
	}
	if (1 < stack_size)
	{
		if (stack_b->next->next->index == info->sorted)
		{
			if (stack_b->next->index == (info->sorted + 1))
			{
	 			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
				info->pushed += 1;
			}
			else
			{
				head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
			}
			if (stack_a->prev->index == (info->sorted + 1))
			{
				head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
			}
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			info->pushed += 1;
			info->sorted += 1;
		}
	}
	if (0 < stack_size)
	{
		if (stack_b->next->index == info->sorted)
		{
			if (stack_a->prev->index == (info->sorted + 1))
			{
				head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
			}
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			info->pushed += 1;
			info->sorted += 1;
		}
	}
	if (stack_a->next->next->index == info->sorted)
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
	return (head_p_log);
}

static t_list	*try_prepare_sort2(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	int	stack_size;

	stack_size = stack_len2(stack_b);
	if (5 < stack_size)
	{
		if (stack_b->prev->prev->index == (info->sorted + 1))
		{
			head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			info->pushed += 1;
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	// if (3 < stack_size)
	// {
	// 	if (stack_b->prev->prev->index == (info->sorted + 1))
	// 	{
	//  		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	//  		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	//  		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	//  		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	// 		info->pushed += 1;
	// 		info->sorted += 1;
	// 	}
	// }
	if (2 < stack_size)
	{
		if (stack_b->prev->index == (info->sorted + 1))
		{
	 		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			info->pushed += 1;
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	if (1 < stack_size)
	{
		if (stack_b->next->next->index == (info->sorted + 1))
		{
			// if (stack_b->next->index == (info->sorted + 1))
			// {
	 		// 	head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			// 	info->pushed += 1;
			// }
			// else
			// {
			// 	head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
			// }
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			info->pushed += 1;
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	if (0 < stack_size)
	{
		if (stack_b->next->index == (info->sorted + 1))
		{
	 		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			info->pushed += 1;
	 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	if (stack_a->next->next->index == (info->sorted + 1) && stack_a->next->index != info->sorted)
	{
 		head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	if (stack_a->next->index == (info->sorted + 1))
	{
 		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
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
		// print_info_info(info, 'b');
		// output_stack(stack_a, stack_b);
		head_p_log = try_prepare_sort2(info, stack_a, stack_b, head_p_log);
		head_p_log = try_sort2(info, stack_a, stack_b, head_p_log);
		head_p_log = try_swap2(stack_a, stack_b, head_p_log);
		if (!is_under_b_pivot(info->b_pivot, stack_b->next->index))
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
		print_sort_info(info, 'b');
		head_p_log = push_a_half(info, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}
