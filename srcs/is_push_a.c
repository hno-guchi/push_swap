/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 17:09:00 by hnoguchi         ###   ########.fr       */
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

bool	is_push_a(t_sort_info *info, t_dcl_list *stack)
{
	if (is_push_a_next(info, stack->next->index))
	{
		return (true);
	}
	if (is_push_a_prev(info, stack->prev->index))
	{
		return (true);
	}
	return (false);
}
