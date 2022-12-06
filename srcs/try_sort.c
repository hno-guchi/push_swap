/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 09:21:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list	*try_sort(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b
		, t_list *log)
{
	t_dcl_list	*node;

	node = stack_a->next;
	if (info->sorted == node->index)
	{
		log = execute_operation(Rotate_a, stack_a, stack_b, log);
		info->sorted += 1;
	}
	return (log);
}
