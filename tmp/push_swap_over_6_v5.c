/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/04 09:36:41 by hnoguchi         ###   ########.fr       */
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

typedef struct	s_sort_range_index {
	int	stack_a_size;
	int	sorted;
	int	median;
	int	push_b;
	int	rotate_b;
	int	cycle;
}	t_sort_range_index;

t_list	*push_a_and_rotate_a(t_bidrect_circle_list *stack_a,
			t_bidrect_circle_list *stack_b, t_list *head_p_log, t_sort_range_index *ranges)
{
	// int	count_push_a;
	t_bidrect_circle_list	*node;

	node = stack_b->next;
	/*
	while (stack_b->prev->index < ranges->rotate_b)
	{
		head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
		if (stack_b->next->index < stack_b->next->next->index)

	}
	*/
	while (node != stack_b)
	{if (stack_a->next->index == ranges->sorted)
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
					head_p_log);
			ranges->sorted += 1;
		}
		if (stack_b->prev->index < ranges->rotate_b)
		{
			head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b, head_p_log);
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
		}
		else
		{
			// if (stack_b->next->index < stack_b->next->next->index)
			if (stack_b->next->index - stack_b->next->next->index == -1)
			{
				// if (stack_a->next->next->index < stack_a->next->index)
				if (stack_a->next->index - stack_a->next->next->index == 1)
				{
					head_p_log = execute_operation(Swap_s, stack_a, stack_b,
						head_p_log);
				}
				else
				{
					head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
				}
			}
			head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
		}
		
		/*
		if (stack_a->next->next->index < stack_a->next->index)
		{
			if (stack_b->next->index < stack_b->next->next->index)
			{
				head_p_log = execute_operation(Swap_s, stack_a, stack_b,
						head_p_log);
			}
			else
			{
				head_p_log = execute_operation(Swap_a, stack_a, stack_b,
						head_p_log);
			}
		}
		*/
		node = stack_b->next;
	}
	return (head_p_log);
}

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

	// while (ranges.sorted != ranges.stack_a_size)
	while (!is_ascending_sorted(stack_a))
	{
		count_stack_b_node = 0;
		ranges.push_b = set_range_push_b(ranges.sorted, ranges.median, ranges.stack_a_size);
		ranges.rotate_b = set_range_rotate_b(ranges.sorted, ranges.median);
		while (count_stack_b_node < (ranges.push_b - ranges.sorted))
		{
			if (0 < ranges.cycle && stack_a->next->index == ranges.sorted)
			{
				if (1 < count_stack_b_node && stack_b->next->index < ranges.rotate_b)
				{
					head_p_log = execute_operation(Rotate_r, stack_a, stack_b,
							head_p_log);
					ranges.sorted += 1;
					continue ;
				}
				head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
						head_p_log);
				ranges.sorted += 1;
				continue ;
			}
			if (stack_a->next->next->index < stack_a->next->index)
			// if (stack_a->next->index - stack_a->next->next->index == 1)
			{
				head_p_log = execute_operation(Swap_a, stack_a, stack_b,
						head_p_log);
				continue ;
			}
			else if (ranges.push_b <= stack_a->next->index < ranges.push_b && ranges.push_b <= stack_a->prev->index)
			{
				head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
						head_p_log);
				continue ;
			}
			/*
			if (1 < count_stack_b_node)
			{
				if (stack_b->next->index < ranges.rotate_b)
				{
					head_p_log = execute_operation(Rotate_b, stack_a, stack_b,
							head_p_log);
				}
				else if (stack_b->next->index < stack_b->next->next->index)
				// else if (stack_b->next->index - stack_b->next->next->index == -1)
				{
					// if (stack_a->next->next->index < stack_a->next->index)
					if (stack_a->next->index - stack_a->next->next->index == 1)
					{
						head_p_log = execute_operation(Swap_s, stack_a, stack_b,
								head_p_log);
					}
					else
					{
						head_p_log = execute_operation(Swap_b, stack_a, stack_b,
								head_p_log);
					}
					// continue ;
				}
			}
			*/
			if (stack_a->next->index < ranges.push_b || stack_a->prev->index < ranges.push_b)
			{
				if (stack_a->next->index < ranges.push_b)
				{
					head_p_log = execute_operation(Push_b, stack_a, stack_b,
							head_p_log);
					count_stack_b_node += 1;
				}
				else
				{
					head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b,
							head_p_log);
					head_p_log = execute_operation(Push_b, stack_a, stack_b,
							head_p_log);
					count_stack_b_node += 1;
				}
				// continue ;
			}
			if (1 < count_stack_b_node)
			{
				if (stack_b->next->index < ranges.rotate_b)
				{
					head_p_log = execute_operation(Rotate_b, stack_a, stack_b,
							head_p_log);
				}
				else if (stack_b->next->index < stack_b->next->next->index)
				// else if (stack_b->next->index - stack_b->next->next->index == -1)
				{
					// if (stack_a->next->next->index < stack_a->next->index)
					if (stack_a->next->index - stack_a->next->next->index == 1)
					{
						head_p_log = execute_operation(Swap_s, stack_a, stack_b,
								head_p_log);
					}
					else
					{
						head_p_log = execute_operation(Swap_b, stack_a, stack_b,
								head_p_log);
					}
					// continue ;
				}
			}
			/*
			if (stack_a->next->next->index < stack_a->next->index)
			// if (stack_a->next->index - stack_a->next->next->index == 1)
			{
				head_p_log = execute_operation(Swap_a, stack_a, stack_b,
						head_p_log);
			}
			else
			{
				head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
						head_p_log);
			}
			*/
		}
		head_p_log = push_a_and_rotate_a(stack_a, stack_b, head_p_log, &ranges);
		ranges.cycle += 1;
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
/*
	while (ranges.sorted != ranges.stack_a_size)
	{
		count_stack_b_node = 0;
		ranges.push_b = set_range_push_b(ranges.sorted, ranges.median, ranges.stack_a_size);
		ranges.rotate_b = set_range_rotate_b(ranges.sorted, ranges.median);
		while (count_stack_b_node < (ranges.push_b - ranges.sorted))
		{
			// if (0 < ranges.cycle && stack_a->next->index == ranges.sorted)
			// {
			// 	head_p_log = execute_operation(Rotate_r, stack_a, stack_b,
			// 			head_p_log);
			// 	ranges.sorted += 1;
			// }
			if (stack_a->next->index < ranges.push_b || stack_a->prev->index < ranges.push_b)
			{
				if (stack_a->next->index < ranges.push_b)
				{
					head_p_log = execute_operation(Push_b, stack_a, stack_b,
							head_p_log);
					count_stack_b_node += 1;
				}
				else
				{
					head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b,
							head_p_log);
					head_p_log = execute_operation(Push_b, stack_a, stack_b,
							head_p_log);
					count_stack_b_node += 1;
				}
				if (count_stack_b_node == 1)
				{
					continue ;
				}
				if ((stack_b->next->index - stack_b->next->next->index) == -1)
				{
					if ((stack_a->next->index - stack_a->next->next->index) == 1)
					{
						head_p_log = execute_operation(Swap_s, stack_a, stack_b,
								head_p_log);
					}
					else
					{
						head_p_log = execute_operation(Swap_b, stack_a, stack_b,
								head_p_log);
					}
				}
				if (stack_b->next->index < ranges.rotate_b)
				{
					// if ((0 < ranges.cycle && stack_a->next->index == ranges.sorted) ||
					if (ranges.cycle == 0 && ranges.push_b <= stack_a->next->index)
					{
						head_p_log = execute_operation(Rotate_r, stack_a, stack_b,
								head_p_log);
						// ranges.sorted += 1;
					}
					else
					{
						head_p_log = execute_operation(Rotate_b, stack_a, stack_b,
							head_p_log);
					}
				}
				if (0 < ranges.cycle && stack_a->next->index == ranges.sorted)
				{
					head_p_log = execute_operation(Rotate_r, stack_a, stack_b,
							head_p_log);
					ranges.sorted += 1;
				}
			}
			else
			{
				if (ranges.cycle == 0)
				{
					head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
							head_p_log);
				}
				if ((stack_a->next->index - stack_a->next->next->index) == 1)
				{
					head_p_log = execute_operation(Swap_a, stack_a, stack_b,
							head_p_log);
				}
			}
*/
