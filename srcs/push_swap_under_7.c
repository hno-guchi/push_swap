/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/02 19:48:21 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_swap_under_7(int n, t_bidrect_circle_list *stack_a
	, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	/*
	if (is_ascending_sorted(stack_a) || n == 1)
	{
		return (NULL);
	}
	else if (n < 4)
	*/
	if (n < 4)
	{
		head_p_log = sort_n_under_4(n, stack_a, stack_b, head_p_log);
	}
	else
	{
		head_p_log = sort_n_under_7(n, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}
