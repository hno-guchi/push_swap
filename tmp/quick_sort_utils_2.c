/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:35:42 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/27 19:01:37 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_sort.h"

void	add_data_index_stack(t_stack_sort_range *stack, int begin, int end)
{
	if (stack->list_size <= stack->present_index_stack_begin
		|| stack->list_size <= stack->present_index_stack_end)
	{
		return ;
	}
	stack->stack_begin_index[stack->present_index_stack_begin] = begin;
	stack->stack_end_index[stack->present_index_stack_end] = end;
	stack->present_index_stack_begin += 1;
	stack->present_index_stack_end += 1;
}

bool	is_empty_stack(t_stack_sort_range *stack)
{
	if (stack->present_index_stack_begin <= 0
		&& stack->present_index_stack_end <= 0)
	{
		return (true);
	}
	return (false);
}

int	get_data_stack_begin_index(t_stack_sort_range *stack)
{
	if (is_empty_stack(stack))
	{
		return (-1);
	}
	stack->present_index_stack_begin -= 1;
	return (stack->stack_begin_index[stack->present_index_stack_begin]);
}

int	get_data_stack_end_index(t_stack_sort_range *stack)
{
	if (is_empty_stack(stack))
	{
		return (-1);
	}
	stack->present_index_stack_end -= 1;
	return (stack->stack_end_index[stack->present_index_stack_end]);
}
