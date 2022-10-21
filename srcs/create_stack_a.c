/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/21 13:57:41 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_bidrect_circle_list	*create_sentinel(void)
{
	t_bidrect_circle_list	*sentinel;

	sentinel = (t_bidrect_circle_list *)malloc(sizeof(t_bidrect_circle_list));
	if (!sentinel)
	{
		return (NULL);
	}
	sentinel->num = 0;
	sentinel->index = 0;
	sentinel->prev = sentinel;
	sentinel->next = sentinel;
	return (sentinel);
}

static void	connect_node(t_bidrect_circle_list *head_p
		,t_bidrect_circle_list *new_node)
{
	new_node->prev = head_p;
	new_node->next = head_p->next;
	head_p->next->prev = new_node;
	head_p->next = new_node;
}

t_bidrect_circle_list	*create_stack_a(int argc, char **argv)
{
	int						i;
	t_bidrect_circle_list	*head_p;
	t_bidrect_circle_list	*new_node;

	i = 1;
	head_p = create_sentinel();
	if (!head_p)
	{
		exit_write_message (Malloc_error);
	}
	while (i < argc)
	{
		new_node = create_node(ft_atoi(argv[i]));
		if (!new_node)
		{
			stack_clear(&head_p);
			exit_write_message(Malloc_error);
		}
		connect_node(head_p, new_node);
		i += 1;
	}
	return (head_p);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int						i;
	t_bidrect_circle_list	*head_p;
	t_bidrect_circle_list	*stack_a;

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
