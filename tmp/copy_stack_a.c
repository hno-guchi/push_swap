/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/26 16:39:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bidrect_circle_list	*copy_stack_a(t_bidrect_circle_list *src_head_p)
{
	t_bidrect_circle_list	*tmp_stack;
	t_bidrect_circle_list	*tmp_node;
	t_bidrect_circle_list	*stack_a;

	tmp_stack = create_sentinel();
	if (!tmp_stack)
	{
		stack_clear(&src_head_p);
		exit_write_message (Malloc_error);
	}
	stack_a = src_head_p->prev;
	while (stack_a != src_head_p)
	{
		tmp_node = create_node(stack_a->num);
		if (!tmp_node)
		{
			stack_clear(&src_head_p);
			stack_clear(&tmp_stack);
			exit_write_message(Malloc_error);
		}
		connect_node(tmp_stack, tmp_node);
		stack_a = stack_a->prev;
	}
	return (tmp_stack);
}

/*
int	main(int argc, char **argv)
{
	t_bidrect_circle_list	*head_p_stack_a;
	t_bidrect_circle_list	*head_p_stack_tmp;

	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	head_p_stack_tmp = copy_stack_a(head_p_stack_a);
	output_stack(head_p_stack_a, head_p_stack_tmp);
	stack_clear(&head_p_stack_a);
	stack_clear(&head_p_stack_tmp);
	system("leaks -q push_swap");
	return (0);
}
*/
