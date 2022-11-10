/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/10 18:08:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// both
bool	is_head_less_than_second(t_bidrect_circle_list *stack)
{
	return (stack->next->index < stack->next->next->index);
}

bool	is_head_less_than_tail(t_bidrect_circle_list *stack)
{
	return (stack->next->index < stack->prev->index);
}

// stack_a
bool	is_sorted_head(int sorted, int index)
{
	if (sorted != 0 && index != 0)
	{
		return (false);
	}
	return (true);
}

// stack_b
bool	is_under_b_pivot(int b_pivot, int index)
{
	return (index < b_pivot);
}
