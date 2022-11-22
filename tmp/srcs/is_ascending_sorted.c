/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ascending_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/02 11:06:35 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_ascending_sorted(t_bidrect_circle_list *head_p)
{
	int						i;
	t_bidrect_circle_list	*node;

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
