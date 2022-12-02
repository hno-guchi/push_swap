/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_complete_sort_section.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 14:14:39 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_complete_sort_section(t_sort_info *info, t_dcl_list *stack)
{
	int			count;
	t_dcl_list	*node;

	count = 0;
	node = stack->next;
	if (stack == node)
	{
		return (true);
	}
	while (node->index < info->limit)
	{
		if (node->index == 0)
		{
			break ;
		}
		count += 1;
		node = node->next;
	}
	if (count == 0)
	{
		return (true);
	}
	return (false);
}
