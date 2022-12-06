/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_swap_next_sort_stack_b.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 10:15:25 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list	*try_swap_next_sort_stack_b(t_sort_info *info, t_dcl_list *stack_a
		, t_dcl_list *stack_b, t_list *log)
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
