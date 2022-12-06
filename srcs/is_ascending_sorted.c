/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ascending_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 18:00:00 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_ascending_sorted(t_dcl_list *head_p)
{
	int			i;
	t_dcl_list	*node;

	i = 0;
	node = head_p->next;
	while (node != head_p)
	{
		if (node->index != i)
		{
			return (false);
		}
		node = node->next;
		i += 1;
	}
	return (true);
}
