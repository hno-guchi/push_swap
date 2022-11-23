/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_first_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/23 20:46:32 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*try_2(t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
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

t_list	*try(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	t_operation	operation;
	t_operation	a;
	t_operation	b;

	operation = Not;
	a = Not;
	b = Not;
	if (info->a_pivot <= stack_a->next->index)
	{
		a = Rotate_a;
	}
	if (1 < info->pushed && stack_b->next->index < info->b_pivot)
	{
		b = Rotate_b;
	}
	if (a == Rotate_a && b == Rotate_b)
	{
		operation = Rotate_r;
	}
	else if (a == Rotate_a && b != Rotate_b)
	{
		operation = a;
	}
	else if (a != Rotate_a && b == Rotate_b)
	{
		operation = b;
	}
	head_p_log = execute_operation(operation, stack_a, stack_b, head_p_log);
	return (head_p_log);
}

t_list	*split_first_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	// int	cycle = 0;

	info->a_pivot = calculate_median(info->size);
	info->b_pivot = calculate_median(info->a_pivot);
	while (1)
	{
		// print_ranges_info(info, 'a');
		// output_stack(stack_a, stack_b);
		// if (is_finish(info->pushed, info->a_pivot))
		if (info->pushed == info->a_pivot)
		{
			break ;
		}
		if (stack_a->next->index < info->a_pivot)
		{
			head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
			info->pushed += 1;
		}
		head_p_log = try(info, stack_a, stack_b, head_p_log);
		head_p_log = try_2(stack_a, stack_b, head_p_log);
		// putstr_log(head_p_log);
		// output_stack(stack_a, stack_b);

	}
	// cycle += 1;
	// if (cycle == 1000)
	// {
	// 	exit(1);
		// return (head_p_log);
	// }
	return (head_p_log);
}
