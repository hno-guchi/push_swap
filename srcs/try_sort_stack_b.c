/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_sort_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 12:11:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list	*try_sort_stack_b(t_sort_info *info, t_dcl_list *stack_a,
		t_dcl_list *stack_b, t_list *log)
{
	if (0 < info->stack_b_size)
	{
		if (stack_b->next->index == info->sorted)
		{
			log = execute_operation(Push_a, stack_a, stack_b, log);
			return (log);
		}
	}
	if (1 < info->stack_b_size)
	{
		if (stack_b->prev->index == info->sorted)
		{
			log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
			return (log);
		}
	}
	return (log);
}
