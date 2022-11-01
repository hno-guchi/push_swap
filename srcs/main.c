/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/01 20:11:59 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_bidrect_circle_list *head_p_stack_a
		, t_bidrect_circle_list *head_p_stack_b);

bool	is_descending_sorted(t_bidrect_circle_list *head_p)
{
	int						i;
	t_bidrect_circle_list	*node;

	i = 0;
	node = head_p->prev;
	while (node != head_p)
	{
		if (node->index != i)
		{
			return (false);
		}
		node = node->prev;
		i += 1;
	}
	return (true);
}
bool	is_ascending_sorted(t_bidrect_circle_list *head_p)
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
		median = (size / 2);
	}
	else
	{
		median = (size - 1) / 2;
	}
	return (median);
}

t_list	*push_b_until_stack_a_n_3(int size
	, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b
	, t_list *head_p_log)
{
	int						i;
	int						median_index;
	t_bidrect_circle_list	*node;

	median_index = select_median(size);

	i = 0;
	while (i < (size - 3))
	{
		node = stack_a->next;
		if (node->index < median_index)
		{
			head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
			i += 1;
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	return (head_p_log);
}

t_list	*sort_n_2_stack_b_descending(t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_bidrect_circle_list	*node;

	node = stack_b->next;
	if (node->index < node->next->index)
	{
		head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}

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

t_list	*sort_n_3_stack_b_descending(t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_bidrect_circle_list	*node;
	t_order					order;

	node = stack_b->next;
	order = compare_3_values(node->index, node->next->index,
			node->next->next->index);
	if (order == Min_mid_max || order == Max_min_mid || order == Mid_max_min)
	{
		head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
	}
	if (order == Max_min_mid || order == Min_max_mid)
	{
		head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
	}
	if (order == Min_mid_max || order == Mid_min_max)
	{
		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b,
				head_p_log);
	}
	return (head_p_log);
}

t_list	*sort_n_under_7(int size
	, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b
	, t_list *head_p_log)
{
	head_p_log = push_b_until_stack_a_n_3(size, stack_a, stack_b, head_p_log);
	// head_p_log = sort_stack_a_and_b(size - 3, stack_a, stack_b, head_p_log);
	if (!is_ascending_sorted(stack_a))
	{
		head_p_log = sort_n_3_ascending(stack_a, stack_b, head_p_log);
	}
	if ((size - 3) == 2)
	{
		head_p_log = sort_n_2_stack_b_descending(stack_a, stack_b, head_p_log);
	}
	else if ((size - 3) == 3)
	{
		if (!is_descending_sorted(stack_b))
		{
			head_p_log = sort_n_3_stack_b_descending(stack_a, stack_b, head_p_log);
		}
	}
	// head_p_log = push_a_and_swap_a(stack_a, stack_b, head_p_log);
	return (head_p_log);
}

t_list	*execute_push_swap_under_7(int size, t_bidrect_circle_list *stack_a
	, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	if (is_ascending_sorted(stack_a) || size == 1)
	{
		return (NULL);	
	}
	if (size == 2)
	{
		head_p_log = sort_n_2_ascending(stack_a, stack_b, head_p_log);
	}
	else if (size == 3)
	{
		head_p_log = sort_n_3_ascending(stack_a, stack_b, head_p_log);
	}
	else
	{
		head_p_log = sort_n_under_7(size, stack_a, stack_b, head_p_log);
	}
	output_stack(stack_a, stack_b);
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
			printf("         |   [%4d]\n", stack_b->num);
		}
		else if (stack_b == head_p_stack_b)
		{
			printf("   [%4d]   |\n", stack_a->num);
		}
		else
		{
			printf("   [%4d]   |   [%4d]\n", stack_a->num, stack_b->num);
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
