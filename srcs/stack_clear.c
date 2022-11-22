/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/22 11:35:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_clear(t_dcl_list **head_p)
{
	t_dcl_list	*node;
	t_dcl_list	*next_node;

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
