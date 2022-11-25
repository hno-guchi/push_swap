/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/25 16:36:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_swap_under_7(int n, t_dcl_list *stack_a
	, t_dcl_list *stack_b, t_list *head_p_log)
{
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
