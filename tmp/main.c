/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/23 17:09:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_dcl_list *head_p_stack_a,
			t_dcl_list *head_p_stack_b);
void	print_sort_info(t_sort_info *info, char stack);

bool	is_finish(int value, int border)
{
	return (value == border);
}

bool	is_empty_stack_b(t_dcl_list *stack_b)
{
	t_dcl_list	*node;

	node = stack_b->next;
	if (node == stack_b)
	{
		return (true);
	}
	return (false);
}

/*
void	set_sort_info(t_sort_info *info, int stack_size)
{
	// info->end = stack_size;
	info->count_pushed = 0;
	info->begin = info->count_sorted;
	if (info->median <= info->count_sorted)
	{
		// info->begin = info->median;
		info->b_pivot = calculate_median(info->begin + info->end);
	}
	else
	{
		// info->begin = 0;
		info->b_pivot = calculate_median(info->begin + info->a_pivot);
	}
}

t_list	*try_sort_stack_b_head(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	if (is_sort(ranges->count_sorted, stack_b))
	{
		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
		ranges->count_pushed -= 1;
	}
	return (head_p_log);
}

t_list	*try_push_a(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	if (!is_under_b_pivot(ranges->b_pivot, stack_b->next->index))
	{
		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}

bool	is_sort_to_over_median_from_n(t_sort_info *ranges, t_dcl_list *stack)
{
	int						temp_pushed;
	t_dcl_list	*node;

	temp_pushed = ranges->count_pushed + 1;
	node = stack->next;
	if (is_finish(ranges->count_sorted + temp_pushed, ranges->a_pivot))
	{
		return (false);
	}
	while(!is_finish(ranges->count_sorted + temp_pushed, ranges->a_pivot))
	{
		if ((node->index + 1) != node->next->index)
	{
			return (false);
		}
		node = node->next;
		temp_pushed += 1;
	}
	return (true);
}

int	check_sort_to_over_median_from_n(t_sort_info *ranges, t_dcl_list *stack)
{
	int	temp_pushed;

	temp_pushed = ranges->count_pushed;
	if (!is_sort_to_over_median_from_n(ranges, stack))
	{
		return (temp_pushed);
	}
	while (!is_finish(ranges->count_sorted + temp_pushed, ranges->a_pivot))
	{
		temp_pushed += 1;
	}
	return (temp_pushed);
}

bool	is_under_median(int sorted, int median)
{
	return (sorted < median);
}

t_list	*try_push_b(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	if (is_under_median(ranges->count_sorted, ranges->a_pivot))
	{
		if (is_finish(ranges->count_sorted + ranges->count_pushed, ranges->a_pivot))
		{
			return (head_p_log);
		}
		if (ranges->a_pivot <= stack_a->next->index)
		{
			return (head_p_log);
		}
	}
	head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
	ranges->count_pushed += 1;
	return (head_p_log);
}

bool	is_descending_sort_until_next_sort(int sorted, t_dcl_list *stack)
{
	int						count;
	t_dcl_list	*node;

	count = 1;
	node = stack->next;
	while (node != stack)
	{
		if (node->index != (node->next->index + 1))
		{
			break ;
		}
		node = node->next;
		count += 1;
	}
	if (count == 1)
	{
		return (false);
	}
	if (node->index != sorted)
	{
		return (false);
	}
	return (true);
}

int	descending_sort_until_next_sort_size(int sorted, t_dcl_list *stack)
{
	int						count;
	t_dcl_list	*node;

	count = 1;
	node = stack->next;
	while (node != stack && node->index != sorted)
	{
		count += 1;
		node = node->next;
	}
	return (count);
}

t_list	*try_sort_stack_b(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	int	count_node;

	count_node = 0;
	if (stack_len(stack_b) < 2)
	{
		return (head_p_log);
	}
	if (!is_descending_sort_until_next_sort(ranges->count_sorted, stack_b))
	{
		return (head_p_log);
	}
	count_node = descending_sort_until_next_sort_size(ranges->count_sorted, stack_b);
	while (count_node)
	{
		head_p_log = execute_operation(Push_a, stack_a, stack_b, head_p_log);
		ranges->count_pushed -= 1;
		count_node -= 1;
	}
	return (head_p_log);
}

bool	is_ascending_sort_until_next_sort(int sorted, t_dcl_list *stack)
{
	int						count;
	t_dcl_list	*node;

	count = 0;
	node = stack->next;
	while (node != stack)
	{
		if ((node->index + 1) != node->next->index)
		{
			break ;
		}
		node = node->next;
		count += 1;
	}
	if (count < 2)
	{
		return (false);
	}
	if (node->index != sorted)
	{
		return (false);
	}
	return (true);
}

int	ascending_sort_until_next_sort_size(int sorted, t_dcl_list *stack)
{
	int						count;
	t_dcl_list	*node;

	count = 0;
	node = stack->next;
	while (node != stack && node->index != sorted)
	{
		count += 1;
		node = node->next;
	}
	return (count);
}

t_list	*try_sort_n_th_from_front_stack_a(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	int	count_node;

	count_node = 0;
	if (!is_ascending_sort_until_next_sort(ranges->count_sorted, stack_a))
	{
		return (head_p_log);
	}
	count_node = ascending_sort_until_next_sort_size(ranges->count_sorted, stack_a);
	while (count_node)
	{
		head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
		ranges->count_pushed += 1;
		count_node -= 1;
	}
	return (head_p_log);
}

t_list	*try_swap_rotate(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	bool	judge_swap_a;
	bool	judge_swap_b;
	bool	judge_rotate_b;

	judge_swap_a = is_swap_a(ranges, stack_a);
	judge_swap_b = is_swap_b(stack_b);
	judge_rotate_b = is_rotate_b(ranges, stack_b);
	if (judge_rotate_b)
	{
		judge_swap_b = false;
		head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
	}
	if (judge_swap_a && judge_swap_b)
	{
		head_p_log = execute_operation(Swap_s, stack_a, stack_b, head_p_log);
	}
	else if (judge_swap_a)
	{
		head_p_log = execute_operation(Swap_a, stack_a, stack_b, head_p_log);
	}
	else if (judge_swap_b)
	{
		head_p_log = execute_operation(Swap_b, stack_a, stack_b, head_p_log);
	}
	return (head_p_log);
}

t_list	*split_second_half(t_sort_info *ranges, t_dcl_list *stack_a,
		t_dcl_list *stack_b, t_list *head_p_log)
{
	int	cycle = 0;
	while (1)
	{
		// print_ranges_info(ranges, 'a');
		// output_stack(stack_a, stack_b);
		if (is_finish(ranges->count_sorted + ranges->count_pushed, ranges->end))
		{
			break ;
		}
		if (is_sort(ranges->count_sorted, stack_a) || is_sort_n_node(ranges->count_sorted, stack_a, 2))
		{
			head_p_log = try_sort(ranges, stack_a, stack_b, head_p_log);
			ranges->count_sorted += 1;
			continue ;
		}
		head_p_log = try_swap(ranges, stack_a, stack_b, head_p_log);
		head_p_log = try_push_b(ranges, stack_a, stack_b, head_p_log);
		head_p_log = try_rotate_b(ranges, stack_a, stack_b, head_p_log);
		// putstr_log(head_p_log);
		// output_stack(stack_a, stack_b);
		cycle += 1;
		if (cycle == 1000)
		{
			exit(1);
			// return (head_p_log);
		}
	}
	return (head_p_log);
}

t_list	*sort_over_median(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	int	cycle = 0;

	while (1)
	{
		// print_ranges_info(ranges, 'a');
		// output_stack(stack_a, stack_b);
		if (is_finish(ranges->count_sorted + ranges->count_pushed, ranges->end))
		{
			break ;
		}
		head_p_log = try_sort_three_relation(ranges, stack_a, stack_b, head_p_log);
		head_p_log = try_sort_stack_b_head(ranges, stack_a, stack_b, head_p_log);
		head_p_log = try_sort_stack_b(ranges, stack_a, stack_b, head_p_log);
		head_p_log = try_sort_n_th_from_front_stack_a(ranges, stack_a, stack_b, head_p_log);
		if (is_sort(ranges->count_sorted, stack_a) || is_sort_n_node(ranges->count_sorted, stack_a, 2))
		{
			head_p_log = try_sort(ranges, stack_a, stack_b, head_p_log);
			ranges->count_sorted += 1;
			continue ;
		}
		head_p_log = try_swap(ranges, stack_a, stack_b, head_p_log);
		// head_p_log = try_swap_rotate(ranges, stack_a, stack_b, head_p_log);
		ranges->count_pushed = check_sort_to_over_median_from_n(ranges, stack_a);
		head_p_log = try_push_b(ranges, stack_a, stack_b, head_p_log);
		// putstr_log(head_p_log);
		// output_stack(stack_a, stack_b);
		cycle += 1;
		if (cycle == 1000)
		{
			exit(1);
			// return (head_p_log);
		}
	}
	return (head_p_log);
}
*/

