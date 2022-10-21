/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/21 13:51:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bidrect_circle_list	*create_node(int num)
{
	t_bidrect_circle_list	*new_node;

	new_node = (t_bidrect_circle_list *)malloc(sizeof(t_bidrect_circle_list));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->num = num;
	new_node->index = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>
#include "../libft/includes/libft.h"
int	main(int argc, char **argv)
{
	t_stack	*new_node;

	new_node = create_node(ft_atoi(argv[argc - 1]));
	printf("[%p]\n", new_node);
	printf("[%d]\n", *new_node->num);
	free(new_node);
	system("leaks -q a.out");
	return (0);
}
*/
