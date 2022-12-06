/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_sort_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 17:50:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
