/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_section_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 11:17:14 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_section_size(t_sort_info *info, t_dcl_list *stack)
{
	int			section_size;
	t_dcl_list	*node;

	section_size = 0;
	node = stack->next;
	if (node == stack)
	{
		return (0);
	}
	while (info->sorted <= node->index && node->index < info->limit)
	{
		section_size += 1;
		if (node->next == stack)
		{
			break ;
		}
		node = node->next;
	}
	return (section_size);
}
