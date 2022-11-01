/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_3_ascending.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/01 19:20:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_order	compare_3_values(int first, int second, int third)
{
	if ((first < second) && (third < second) && (first < third))
	{
		return (Min_max_mid);
	}
	else if ((second < first) && (third < first) && (third < second))
	{
		return (Max_mid_min);
	}
	else if ((second < first) && (second < third) && (first < third))
	{
		return (Mid_min_max);
	}
	else if ((second < first) && (third < first) && (second < third))
	{
		return (Max_min_mid);
	}
	else if ((first < second) && (third < second) && (third < first))
	{
		return (Mid_max_min);
	}
	return (Min_mid_max);
}

t_list	*sort_n_3_ascending(t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_bidrect_circle_list	*node;
	t_order					order;

	node = stack_a->next;
	order = compare_3_values(node->index, node->next->index,
			node->next->next->index);
	if (order == Min_max_mid || order == Max_mid_min || order == Mid_min_max)
	{
		head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
	}
	if (order == Min_max_mid || order == Max_min_mid)
	{
		head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
	}
	if (order == Max_mid_min || order == Mid_max_min)
	{
		head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b,
				head_p_log);
	}
	return (head_p_log);
}

/*
int	main(int argc, char **argv)
{
	t_bidrect_circle_list	*head_p_stack_a;
	t_list					*head_p_log;

	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	head_p_stack_a = prepare_sort(argc - 1, &argv[1], head_p_stack_a);
	head_p_log = execute_push_swap(argc - 1, head_p_stack_a);
	putstr_log(head_p_log);
	stack_clear(&head_p_stack_a);
	ft_lstclear(&head_p_log, NULL);
	//system("leaks -q push_swap");
	return (0);
}
*/
