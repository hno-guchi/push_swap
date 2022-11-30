/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/30 20:25:19 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_dcl_list *head_p_stack_a, t_dcl_list *head_p_stack_b);
void	print_sort_info(t_sort_info *info, char stack);
// main.c
t_list	*try_push_a(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
bool	is_empty_stack_b(t_dcl_list *stack_b);
t_list	*try_sort_check_exist_next(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list	*try_swap_next_sort(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list	*try_sort(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);

bool	is_target_push_a(t_sort_info *info, int index)
{
	if (info->b_pivot <= index && index < info->limits[info->limits_idx - 1])
	{
		return (true);
	}
	return (false);
}

int	search_begin_idx(t_dcl_list *stack)
{
	t_dcl_list	*node;
	int			begin_idx;

	node = stack->next;
	begin_idx = 0;
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
	end_idx = 0;
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
}

t_list	*try_swap_next_sort_stack_b(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node;

	node = stack_b->next;
	if (0 < info->stack_b_size)
	{
		if ((info->sorted + 1) == node->next->index)
		{
			log = execute_operation(Swap_s, stack_a, stack_b, log);
			return (log);
		}
	}
	log = execute_operation(Swap_a, stack_a, stack_b, log);
	return (log);
}

t_list	*try_sort_until_possible(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	while (stack_a->next->index == info->sorted || stack_a->next->next->index == info->sorted)
	{
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
	}
	return (log);
}

static t_list	*try_swap2(t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
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
	log = execute_operation(operation, stack_a, stack_b, log);
	return (log);
}

bool	is_exist_over_pivot(t_sort_info *info, t_dcl_list *stack)
{
	t_dcl_list	*node;

	node = stack->next;
	if (info->stack_b_size == 0)
	{
		return (false);
	}
	while (node != stack)
	{
		if (is_target_push_a(info, node->index))
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

t_list	*push_a_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	while (is_exist_over_pivot(info, stack_b) && !is_empty_stack_b(stack_b))
	{
		// i += 1;
		// if (i == 1000)
		// 	exit(1);
		info->stack_b_size = stack_len(stack_b);
		if (1 < info->stack_b_size)
		{
			if (is_descending_sorted(stack_b, info->sorted))
			{
				log = all_push_a(stack_a, stack_b, log);
				break ;
			}
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
		if (0 < info->stack_b_size)
		{
			if (stack_b->next->index == info->sorted)
			{
				log = execute_operation(Push_a, stack_a, stack_b, log);
				continue ;
			}
		}
		if (1 < info->stack_b_size)
		{
			if (stack_b->prev->index == info->sorted)
			{
				log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
				continue ;
			}
		}
		if (stack_a->next->index == (info->sorted + 1))
		{
			if (stack_b->next->index != info->sorted)
			{
				log = execute_operation(Rotate_a, stack_a, stack_b, log);
				continue ;
			}
		}
		if (1 < info->stack_b_size)
		{
			if (stack_b->next->index == (info->sorted + 1))
			{
				log = try_push_next_sort(info, stack_a, stack_b, log);
				continue ;
			}
		}
		if (2 < info->stack_b_size)
		{
			if (stack_b->prev->index == (info->sorted + 1))
			{
				if (!is_exist_sort(info->sorted, stack_b))
				{
					log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
					continue ;
				}
			}
		}
		if ((stack_a->next->index - stack_a->next->next->index) == 1 || (stack_b->next->index - stack_b->next->next->index) == -1)
		{
			log = try_swap2(stack_a, stack_b, log);
			continue ;
		}
		if (is_target_push_a(info, stack_b->next->index))
		{
			if (2 < info->stack_b_size)
			{
				if (is_target_push_a(info, stack_b->prev->index))
				{
					if (stack_b->next->index < stack_b->prev->index)
					{
		 				log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
						continue ;
					}
				}
			}
		 	log = execute_operation(Push_a, stack_a, stack_b, log);
			continue ;
		}
		if (is_target_push_a(info, stack_b->prev->index))
		{
 			log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
			continue ;
		}
		log = execute_operation(Rotate_b, stack_a, stack_b, log);
		
	}
	return (log);
}

t_list	*sort_to_a_from_b(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	while (!is_empty_stack_b(stack_b))
	{
		set_sort_info_stack_b(info, stack_b);
		// print_sort_info(info,'b');
		// output_stack(stack_a, stack_b);
		log = push_a_half(info, stack_a, stack_b, log);
	}
	log = try_sort_until_possible(info, stack_a, stack_b, log);
	return (log);
}
