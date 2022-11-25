/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_descending_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/25 16:42:21 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_descending_sorted(t_dcl_list *head_p, int begin)
{
	int			index;
	t_dcl_list	*node;

	index = begin;
	node = head_p->prev;
	while (node != head_p)
	{
		if (node->index != index)
		{
			return (false);
		}
		node = node->prev;
		index += 1;
	}
	return (true);
}