t_list	*push_swap_over_6(int n, t_dcl_list *stack_a,
			t_dcl_list *stack_b, t_list *head_p_log)
{
	// t_list	*log = NULL;
	t_sort_info	sort_info;

	initialize_sort_info(&sort_info, n);
	// set_sort_info(&sort_info, n);
	head_p_log = split_first_half(&sort_info, stack_a, stack_b, head_p_log);
	// log = NULL;
	// log = split_first_half(&sort_info, stack_a, stack_b, head_p_log);
	// print_sort_info(&sort_info, 'a');
	// output_stack(stack_a, stack_b);
	// putstr_log(log);
	// ft_lstadd_back(&head_p_log, log);
	head_p_log = sort_to_a_from_b(&sort_info, stack_a, stack_b, head_p_log);
	// log = NULL;
	// log = sort_to_a_from_b(&sort_info, stack_a, stack_b, head_p_log);
	// print_sort_info(&sort_info, 'a');
	// output_stack(stack_a, stack_b);
	// putstr_log(log);
	// ft_lstadd_back(&head_p_log, log);
	head_p_log = sort_first_half(&sort_info, stack_a, stack_b, head_p_log);
	// log = NULL;
	// log = sort_first_half(&sort_info, stack_a, stack_b, head_p_log);
	// print_sort_info(&sort_info, 'a');
	// output_stack(stack_a, stack_b);
	// putstr_log(log);
	// ft_lstadd_back(&head_p_log, log);
		/*
	while (1)
	{
		if (is_ascending_sorted(stack_a))
		{
			return (head_p_log);
		}
		// ranges.begin = ranges.sorted;
		head_p_log = sort_to_a_from_b(&sort_info, stack_a, stack_b, head_p_log);
		while (1)
		{
			if (is_empty_stack_b(stack_b))
			{
				break ;
			}
			set_ranges_stack_b(&ranges, stack_b);
			head_p_log = push_a_half(&ranges, stack_a, stack_b, head_p_log);
		}
		*/
	/*
		set_ranges_stack_a(&ranges, n);
		else if (ranges.count_sorted < ranges.median)
		{
			// output_stack(stack_a, stack_b);
			head_p_log = sort_under_median(&ranges, stack_a, stack_b, head_p_log);
			// log = NULL;
			// log = sort_under_median(&ranges, stack_a, stack_b, log);
			// putstr_log(log);
			// output_stack(stack_a, stack_b);
			// print_ranges_info(&ranges, 'a');
			// ft_lstadd_back(&head_p_log, log);
		}
		else if (ranges.median == ranges.count_sorted)
		{
			// log = NULL;
			head_p_log = split_second_half(&ranges, stack_a, stack_b, head_p_log);
			// output_stack(stack_a, stack_b);
			// putstr_log(log);
			// ft_lstadd_back(&head_p_log, log);
		}
		// else if (ranges.median <= ranges.count_sorted)
		else if (ranges.median < ranges.count_sorted)
		{
			// output_stack(stack_a, stack_b);
			head_p_log = sort_over_median(&ranges, stack_a, stack_b, head_p_log);
			// log = NULL;
			// log = sort_over_median(&ranges, stack_a, stack_b, log);
			// putstr_log(log);
			// output_stack(stack_a, stack_b);
			// ft_lstadd_back(&head_p_log, log);
		}
		// head_p_log = push_swap_stack_b(&range, stack_a, stack_b, head_p_log);
		
		ranges.cycle += 1;
		// if (ranges.cycle == 1000)
		// {
		// 	exit(1);
			// return (head_p_log);
		// }
	}
	*/
	return (head_p_log);
}

