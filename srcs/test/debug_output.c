/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/06 18:13:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	output_stack(t_dcl_list *head_p_stack_a, t_dcl_list *head_p_stack_b)
{
	t_dcl_list	*stack_a;
	t_dcl_list	*stack_b;

	stack_a = head_p_stack_a->next;
	stack_b = head_p_stack_b->next;
	printf(" stack_a    |  stack_b\n");
	printf("------------------------------------------------------\n");
	while (stack_a != head_p_stack_a || stack_b != head_p_stack_b)
	{
		if (stack_a == head_p_stack_a)
			printf("         |   [%3d]\n", stack_b->index);
		else if (stack_b == head_p_stack_b)
			printf(" [%3d]   |\n", stack_a->index);
		else
			printf(" [%3d]   |   [%3d]\n", stack_a->index, stack_b->index);
		if (stack_a != head_p_stack_a)
			stack_a = stack_a->next;
		if (stack_b != head_p_stack_b)
			stack_b = stack_b->next;
	}
	printf("------------------------------------------------------\n");
}

void	print_sort_info(t_sort_info *info, char stack)
{
	int	i;

	i = 0;
	printf("stack [%c] info\n", stack);
	printf("-----------------------------------\n");
	printf("info->size         : [%4d]\n", info->size);
	printf("info->sorted       : [%4d]\n", info->sorted);
	printf("info->limits_idx   : [%4d]\n", info->limits_idx);
	printf("info->limits[]     : ");
	while (info->limits[i] != 0)
	{
		printf("[%d]", info->limits[i]);
		i += 1;
		if (i < info->limits[i] != 0)
		{
			printf("-> ");
		}
	}
	printf("\n");
	printf("info->limit        : [%4d]\n", info->limit);
	printf("info->section_size : [%4d]\n", info->section_size);
	printf("info->a_pivot      : [%4d]\n", info->a_pivot);
	printf("info->b_pivot      : [%4d]\n", info->b_pivot);
	printf("info->stack_b_size : [%4d]\n", info->stack_b_size);
	printf("-----------------------------------\n");
}
