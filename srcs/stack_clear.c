/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/21 12:16:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_clear(t_bidrect_circle_list **head)
{
	t_bidrect_circle_list	*node_p;
	t_bidrect_circle_list	*next_node_p;

	if (!head[0])
	{
		return ;
	}
	node_p = head[0]->next;
	while (node_p != head[0])
	{
		next_node_p = node_p->next;
		free(node_p);
		node_p = next_node_p;
	}
	free(head[0]);
	head = NULL;
}