// 1: begin_idx ~ end_idx; (0 ~ 25)[25] stack_b_pivot; [12] -> push_a (12 ~ 24)[13]
// 2: begin_idx ~ end_idx; (0 ~ 12)[12] stack_b_pivot; [ 6] -> push_a ( 6 ~ 11)[ 6]
// 3: begin_idx ~ end_idx; (0 ~  6)[ 6] stack_b_pivot; [ 3] -> push_a ( 3 ~  5)[ 3]
// 4: begin_idx ~ end_idx; (0 ~  3)[ 3] stack_b_pivot; [ 0] -> push_a ( 0 ~  2)[ 3]

t_list	*push_swap(int stack_size, t_dcl_list *stack_a, t_list *log)
{
	t_dcl_list	*stack_b;

	stack_b = create_sentinel();
	if (is_ascending_sorted(stack_a) || stack_size == 1)
	{
		stack_clear(&stack_b);
		return (NULL);
	}
	if (stack_size < 7)
	{
		log = push_swap_under_7(stack_size, stack_a, stack_b, log);
	}
	else
	{
		log = push_swap_over_6(stack_size, stack_a, stack_b, log);
	}
	stack_clear(&stack_b);
	return (log);
}

int	main(int argc, char **argv)
{
	t_dcl_list	*head_p_stack_a;
	t_list		*head_p_log;

	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	head_p_log = NULL;
	head_p_stack_a = prepare_sort(argc - 1, &argv[1], head_p_stack_a);
	head_p_log = push_swap(argc - 1, head_p_stack_a, head_p_log);
	putstr_log(head_p_log);
	stack_clear(&head_p_stack_a);
	ft_lstclear(&head_p_log, NULL);
	system("leaks -q push_swap");
	return (0);
}

