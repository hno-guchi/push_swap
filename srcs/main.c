/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/02 11:59:24 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_dcl_list *head_p_stack_a, t_dcl_list *head_p_stack_b);
void	print_sort_info(t_sort_info *info, char stack);

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

int	get_limit(t_sort_info *info)
{
	int	limit;

	limit = 0;
	if (info->limits_idx <= 0)
	{
		return (-1);
	}
	info->limits_idx -= 1;
	limit = info->limits[info->limits_idx];
	info->limits[info->limits_idx] = 0;
	return (limit);
}

int	get_next_limit(t_sort_info *info)
{
	int	limit;

	limit = get_limit(info);
	if (limit == -1)
	{
		return (-1);
	}
	while (limit <= info->sorted)
	{
		limit = get_limit(info);
		if (limit == -1)
		{
			return (-1);
		}
	}
	return (limit);
}

void	set_sort_info_next_section(t_sort_info *info, t_dcl_list *stack)
{
	info->limit = get_next_limit(info);
	if (info->limit == -1)
	{
		return ;
	}
	info->section_size = calculate_section_size(info, stack);
	info->b_pivot = calculate_median(info->sorted + info->limit);
}

bool	is_complete_sort_section(t_sort_info *info, t_dcl_list *stack)
{
	int			count;
	t_dcl_list	*node;

	count = 0;
	node = stack->next;
	if (stack == node)
	{
		return (true);
	}
	while (node->index < info->limit)
	{
		if (node->index == 0)
		{
			break ;
		}
		count += 1;
		node = node->next;
	}
	if (count == 0)
	{
		return (true);
	}
	return (false);
}

t_list	*push_swap_over_6(int n, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	int			pivot;
	t_sort_info	info;

	pivot = 0;
	initialize_sort_info_first_half(&info, n);
	log = split_first_half(&info, stack_a, stack_b, log);
	pivot = info.a_pivot;
	// print_sort_info(&info,'0');
	// output_stack(stack_a, stack_b);
	while(info.sorted != info.size)
	{
		if (info.a_pivot <= info.sorted)
		{
			initialize_sort_info_second_half(&info);
			log = split_second_half(&info, stack_a, stack_b, log);
			pivot = info.size;
		}
		while(info.sorted < pivot)
		{
			// i += 1;
			// if (i == 1000)
			// {
			// 	print_sort_info(&info,'1');
			// 	output_stack(stack_a, stack_b);
			// 	putstr_log(log);
			// 	exit(1);
			// }
			log = push_swap_stack_b(&info, stack_a, stack_b, log);
		// print_sort_info(&info,'1');
		// output_stack(stack_a, stack_b);
			log = try_sort_until_possible(&info, stack_a, stack_b, log);
		// print_sort_info(&info,'2');
			if (is_complete_sort_section(&info, stack_a))
			{
				set_sort_info_next_section(&info, stack_a);
				// print_sort_info(&info,'@');
				// output_stack(stack_a, stack_b);
			}
		// print_sort_info(&info,'3');
		// output_stack(stack_a, stack_b);
			log = push_swap_stack_a(&info, stack_a, stack_b, log);
		// print_sort_info(&info,'4');
		// output_stack(stack_a, stack_b);
		}
	}
	return (log);
}

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
	// system("leaks -q push_swap");
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
	printf("------------------------------------------------------\n");
}

void	print_sort_info(t_sort_info *info, char stack)
{
	int	i = 0;

	// printf("Cycle [%d] : stack [%c] info\n", info->cycle, stack);
	printf("stack [%c] info\n", stack);
	printf("-----------------------------------\n");
	printf("info->size         : [%4d]\n", info->size);
	printf("info->sorted       : [%4d]\n", info->sorted);
	// printf("info->pushed       : [%4d]\n", info->pushed);
	// printf("info->begin_idxes[]   : ");
	// i = 0;
	// while (i < info->position_ary)
	// {
	// 	printf("[%d]", info->end_idxes[i]);
	// 	i += 1;
	// 	if (i < info->position_ary)
	// 	{
	// 		printf("-> ");
	// 	}
	// }
	// printf("\n");
	printf("info->limits_idx   : [%4d]\n", info->limits_idx);
	printf("info->limits[]     : ");
	while (info->limits[i] != 0)
	{
		printf("[%d]", info->limits[i]);
		i += 1;
		if (i < info->limits[i] != 0)
		{
			printf("-> ");
		}
	}
	printf("\n");
	printf("info->limit        : [%4d]\n", info->limit);
	printf("info->section_size : [%4d]\n", info->section_size);
	printf("info->a_pivot      : [%4d]\n", info->a_pivot);
	printf("info->b_pivot      : [%4d]\n", info->b_pivot);
	printf("info->stack_b_size : [%4d]\n", info->stack_b_size);
	// printf("info->median       : [%4d]\n", info->median);
	printf("-----------------------------------\n");
}

