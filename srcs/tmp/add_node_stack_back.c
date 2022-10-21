/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_stack_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/20 15:29:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_stack_back(t_bidrect_circle_list **stack
		, t_bidrect_circle_list *new)
{
	t_bidrect_circle_list	*last_node;

	if (!new)
	{
		return ;
	}
	if (!stack[0])
	{
		stack[0] = new;
	}
	else
	{
		last_node = stack_last(stack[0]);
		last_node->next = new;
		new->prev = last_node;
	}
}

/*
int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	(void)argc;
	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		if (is_atoi(argv[i]))
		{
			add_node_stack_back(&stack_a, create_node(ft_atoi(argv[i])));
		}
		else
		{
			stack_clear(&stack_a);
			exit_write_message(Not_int);
		}
		i += 1;
	}
	 i = 0;
	while (stack_a->next)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	stack_clear(&stack_a);
	// execute_push_swap
	//
	system("leaks -q push_swap");
	return (0);
}

*/
