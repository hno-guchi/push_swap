/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/04 23:04:15 by hnoguchi         ###   ########.fr       */
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
	int	cycle;
	int	sorted;
	int	begin_idx;
	int	end_idx;
	int	stack_a_pivot;
	int	stack_b_pivot;
	int	count_push_b;

	int	count_push_a;
	t_bidrect_circle_list	*node;
	int	count_temp_rotate_b;

	cycle = 0;
	sorted = 0;
	begin_idx = 0;
	end_idx = 0;
	stack_a_pivot = 0;
	stack_b_pivot = 0;
	count_push_b = 0;
	begin_idx = 0;
	count_push_a = 0;
	node = NULL;
	count_temp_rotate_b = 0;

	while (1)
	{
		if (cycle == 1)
		{
			return (head_p_log);
		}
		begin_idx = sorted;
		end_idx = n;
		stack_a_pivot = calculate_median(begin_idx + end_idx);
		stack_b_pivot = calculate_median(begin_idx + stack_a_pivot);
		count_push_b = 0;
		printf("Cycle [%d] : push_swap_stack_a info\n", cycle);
		printf("-----------------------------------\n");
		printf("begin_idx        : [%d]\n", begin_idx);
		printf("end_idx          : [%d]\n", end_idx);
		printf("stack_a_pivot    : [%d]\n", stack_a_pivot);
		printf("stack_b_pivot    : [%d]\n", stack_b_pivot);
		printf("count_push_b     : [%d]\n", count_push_b);
		printf("sorted           : [%d]\n", sorted);
		printf("-----------------------------------\n");
		while (1)
		{
			if (0 < cycle && stack_a->next->index == sorted)
			{
				head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
						head_p_log);
				sorted += 1;
				count_push_b += 1;
				continue ;
			}
			if (1 < count_push_b)
			{
				if (stack_b->next->index < stack_b_pivot)
				{
					head_p_log = execute_operation(Rotate_b, stack_a, stack_b,
							head_p_log);
				}
				if (stack_b->next->index < stack_b->next->next->index)
				{
					head_p_log = execute_operation(Swap_b, stack_a, stack_b,
							head_p_log);
				}
			}
			if (count_push_b == stack_a_pivot)
			{
				output_stack(stack_a, stack_b);
				break ;
			}
 			if (0 < cycle && stack_a_pivot <= stack_a->next->index)
			{
				output_stack(stack_a, stack_b);
				break ;
			}
			if (cycle == 0 && (stack_a->prev->index < stack_a_pivot || stack_a->next->index < stack_a_pivot))
			{
				if (stack_a->prev->index < stack_a_pivot)
				{
					head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b,
						head_p_log);
					head_p_log = execute_operation(Push_b, stack_a, stack_b,
						head_p_log);
				}
				else
				{
					head_p_log = execute_operation(Push_b, stack_a, stack_b,
						head_p_log);
				}
				count_push_b += 1;
			}
			else if (0 < cycle && stack_a->next->index < stack_a_pivot)
			{
				head_p_log = execute_operation(Push_b, stack_a, stack_b,
						head_p_log);
				count_push_b += 1;
			}
			else
			{
				head_p_log = execute_operation(Rotate_a, stack_a, stack_b,
					head_p_log);
			}
		}

		begin_idx = stack_b_pivot;
		int	i = 0;
		while (1)
		{
			node = stack_b->next;
			if (node == stack_b)
			{
				break ;
			}
			end_idx = node->index;
			while (node != stack_b)
			{
				if (end_idx < node->next->index)
				{
					end_idx = node->next->index;
				}
				node = node->next;
			}
			if (end_idx <= begin_idx || (end_idx - begin_idx) < 4)
			{
				begin_idx = 0;
			}
			stack_b_pivot = calculate_median(begin_idx + end_idx);
			count_push_a = 0;
			printf("Cycle [%d] : push_swap_stack_b info\n", cycle);
			printf("-----------------------------------\n");
			printf("begin_idx        : [%d]\n", begin_idx);
			printf("end_idx          : [%d]\n", end_idx);
			printf("stack_b_pivot    : [%d]\n", stack_b_pivot);
			printf("count_push_a     : [%d]\n", count_push_a);
			printf("sorted           : [%d]\n", sorted);
			printf("-----------------------------------\n");
			if (begin_idx != 0)
			{
				while (1)
				{
					if (stack_b->next->index < stack_b->next->next->index)
					{
						head_p_log = execute_operation(Swap_b, stack_a, stack_b,
								head_p_log);
					}
					if (stack_b_pivot <= stack_b->next->index)
					{
						head_p_log = execute_operation(Push_a, stack_a, stack_b,
								head_p_log);
					}
					else
					{
						head_p_log = execute_operation(Rotate_b, stack_a, stack_b,
							head_p_log);
					}
					// printf(GREEN"[OK]"END); printf(" : if (stack_b_quartile <= stack_b->next->index)\n");
					// printf("end_idx : [%d] | count_push_a ; [%d]\n", end_idx, count_push_a);
					if (stack_a->next->next->index < stack_a->next->index)
					{
						head_p_log = execute_operation(Swap_a, stack_a, stack_b,
								head_p_log);
					}
					// printf(GREEN"[OK]"END); printf(" : if (stack_a->next->next->index < stack_a->next->index)\n");
					if (stack_b->next->index < begin_idx)
					{
						while (begin_idx <= stack_b->prev->index)
						{
							head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b,
							head_p_log);
							// printf(GREEN"[OK]"END);printf("while (stack_b_pivot < stack_b->prev->index)\n");
						}
						output_stack(stack_a, stack_b);
						break ;
					}
					// printf(GREEN"[OK]"END); printf(" : if (count_push_a == end_idx)\n");
				}
			}
			else
			{
				while (1)
				{
					if (stack_b->next->index < stack_b->next->next->index)
					{
						head_p_log = execute_operation(Swap_b, stack_a, stack_b,
								head_p_log);
					}
					if (stack_b_pivot <= stack_b->prev->index || stack_b_pivot <= stack_b->next->index)
					{
						if (stack_b_pivot <= stack_b->prev->index)
						{
							head_p_log = execute_operation(Reverse_rotate_b, stack_a, stack_b,
								head_p_log);
							head_p_log = execute_operation(Push_a, stack_a, stack_b,
								head_p_log);
						}
						else
						{
							head_p_log = execute_operation(Push_a, stack_a, stack_b,
									head_p_log);
							count_push_a += 1;
						}
					}
					else
					{
						head_p_log = execute_operation(Rotate_b, stack_a, stack_b,
							head_p_log);
					}
					// printf(GREEN"[OK]"END); printf(" : if (stack_b_quartile <= stack_b->next->index)\n");
					// printf("end_idx : [%d] | count_push_a ; [%d]\n", end_idx, count_push_a);
					if (stack_a->next->next->index < stack_a->next->index)
					{
						head_p_log = execute_operation(Swap_a, stack_a, stack_b,
								head_p_log);
					}
					// printf(GREEN"[OK]"END); printf(" : if (stack_a->next->next->index < stack_a->next->index)\n");
					if (stack_b_pivot <= count_push_a)
					{
						output_stack(stack_a, stack_b);
						break ;
					}
					// printf(GREEN"[OK]"END); printf(" : if (count_push_a == end_idx)\n");
				}

			}
			i += 1;
			if (i == 6)
			{
				break ;
			}
		}
	cycle += 1;
	}
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
