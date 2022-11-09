/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/09 20:08:05 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_bidrect_circle_list *head_p_stack_a,
			t_bidrect_circle_list *head_p_stack_b);
void	print_ranges_info(t_sort_range_index *ranges, char stack);

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

void	initialize_ranges(t_sort_range_index *ranges, int stack_size)
{
	ranges->count_sorted = 0;
	ranges->begin = 0;
	ranges->end = stack_size;
	ranges->a_pivot = calculate_median(ranges->begin + ranges->end);
	ranges->b_pivot = 0;
	ranges->median = ranges->a_pivot;
	ranges->count_pushed = 0;
	ranges->cycle = 0;
}

void	set_ranges_stack_a(t_sort_range_index *ranges, int stack_size)
{
	ranges->end = stack_size;
	ranges->count_pushed = 0;
	if (ranges->median <= ranges->count_sorted)
	{
		ranges->begin = ranges->median;
		ranges->b_pivot = calculate_median(ranges->begin + ranges->end);
	}
	else
	{
		ranges->begin = 0;
		ranges->b_pivot = calculate_median(ranges->begin + ranges->a_pivot);
	}
}

bool	is_empty_stack_b(t_bidrect_circle_list *stack_b)
{
	t_bidrect_circle_list	*node;

	node = stack_b->next;
	if (node == stack_b)
	{
		return (true);
	}
	return (false);
}

void	set_ranges_stack_b(t_sort_range_index *ranges,
		t_bidrect_circle_list *stack_b)
{
	t_bidrect_circle_list	*node;

	node = stack_b->next;
	ranges->end = node->index;
	while (node != stack_b)
	{
		if (ranges->end < node->next->index)
		{
			ranges->end = node->next->index;
		}
		node = node->next;
	}
	ranges->end += 1;
	if (ranges->end - ranges->begin < 4)
	{
		ranges->b_pivot = 0;
		ranges->count_pushed = ranges->begin;
	}
	else
	{
		ranges->b_pivot = calculate_median(ranges->begin + ranges->end);
		ranges->count_pushed = ranges->b_pivot;
	}
}

t_list	*split_half(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a,
		t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	ranges->b_pivot = calculate_median(ranges->begin + ranges->a_pivot);
	while (1)
	{
		if (ranges->count_pushed == ranges->a_pivot)
		{
			break ;
		}
		head_p_log = try_rotate(ranges, stack_a, stack_b, head_p_log);
		head_p_log = try_swap(ranges, stack_a, stack_b, head_p_log);
		if (stack_a->prev->index < ranges->a_pivot || stack_a->next->index < ranges->a_pivot)
		{
			if (stack_a->prev->index < ranges->a_pivot)
			{
				head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
			}
			head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
		}
		else
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
		}
	}
	return (head_p_log);
}

t_list	*sort_under_median(t_sort_range_index *ranges,
		t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b,
		t_list *head_p_log)
{
	while (1)
	{
		if ((ranges->a_pivot - ranges->count_sorted) <= ranges->count_pushed)
		{
			break ;
		}
		if (is_sort(ranges->count_sorted, stack_a->next->index) || is_sort(ranges->count_sorted, stack_a->next->next->index))
		// if (is_sort(ranges->count_sorted, stack_a->next->index))
		{
			head_p_log = try_sort(ranges, stack_a, stack_b, head_p_log);
			ranges->count_sorted += 1;
			continue ;
		}
		if (is_rotate_b(ranges, stack_b->next->index))
		{
			head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
		}
		head_p_log = try_swap(ranges, stack_a, stack_b, head_p_log);
		if (stack_a->next->index < ranges->a_pivot)
		{
			head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
		}
	}
	return (head_p_log);
}

t_list	*sort_over_median(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	while (1)
	{
		if (ranges->count_sorted + ranges->count_pushed == ranges->end)
		{
			break ;
		}
		if (is_sort(ranges->count_sorted, stack_a->next->index) || is_sort(ranges->count_sorted, stack_a->next->next->index))
		// if (is_sort(ranges->count_sorted, stack_a->next->index))
		{
			head_p_log = try_sort(ranges, stack_a, stack_b, head_p_log);
			ranges->count_sorted += 1;
			continue ;
		}
		if (is_rotate_b(ranges, stack_b->next->index))
		{
			head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
		}
		head_p_log = try_swap(ranges, stack_a, stack_b, head_p_log);
		if (ranges->a_pivot <= stack_a->next->index)
		{
			head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
		}
	}
	return (head_p_log);
}

t_list	*push_a_half(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	while (1)
	{
		if (ranges->count_pushed == ranges->end)
		{
			break;
		}
		// print_ranges_info(ranges, 'b');
		// output_stack(stack_a, stack_b);
		if (3 < (ranges->end - ranges->count_pushed) && ranges->b_pivot <= stack_b->prev->index)
		{
			if (stack_b->next->index < stack_b->prev->index)
			{
				head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			}
		}
		//if (ranges->b_pivot <= stack_b->prev->index)
		//{
		if (stack_b->next->index < stack_b->next->next->index)
		{
			head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
		}
		// }
		if (is_swap_a(ranges->count_sorted, stack_a) || is_swap_b(2, stack_b))
		{
			if (is_swap_a(ranges->count_sorted, stack_a) && is_swap_b(2, stack_b))
			{
				head_p_log = execute_operation(Swap_s, stack_a, stack_b, head_p_log);
			}
			else if (is_swap_a(ranges->count_sorted, stack_a))
			{
				head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
			}
			else if (is_swap_b(2, stack_b))
			{
				head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
			}
		}
		// if (ranges->b_pivot <= stack_b->next->index)
		if (ranges->b_pivot <= stack_b->next->index || ranges->b_pivot <= stack_b->prev->index)
		{
			if (ranges->b_pivot <= stack_b->next->index && ranges->b_pivot <= stack_b->prev->index)
			{
				if (stack_b->next->index < stack_b->prev->index)
				{
					head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
					head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
				}
				else
				{
					head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
				}
			}
			else if (ranges->b_pivot <= stack_b->next->index)
			{
					head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			}
			else if (ranges->b_pivot <= stack_b->prev->index)
			{
				head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
				head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
			}
			ranges->count_pushed += 1;
		}
		else
		{
			if (is_sort(ranges->count_sorted, stack_a->next->index))
			{
				head_p_log = execute_operation(Rotate_r, stack_a, stack_b, head_p_log);
				ranges->count_sorted += 1;
			}
			else
			{
				head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
			}
		}
		// putstr_log(head_p_log);
		// output_stack(stack_a, stack_b);
	}
	return (head_p_log);
}

