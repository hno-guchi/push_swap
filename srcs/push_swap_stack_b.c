/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 14:58:33 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

t_list	*all_push_a(t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	while (!is_empty_stack_b(stack_b))
	{
		log = execute_operation(Push_a, stack_a, stack_b, log);
	}
	return (log);
}

t_list	*try_push_next_sort(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
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

/*
bool	is_exist_next_sort_stack_b(t_sort_info *info, t_dcl_list *stack_b)
{
	if (1 < info->stack_b_size)
	{
		if (stack_b->next->index == (info->sorted + 1))
		{
			return (true);
		}
	}
	if (2 < info->stack_b_size)
	{
		if (stack_b->prev->index == (info->sorted + 1))
		{
			if (!is_exist_sort(info->sorted, stack_b))
			{
				return (true);
			}
		}
	}
	return (false);
}
*/

t_list	*try_next_sort_stack_b(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
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
				log = execute_operation(Reverse_rotate_b, stack_a, stack_b,
						log);
				return (log);
			}
		}
	}
	return (log);
}

t_list	*try_next_sort(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	if (stack_a->next->index == (info->sorted + 1))
	{
		log = execute_operation(Rotate_a, stack_a, stack_b, log);
		return (log);
	}
	if (is_exist_next_sort_stack_b(info, stack_b))
	{
		log = try_next_sort_stack_b(info, stack_a, stack_b, log);
		return (log);
	}
	return (log);
}

t_list	*try_push_a(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b
		, t_list *log)
{
	if (is_push_a_next(info, stack_b->next->index))
	{
		if (is_push_a_prev(info, stack_b->prev->index))
		{
			if (stack_b->next->index < stack_b->prev->index)
			{
				log = execute_operation(Reverse_rotate_b, stack_a, stack_b,
						log);
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

static bool	is_sort_stack_a(t_sort_info *info, t_dcl_list *stack)
{
	if (stack->next->index == info->sorted)
	{
		return (true);
	}
	if (stack->next->next->index == info->sorted)
	{
		return (true);
	}
	return (false);
}

t_list	*try_sort_stack_a(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	if (stack_a->next->index == info->sorted)
	{
		log = try_sort_check_exist_next(info, stack_a, stack_b, log);
		return (log);
	}
	if (stack_a->next->next->index == info->sorted)
	{
		log = try_swap_next_sort_stack_b(info, stack_a, stack_b, log);
		return (log);
	}
	return (log);
}

static bool	is_prepare_push_swap(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b)
{
	if (stack_a->next->index == info->sorted)
	{
		return (true);
	}
	if (stack_a->next->next->index == info->sorted)
	{
		return (true);
	}
	if (is_sort_stack_b(info, stack_b))
	{
		return (true);
	}
	if (is_exist_next_sort(info, stack_a, stack_b))
	{
		return (true);
	}
	if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
	{
		return (true);
	}
	return (false);
}

static t_list	*try_prepare_push_swap(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	if (is_sort_stack_a(info, stack_a))
	{
		log = try_sort_stack_a(info, stack_a, stack_b, log);
		return (log);
	}
	if (is_sort_stack_b(info, stack_b))
	{
		log = try_sort_stack_b(info, stack_a, stack_b, log);
		return (log);
	}
	if (is_exist_next_sort(info, stack_a, stack_b))
	{
		log = try_next_sort(info, stack_a, stack_b, log);
		return (log);
	}
	if (is_swap_a(info, stack_a->next) || is_swap_b(info, stack_b->next))
	{
		log = try_swap(info, stack_a, stack_b, log);
		return (log);
	}
	return (log);
}

t_list	*push_a_half(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	while (is_exist_push_a(info, stack_b) && !is_empty_stack_b(stack_b))
	{
		info->stack_b_size = stack_len(stack_b);
		if (is_complete_descending_sort(info, stack_b))
		{
			log = all_push_a(stack_a, stack_b, log);
			break ;
		}
		if (is_prepare_push_swap(info, stack_a, stack_b))
		{
			try_prepare_push_swap(info, stack_a, stack_b, log);
			continue ;
		}
		if (is_push_a_next(info, stack_b->next->index)
			|| is_push_a_prev(info, stack_b->prev->index))
		{
			log = try_push_a(info, stack_a, stack_b, log);
			continue ;
		}
		log = execute_operation(Rotate_b, stack_a, stack_b, log);
	}
	return (log);
}

t_list	*push_swap_stack_b(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
{
	while (!is_empty_stack_b(stack_b))
	{
		set_sort_info_stack_b(info, stack_b);
		log = push_a_half(info, stack_a, stack_b, log);
	}
	return (log);
}
