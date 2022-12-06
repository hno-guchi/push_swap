/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_push_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 17:47:55 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
