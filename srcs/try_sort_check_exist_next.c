/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_sort_check_exist_next.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 12:15:56 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// push_swap_stack_a.c
t_list	*try_sort(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);

static t_list	*try_reverse_rotate_check_exist_next(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node;
	int			stack_size;

	node = stack_b->prev;
	stack_size = stack_len(stack_b);
	if (1 < stack_size)
	{
		if ((info->sorted + 2) == node->index)
		{
			log = execute_operation(Reverse_rotate_r, stack_a, stack_b, log);
			return (log);
		}
	}
	log = execute_operation(Reverse_rotate_a, stack_a, stack_b, log);
	return (log);
}

t_list	*try_sort_check_exist_next(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node;

	node = stack_a->prev;
	if ((info->sorted + 1) == node->index)
	{
		log = try_reverse_rotate_check_exist_next(info, stack_a, stack_b, log);
		log = execute_operation(Swap_a, stack_a, stack_b, log);
	}
	log = try_sort(info, stack_a, stack_b, log);
	return (log);
}
