/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/20 16:15:20 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_clear(t_bidrect_circle_list **stack)
{
	t_bidrect_circle_list	*next_node;

	if (!stack[0])
	{
		return ;
	}
	while (stack[0]->role != SENTINEL)
	{
		next_node = stack[0]->next;
		free(stack[0]);
		stack[0] = next_node;
	}
	free(stack[0]);
	stack = NULL;
}
