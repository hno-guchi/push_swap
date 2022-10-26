/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/26 20:40:43 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_bidrect_circle_list *head_p_stack_a, t_bidrect_circle_list *head_p_stack_b)
{
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*stack_b;
	
	stack_a = head_p_stack_a->next;
	stack_b = head_p_stack_b->next;
	printf(" stack_a | stack_b\n");
	printf("------------------\n");
	while (stack_a != head_p_stack_a || stack_b != head_p_stack_b)
	{
		if (stack_a == head_p_stack_a)
		{
			printf("         |   [%d]\n", stack_b->num);
		}
		else if (stack_b == head_p_stack_b)
		{
			printf("   [%d]   |\n", stack_a->num);
		}
		else
		{
			printf("   [%d]   |   [%d]\n", stack_a->num, stack_b->num);
		}
		if (stack_a != head_p_stack_a)
		{
			stack_a = stack_a->next;
		}
		if (stack_b != head_p_stack_b)
		{
			stack_b = stack_b->next;
		}
	}
	printf("------------------\n");
	// printf(" [%d]     | [%d]\n", stack_a->num, stack_b->num);
}

t_list	*execute_push_swap_under_7(t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_list	*log_node;

	log_node = execute_operation(Push_b, stack_a, stack_b);
	ft_lstadd_back(&head_p_log, log_node);
	output_stack(stack_a, stack_b);

	return (head_p_log);
}

t_list	*execute_push_swap(int argc, t_bidrect_circle_list *head_p_stack_a)
{
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*head_p_stack_b;
	t_bidrect_circle_list	*stack_b;
	t_list					*head_p_log;

	stack_a = head_p_stack_a;
	head_p_stack_b = create_sentinel();
	stack_b = head_p_stack_b;
	head_p_log = NULL;
	if (argc < 7)
	{
		head_p_log = execute_push_swap_under_7(stack_a, stack_b, head_p_log);
	}
	// else
	// {
		// execute_push_swap_over_6(stack_a, stack_b, head_p_log);
	// }
	stack_clear(&head_p_stack_b);
	return (head_p_log);
}

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
	// head_p_stack_a = prepare_sort(t_bidrect_circle_list *head_p_stack_a);
						// copy_stack_a(t_bidrect_circle_list *head_p_stack_a);
						// compress(t_bidrect_circle_list *stack_a);
						// check_duplication_number(t_bidrect_circle_list *tmp_list);
	head_p_log = execute_push_swap(argc, head_p_stack_a);
	putstr_log(head_p_log);
	stack_clear(&head_p_stack_a);
	ft_lstclear(&head_p_log, NULL);
	system("leaks -q push_swap");
	return (0);
}
