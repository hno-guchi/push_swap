/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/10 15:15:15 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_clear(t_bidrect_circle_list **head_p)
{
	t_bidrect_circle_list	*node;
	t_bidrect_circle_list	*next_node;

	if (!head_p[0])
	{
		return ;
	}
	node = head_p[0]->next;
	while (node != head_p[0])
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(node);
	head_p = NULL;
}
