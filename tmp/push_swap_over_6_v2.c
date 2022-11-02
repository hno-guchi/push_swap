/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_over_6_v2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/02 20:05:09 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_bidrect_circle_list *head_p_stack_a,
			t_bidrect_circle_list *head_p_stack_b);

int	calculate_median(int size)
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

int	set_range_push_b(int sorted, int median, int stack_size)
{
	if (sorted < median)
	{
		return (median);
	}
	return (stack_size);
}

int	set_range_rotate_b(int sorted, int median)
{
	int	first_quartile_index;
	int	third_quartile_index;

	first_quartile_index = calculate_median(median);
	third_quartile_index = median + first_quartile_index;
	if (sorted < median)
	{
		return (first_quartile_index);
	}
	return (third_quartile_index);
}

t_list	*push_a_and_rotate_a(t_bidrect_circle_list *stack_a,
			t_bidrect_circle_list *stack_b, t_list *head_p_log, int *sorted)
{
	t_bidrect_circle_list	*node;

	node = stack_b->next;
	while (node != stack_b)
	{
		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
		if (node->index == *sorted)
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
					head_p_log);
			*sorted += 1;
		}
		node = stack_b->next;
	}
	return (head_p_log);
}

typedef struct	s_sort_range_index {
	int	stack_a_size;
	int	sorted;
	int	median;
	int	push_b;
	int	rotate_b;
	int	cycle;
}	t_sort_range_index;

t_list	*push_swap_over_6(int n, t_bidrect_circle_list *stack_a,
			t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_sort_range_index	ranges;

	// initialize_ranges(t_sort_range_index *ranges);
	ranges.stack_a_size = n;
	ranges.sorted = 0;
	ranges.median = calculate_median(n);
	ranges.cycle = 0;
	
	// First cycle
	// head_p_log = first_push_swap_func(ranges, stack_a, stack_b, head_p_log);
	int	count_stack_b_node;

	count_stack_b_node = 0;
	ranges.push_b = set_range_push_b(ranges.sorted, ranges.median, ranges.stack_a_size);
	ranges.rotate_b = set_range_rotate_b(ranges.sorted, ranges.median);
	while (count_stack_b_node < (ranges.push_b - ranges.sorted))
	{
		if (stack_a->next->index < ranges.push_b)
		{
			head_p_log = execute_operation(Push_b, stack_a, stack_b,
					head_p_log);
			count_stack_b_node += 1;
			if (1 < count_stack_b_node)
			{
				if (stack_b->next->index < ranges.rotate_b)
				{
					head_p_log = execute_operation(Rotate_b, stack_a, stack_b,
							head_p_log);
				}
			}
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
					head_p_log);
		}
	}
	head_p_log = push_a_and_rotate_a(stack_a, stack_b, head_p_log, &ranges.sorted);

	// Second cicle
	if (is_ascending_sorted(stack_a))
	{
		return (head_p_log);
	}
	while (ranges.sorted != ranges.stack_a_size)
	{
		count_stack_b_node = 0;
		ranges.push_b = set_range_push_b(ranges.sorted, ranges.median, ranges.stack_a_size);
		ranges.rotate_b = set_range_rotate_b(ranges.sorted, ranges.median);
		while (count_stack_b_node < (ranges.push_b - ranges.sorted))
		{
			if (stack_a->next->index == ranges.sorted)
			{
				head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
						head_p_log);
				ranges.sorted += 1;
			}
			else if (stack_a->next->index < ranges.push_b)
			{
				head_p_log = execute_operation(Push_b, stack_a, stack_b,
						head_p_log);
				count_stack_b_node += 1;
				if (1 < count_stack_b_node)
				{
					if (stack_b->next->index < ranges.rotate_b)
					{
						head_p_log = execute_operation(Rotate_b, stack_a, stack_b,
								head_p_log);
					}
				}
			}
			else
			{
				head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
						head_p_log);
			}
		}
		head_p_log = push_a_and_rotate_a(stack_a, stack_b, head_p_log, &ranges.sorted);
	}
	// output_stack(stack_a, stack_b);
	return (head_p_log);
}

t_list	*push_swap(int stack_size, t_bidrect_circle_list *head_p_stack_a)
{
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*head_p_stack_b;
	t_bidrect_circle_list	*stack_b;
	t_list					*head_p_log;

	stack_a = head_p_stack_a;
	head_p_stack_b = create_sentinel();
	stack_b = head_p_stack_b;
	head_p_log = NULL;
	if (is_ascending_sorted(stack_a) || stack_size == 1)
	{
		return (NULL);
	}
	if (stack_size < 7)
	{
		head_p_log = push_swap_under_7(stack_size, stack_a, stack_b,
				head_p_log);
	}
	else
	{
		head_p_log = push_swap_over_6(stack_size, stack_a, stack_b,
				head_p_log);
	}
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
	head_p_log = push_swap(argc - 1, head_p_stack_a);
	putstr_log(head_p_log);
	stack_clear(&head_p_stack_a);
	ft_lstclear(&head_p_log, NULL);
	// system("leaks -q push_swap");
	return (0);
}

void	output_stack(t_bidrect_circle_list *head_p_stack_a,
			t_bidrect_circle_list *head_p_stack_b)
{
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*stack_b;

	stack_a = head_p_stack_a->next;
	stack_b = head_p_stack_b->next;
	printf(" stack_a  | stack_b\n");
	printf("----------------------\n");
	while (stack_a != head_p_stack_a || stack_b != head_p_stack_b)
	{
		if (stack_a == head_p_stack_a)
		{
			// printf("         |   [%4d]\n", stack_b->num);
			printf("         |   [%4d]\n", stack_b->index);
		}
		else if (stack_b == head_p_stack_b)
		{
			// printf(" [%4d]   |\n", stack_a->num);
			printf(" [%4d]   |\n", stack_a->index);
		}
		else
		{
			// printf(" [%4d]   |   [%4d]\n", stack_a->num, stack_b->num);
			printf(" [%4d]   |   [%4d]\n", stack_a->index, stack_b->index);
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
	printf("----------------------\n");
}
