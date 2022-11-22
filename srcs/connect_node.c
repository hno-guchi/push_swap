/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/22 11:32:30 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	connect_node(t_dcl_list *head_p , t_dcl_list *new_node)
{
	new_node->prev = head_p;
	new_node->next = head_p->next;
	head_p->next->prev = new_node;
	head_p->next = new_node;
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int			i;
	t_dcl_list	*head_p;
	t_dcl_list	*stack_a;

	i = 0;
	head_p = create_stack_a(argc, argv);
	stack_a = head_p->next;
	while (stack_a != head_p)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	stack_clear(&head_p);
	system("leaks -q push_swap");
	return (0);
}
*/
