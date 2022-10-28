/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/28 19:44:44 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_bidrect_circle_list *head_p_stack_a
		, t_bidrect_circle_list *head_p_stack_b)
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

bool	is_sorted(t_bidrect_circle_list *head_p)
{
	int						i;
	t_bidrect_circle_list	*node;

	i = 0;
	node = head_p->next;
	while (node != head_p)
	{
		if (node->index != i)
		{
			return (false);
		}
		node = node->next;
		i += 1;
	}
	return (true);
}

int	select_median(int size)
{
	int	median;

	median = 0;
	if ((size % 2) == 0)
	{
		median = (size / 2) - 1;
	}
	else
	{
		median = (size - 1) / 2;
	}
	return (median);
}

t_list	*execute_push_swap_under_7(int size, t_bidrect_circle_list *stack_a
	, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	int						median_index;
	t_bidrect_circle_list	*node;
	t_list					*log_node;

	if (is_sorted(stack_a))
	{
		return (NULL);	
	}
	median_index = select_median(size);
	node = stack_a->next;
	while (1)
	{
		if ((node->index - node->next->index) == 1)
		{
			log_node = execute_operation(Swap_a, stack_a, stack_b);
			ft_lstadd_back(&head_p_log, log_node);
		}
		if ((node->index - node->next->index) == -1)
		{
			if (node->index <= median_index)
			{
				log_node = execute_operation(Push_b, stack_a, stack_b);
				ft_lstadd_back(&head_p_log, log_node);
			}
		}

		if (is_sorted(stack_a))
		{
			break ;
		}
	}
	// output_stack(stack_a, stack_b);
	return (head_p_log);
}

t_list	*execute_push_swap(int stack_size, t_bidrect_circle_list *head_p_stack_a)
{
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*head_p_stack_b;
	t_bidrect_circle_list	*stack_b;
	t_list					*head_p_log;

	stack_a = head_p_stack_a;
	head_p_stack_b = create_sentinel();
	stack_b = head_p_stack_b;
	head_p_log = NULL;
	if (stack_size < 7)
	{
		head_p_log = execute_push_swap_under_7(stack_size, stack_a, stack_b, head_p_log);
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
	// t_stack_info			stack_a_info;
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
	system("leaks -q push_swap");
	return (0);
}
