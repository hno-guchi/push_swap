/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_first_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/01 18:31:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define HEAD_SORTED 0

// main.c
t_list	*try_sort_stack_b(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
t_list	*try_sort_check_exist_next(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);
bool	is_sort_stack_b(t_sort_info *info, t_dcl_list *stack_b);

bool	is_swap_b(t_sort_info *info, t_dcl_list *stack)
{
	if (1 < info->stack_b_size)
	{
		if ((stack->next->index - stack->next->next->index) == -1)
		{
			return (true);
		}
	}
	return (false);
}

bool	is_swap_a(t_sort_info *info, t_dcl_list *stack)
{
	if ((stack->next->index - stack->next->next->index) == 1)
	{
		if (info->b_pivot <= stack->next->index && info->b_pivot <= stack->next->next->index)
		{
			return (true);
		}
	}
	return (false);
}

t_operation	judge_operation_swap(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b)
{
	if (is_swap_a(info, stack_a) && is_swap_b(info, stack_b))
	{
		return (Swap_s);
	}
	else if (is_swap_a(info, stack_a) && !is_swap_b(info, stack_b))
	{
		return (Swap_a);
	}
	else if (!is_swap_a(info, stack_a) && is_swap_b(info, stack_b))
	{
		return (Swap_b);
	}
	return (Not);
}

t_list	*try_swap(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_operation	operation;

	operation = judge_operation_swap(info, stack_a, stack_b);
	log = execute_operation(operation, stack_a, stack_b, log);
	return (log);
}

static t_list	*try_rotate_under_b_pivot(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_operation	operation;

	operation = Rotate_b;
	if (info->a_pivot <= stack_a->next->index)
	{
		operation = Rotate_r;
	}
	log = execute_operation(operation, stack_a, stack_b, log);
	return (log);
}

bool	is_under_pivot_b(t_sort_info *info, t_dcl_list *stack)
{
	if (1 < info->stack_b_size)
	{
		if (stack->next->index < info->b_pivot)
		{
			return (true);
		}
	}
	return (false);
}

t_list	*split_first_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	int	pushed;

	pushed = 0;
	while (pushed != info->a_pivot)
	{
		// i += 1;
		// if (i == 1000)
		// 	exit(1);
		// print_ranges_info(info, 'a');
		// output_stack(stack_a, stack_b);
		info->stack_b_size = stack_len(stack_b);
		if (is_swap_a(info, stack_a) || is_swap_b(info, stack_b))
		{
			log = try_swap(info, stack_a, stack_b, log);
			continue ;
		}
		if (stack_a->next->index < info->a_pivot)
		{
			log = execute_operation(Push_b, stack_a, stack_b, log);
			pushed += 1;
			if (is_under_pivot_b(info, stack_b))
			{
				log = try_rotate_under_b_pivot(info, stack_a, stack_b, log);
			}
			continue ;
		}
		log = execute_operation(Rotate_a, stack_a, stack_b, log);
		// putstr_log(log);
		// output_stack(stack_a, stack_b);
	}
	return (log);
}

t_list	*split_second_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	info->b_pivot = calculate_median(info->sorted + info->a_pivot);
	while (stack_a->next->index != HEAD_SORTED)
	{
		// i += 1;
		// if (i == 1000)
		// 	exit(1);
		// print_ranges_info(info, 'a');
		// output_stack(stack_a, stack_b);
		info->stack_b_size = stack_len(stack_b);
		if (stack_a->next->index == info->sorted)
		{
			log = try_sort_check_exist_next(info, stack_a, stack_b, log);
			continue ;
		}
		if (is_sort_stack_b(info, stack_b))
		{
			log = try_sort_stack_b(info, stack_a, stack_b, log);
			continue ;
		}
		if (stack_a->next->index == (info->sorted + 1))
		{
			log = execute_operation(Rotate_a, stack_a, stack_b, log);
			continue ;
		}
		if (is_swap_a(info, stack_a) || is_swap_b(info, stack_b))
		{
			log = try_swap(info, stack_a, stack_b, log);
			continue ;
		}
		log = execute_operation(Push_b, stack_a, stack_b, log);
		if (is_under_pivot_b(info, stack_b))
		{
			log = execute_operation(Rotate_b, stack_a, stack_b, log);
		}
		// putstr_log(log);
		// output_stack(stack_a, stack_b);
	}
	return (log);
}