t_list	*push_swap_over_6(int n, t_bidrect_circle_list *stack_a,
			t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_list	*log = NULL;
	t_sort_range_index	ranges;

	initialize_ranges(&ranges, n);
	while (1)
	{
		if (is_ascending_sorted(stack_a))
		{
			return (head_p_log);
		}
		set_ranges_stack_a(&ranges, n);
		// print_ranges_info(&ranges, 'a');
		// head_p_log = push_swap_stack_a(&range, stack_a, stack_b, head_p_log);
		if (ranges.cycle == 0)
		{
			head_p_log = split_half(&ranges, stack_a, stack_b, head_p_log);
			// log = NULL;
			// log = split_half(&ranges, stack_a, stack_b, log);
			// output_stack(stack_a, stack_b);
			// putstr_log(log);
			// ft_lstadd_back(&head_p_log, log);
		}
		else if (ranges.count_sorted < ranges.median)
		{
			// output_stack(stack_a, stack_b);
			head_p_log = sort_under_median(&ranges, stack_a, stack_b, head_p_log);
			// log = NULL;
			// log = sort_under_median(&ranges, stack_a, stack_b, log);
			// putstr_log(log);
			// output_stack(stack_a, stack_b);
			// ft_lstadd_back(&head_p_log, log);
		}
		else if (ranges.median <= ranges.count_sorted)
		{
			output_stack(stack_a, stack_b);
			// head_p_log = sort_over_median(&ranges, stack_a, stack_b, head_p_log);
			log = NULL;
			log = sort_over_median(&ranges, stack_a, stack_b, log);
			putstr_log(log);
			output_stack(stack_a, stack_b);
			ft_lstadd_back(&head_p_log, log);
		}
		ranges.begin = ranges.count_sorted;
		// head_p_log = push_swap_stack_b(&range, stack_a, stack_b, head_p_log);
		while (1)
		{
			if (is_empty_stack_b(stack_b))
			{
				// output_stack(stack_a, stack_b);
				// putstr_log(log);
				break ;
			}
			set_ranges_stack_b(&ranges, stack_b);
			head_p_log = push_a_half(&ranges, stack_a, stack_b, head_p_log);
			// print_ranges_info(&ranges, 'b');
			// log = NULL;
			// log = push_a_half(&ranges, stack_a, stack_b, log);
			// output_stack(stack_a, stack_b);
			// putstr_log(log);
			// ft_lstadd_back(&head_p_log, log);
		}
		ranges.cycle += 1;
		// if (ranges.cycle == 1)
		// {
		//	return (head_p_log);
		// }
	}
	return (head_p_log);
}

// 1: begin_idx ~ end_idx; (0 ~ 25)[25] stack_b_pivot; [12] -> push_a (12 ~ 24)[13]
// 2: begin_idx ~ end_idx; (0 ~ 12)[12] stack_b_pivot; [ 6] -> push_a ( 6 ~ 11)[ 6]
// 3: begin_idx ~ end_idx; (0 ~  6)[ 6] stack_b_pivot; [ 3] -> push_a ( 3 ~  5)[ 3]
// 4: begin_idx ~ end_idx; (0 ~  3)[ 3] stack_b_pivot; [ 0] -> push_a ( 0 ~  2)[ 3]

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
	// int	size_a;
	// int	i;
	// int	size_b;
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*stack_b;

	// size_a = stack_len(stack_a);
	// size_b = stack_len(stack_b);
	// i = 0;
	stack_a = head_p_stack_a->next;
	stack_b = head_p_stack_b->next;
	printf(" stack_a   |  stack_b\n");
	printf("------------------------------------------------------");
	printf("------------------------------------------------------\n");
	while (stack_a != head_p_stack_a || stack_b != head_p_stack_b)
	{
		if (stack_a == head_p_stack_a)
		{
			printf("         |   [%3d]\n", stack_b->index);
		}
		else if (stack_b == head_p_stack_b)
		{
			printf(" [%3d]   |\n", stack_a->index);
		}
		else
		{
			printf(" [%3d]   |   [%3d]\n", stack_a->index, stack_b->index);
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
	printf("------------------------------------------------------");
	printf("------------------------------------------------------\n");
}

void	print_ranges_info(t_sort_range_index *ranges, char stack)
{
		printf("Cycle [%d] : stack [%c] info\n", ranges->cycle, stack);
		printf("-----------------------------------\n");
		printf("ranges->count_sorted : [%d]\n", ranges->count_sorted);
		printf("ranges->begin        : [%d]\n", ranges->begin);
		printf("ranges->end          : [%d]\n", ranges->end);
		printf("ranges->a_pivot      : [%d]\n", ranges->a_pivot);
		printf("ranges->b_pivot      : [%d]\n", ranges->b_pivot);
		printf("ranges->count_pushed : [%d]\n", ranges->count_pushed);
		printf("-----------------------------------\n");
}