void	output_stack(t_dcl_list *head_p_stack_a, t_dcl_list *head_p_stack_b)
{
	// int	size_a;
	// int	i;
	// int	size_b;
	t_dcl_list	*stack_a;
	t_dcl_list	*stack_b;

	// size_a = stack_len(stack_a);
	// size_b = stack_len(stack_b);
	// i = 0;
	stack_a = head_p_stack_a->next;
	stack_b = head_p_stack_b->next;
	printf(" stack_a    |  stack_b\n");
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

void	print_sort_info(t_sort_info *info, char stack)
{
	int	i = 0;

	// printf("Cycle [%d] : stack [%c] info\n", info->cycle, stack);
	printf("stack [%c] info\n", stack);
	printf("-----------------------------------\n");
	printf("info->size          : [%d]\n", info->size);
	printf("info->sorted        : [%d]\n", info->sorted);
	printf("info->position_ary  : [%d]\n", info->position_ary);
	printf("info->begin_idxes[] : ");
	while (i < info->position_ary)
	{
		printf("[%d]", info->begin_idxes[i]);
		i += 1;
		if (i < info->position_ary)
		{
			printf("-> ");
		}
	}
	printf("\n");
	printf("info->end_idxes[]   : ");
	i = 0;
	while (i < info->position_ary)
	{
		printf("[%d]", info->end_idxes[i]);
		i += 1;
		if (i < info->position_ary)
		{
			printf("-> ");
		}
	}
	printf("\n");
	printf("info->a_pivot      : [%d]\n", info->a_pivot);
	printf("info->b_pivot      : [%d]\n", info->b_pivot);
	printf("info->median       : [%d]\n", info->median);
	printf("info->pushed       : [%d]\n", info->pushed);
	printf("-----------------------------------\n");
}

