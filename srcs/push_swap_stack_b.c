/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 17:18:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static bool	is_empty_stack_b(t_dcl_list *stack_b)
{
	t_dcl_list	*node;

	node = stack_b->next;
	if (node == stack_b)
	{
		return (true);
	}
	return (false);
}

bool	is_push_a_next(t_sort_info *info, int index)
{
	if (info->b_pivot <= index && index < info->limit)
	{
		return (true);
	}
	return (false);
}

bool	is_push_a_prev(t_sort_info *info, int index)
{
	if (2 < info->stack_b_size)
	{
		if (info->b_pivot <= index && index < info->limit)
		{
			return (true);
		}
	}
	return (false);
}

int	search_begin_idx(t_dcl_list *stack)
{
	t_dcl_list	*node;
	int			begin_idx;

	node = stack->next;
	begin_idx = node->index;
	while (node != stack)
	{
		if (node->next != stack)
		{
			if (node->next->index < begin_idx)
			{
				begin_idx = node->next->index;
			}
		}
		node = node->next;
	}
	return (begin_idx);
}

int	search_end_idx(t_dcl_list *stack)
{
	t_dcl_list	*node;
	int			end_idx;

	node = stack->next;
	end_idx = node->index;
	while (node != stack)
	{
		if (node->next != stack)
		{
			if (end_idx < node->next->index)
			{
				end_idx = node->next->index;
			}
		}
		node = node->next;
	}
	end_idx += 1;
	return (end_idx);
}

void	set_sort_info_stack_b(t_sort_info *info, t_dcl_list *stack)
{
	int			begin_idx;
	int			end_idx;

	begin_idx = search_begin_idx(stack);
	end_idx = search_end_idx(stack);
	if (end_idx - begin_idx < 4)
	{
		info->b_pivot = info->sorted;
	}
	else
	{
		info->b_pivot = calculate_median(begin_idx + end_idx);
	}
	info->limits[info->limits_idx] = end_idx;
	info->limits_idx += 1;
	info->limit = end_idx;
	info->stack_b_size = stack_len(stack);
}

bool	is_exist_push_a(t_sort_info *info, t_dcl_list *stack)
{
	t_dcl_list	*node;

	node = stack->next;
	if (info->stack_b_size == 0)
	{
		return (false);
	}
	while (node != stack)
	{
		if (is_push_a_next(info, node->index))
		{
			return (true);
		}
		node = node->next;
	}
	return (false);
}

t_list	*try_push_next_sort(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node;

	node = stack_b->next;
	while (node != stack_b)
	{
		if (node->index == info->sorted)
		{
			log = execute_operation(Rotate_b, stack_a, stack_b, log);
			return (log);
		}
		node = node->next;
	}
	log = execute_operation(Push_a, stack_a, stack_b, log);
	return (log);
}

bool	is_exist_sort(int sorted, t_dcl_list *stack)
{
	t_dcl_list	*node;

	node = stack->next;
	while (node != stack)
	{
		if (node->index == sorted)
		{
			return (true);
		}
		node = node->next;
	}
	return (false);
}

t_list	*all_push_a(t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	while (!is_empty_stack_b(stack_b))
	{
		log = execute_operation(Push_a, stack_a, stack_b, log);
	}
	return (log);
}

bool	is_complete_descending_sort(t_sort_info *info, t_dcl_list *stack)
{
	if (1 < info->stack_b_size)
	{
		if (is_descending_sorted(stack, info->sorted))
		{
			return (true);
		}
	}
	return (false);
}

bool	is_next_sort_stack_a(t_sort_info *info, t_dcl_list *stack)
{
	if (stack->next->index == (info->sorted + 1))
	{
		return (true);
	}
	return (false);
}

bool	is_next_sort_stack_b(t_sort_info *info, t_dcl_list *stack)
{
	if (1 < info->stack_b_size)
	{
		if (stack->next->index == (info->sorted + 1))
		{
			return (true);
		}
	}
	if (2 < info->stack_b_size)
	{
		if (stack->prev->index == (info->sorted + 1))
		{
			if (!is_exist_sort(info->sorted, stack))
			{
				return (true);
			}
		}
	}
	return (false);
}

t_list	*try_next_sort(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	if (stack_a->next->index == (info->sorted + 1))
	{
		log = execute_operation(Rotate_a, stack_a, stack_b, log);
		return (log);
	}
	if (1 < info->stack_b_size)
	{
		if (stack_b->next->index == (info->sorted + 1))
		{
			log = try_push_next_sort(info, stack_a, stack_b, log);
			return (log);
		}
	}
	if (2 < info->stack_b_size)
	{
		if (stack_b->prev->index == (info->sorted + 1))
		{
			if (!is_exist_sort(info->sorted, stack_b))
			{
				log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
				return (log);
			}
		}
	}
	return (log);
}

t_list	*try_push_a(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	if (is_push_a_next(info, stack_b->next->index))
	{
		if (is_push_a_prev(info, stack_b->prev->index))
		{
			if (stack_b->next->index < stack_b->prev->index)
			{
	 			log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
				return (log);
			}
		}
		log = execute_operation(Push_a, stack_a, stack_b, log);
		return (log);
	}
	if (is_push_a_prev(info, stack_b->prev->index))
	{
 		log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
		return (log);
	}
	return (log);
}

t_list	*push_a_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	while (is_exist_push_a(info, stack_b) && !is_empty_stack_b(stack_b))
	{
		// i += 1;
		// if (i == 1000)
		// 	exit(1) ;
		info->stack_b_size = stack_len(stack_b);
		if (is_complete_descending_sort(info, stack_b))
		{
			log = all_push_a(stack_a, stack_b, log);
			break ;
		}
		if (stack_a->next->index == info->sorted)
		{
			log = try_sort_check_exist_next(info, stack_a, stack_b, log);
			continue ;
		}
		if (stack_a->next->next->index == info->sorted)
		{
			log = try_swap_next_sort_stack_b(info, stack_a, stack_b, log);
			continue ;
		}
		if (is_sort_stack_b_next(info, stack_b->next) || is_sort_stack_b_prev(info, stack_b->prev))
		{
			log = try_sort_stack_b(info, stack_a, stack_b, log);
			continue ;
		}
		if (is_next_sort_stack_a(info, stack_a) || is_next_sort_stack_b(info, stack_b))
		{
			log = try_next_sort(info, stack_a, stack_b, log);
			continue ;
		}
		if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
		{
			log = try_swap(info, stack_a, stack_b, log);
			continue ;
		}
		if (is_push_a_next(info, stack_b->next->index) || is_push_a_prev(info, stack_b->prev->index))
		{
			log = try_push_a(info, stack_a, stack_b, log);
			continue ;
		}
		log = execute_operation(Rotate_b, stack_a, stack_b, log);
	}
	return (log);
}

t_list	*push_swap_stack_b(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	while (!is_empty_stack_b(stack_b))
	{
		// i += 1;
		// if (i == 1000)
		// 	exit(1) ;
		set_sort_info_stack_b(info, stack_b);
		log = push_a_half(info, stack_a, stack_b, log);
	}
	return (log);
}
