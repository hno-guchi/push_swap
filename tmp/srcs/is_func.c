/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/11 19:10:14 by hnoguchi         ###   ########.fr       */
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

/*
bool	is_n_descending_sort(t_bidrect_circle_list *stack, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (stack->index != (stack->next->index + 1))
		{
			return (false);
		}
		i += 1;
		stack = stack->next;
	}
	return (stack->index == (stack->next->index + 1));
}
*/

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
