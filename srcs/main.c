/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/01 18:40:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

#define SORT_MINIMAM_SIZE 4

void	output_stack(t_dcl_list *head_p_stack_a,
			t_dcl_list *head_p_stack_b);
void	print_sort_info(t_sort_info *info, char stack);

// split_first_half.c
bool	is_swap_a(t_dcl_list *stack);
bool	is_swap_b(t_dcl_list *stack);
t_list	*try_swap(t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
bool	is_under_pivot_b(t_sort_info *info, t_dcl_list *stack);
t_list	*split_second_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);

// initialize_sort_info.c
void	initialize_sort_info_second(t_sort_info *info);

// sort_to_a_from_b.c
t_list	*try_sort_until_possible(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log);

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

int	calculate_section_size(t_sort_info *info, t_dcl_list *stack)
{
	int			section_size;
	t_dcl_list	*node;

	section_size = 0;
	node = stack->next;
	if (node == stack)
	{
		return (0);
	}
	while (info->sorted <= node->index && node->index < info->limit)
	{
		section_size += 1;
		if (node->next == stack)
		{
			break ;
		}
		node = node->next;
	}
	return (section_size);
}

void	set_sort_info_stack_a(t_sort_info *info, t_dcl_list *stack)
{
	info->limit = get_next_limit(info);
	if (info->limit == -1)
	{
		return ;
	}
	info->section_size = calculate_section_size(info, stack);
	info->b_pivot = calculate_median(info->sorted + info->limit);
}

t_list	*try_sort(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list *node;

	node = stack_a->next;
	if (info->sorted == node->index)
	{
		log = execute_operation(Rotate_a, stack_a, stack_b, log);
		info->sorted += 1;
	}
	return (log);
}

t_list	*try_reverse_rotate_check_exist_next(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node;
	int			stack_size;

	node = stack_b->prev;
	stack_size = stack_len(stack_b);
	if (1 < stack_size)
	{
		if ((info->sorted + 2) == node->index)
		{
			log = execute_operation(Reverse_rotate_r, stack_a, stack_b, log);
			return (log);
		}
	}
	log = execute_operation(Reverse_rotate_a, stack_a, stack_b, log);
	return (log);
}

t_list	*try_sort_check_exist_next(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	t_dcl_list	*node;

	node = stack_a->prev;
	if ((info->sorted + 1) == node->index)
	{
		log = try_reverse_rotate_check_exist_next(info, stack_a, stack_b, log);
		log = execute_operation(Swap_a, stack_a, stack_b, log);
	}
	log = try_sort(info, stack_a, stack_b, log);
	return (log);
}

t_list	*sort_section_size_2(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	int		i;

	i = 0;
	if ((stack_a->next->index - stack_a->next->next->index) == 1)
	{
		log = execute_operation(Swap_a, stack_a, stack_b, log);
	}
	while (i < info->section_size)
	{
		log = try_sort(info, stack_a, stack_b, log);
		i += 1;
	}
	return (log);
}

t_list	*sort_section_size_3(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	int		i;
	t_order	order;

	i = 0;
	order = Bad_order;
	order = compare_3_values(stack_a->next->index, stack_a->next->next->index, stack_a->next->next->next->index);
	if (order == Min_mid_max)
	{
		while (i < info->section_size)
		{
			log = try_sort(info, stack_a, stack_b, log);
			i += 1;
		}
	}
	else if (order == Min_max_mid)
	{
		log = try_sort(info, stack_a, stack_b, log);
		log = execute_operation(Swap_a, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
	}
	else if (order == Mid_min_max)
	{
		log = execute_operation(Swap_a, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
	}
	else if (order == Mid_max_min)
	{
		log = execute_operation(Push_b, stack_a, stack_b, log);
		log = execute_operation(Swap_a, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
		log = execute_operation(Push_a, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
	}
	else if (order == Max_min_mid)
	{
		log = execute_operation(Push_b, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
		log = execute_operation(Push_a, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
	}
	else if (order == Max_mid_min)
	{
		log = execute_operation(Push_b, stack_a, stack_b, log);
		log = execute_operation(Swap_a, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
		log = execute_operation(Push_a, stack_a, stack_b, log);
		log = try_sort(info, stack_a, stack_b, log);
	}
	return (log);
}

t_list	*sort_section_size_under_4(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	if (info->section_size == 1)
	{
		log = try_sort(info, stack_a, stack_b, log);
	}
	else if (info->section_size == 2)
	{
		log = sort_section_size_2(info, stack_a, stack_b, log);
	}
	else if (info->section_size == 3)
	{
		log = sort_section_size_3(info, stack_a, stack_b, log);
	}
	return (log);
}

bool	is_sort_stack_b(t_sort_info *info, t_dcl_list *stack_b)
{
	if (0 < info->stack_b_size)
	{
		if (stack_b->next->index == info->sorted)
		{
			return (true);
		}
	}
	if (1 < info->stack_b_size)
	{
		if (stack_b->prev->index == info->sorted)
		{
			return (true);
		}
	}
	return (false);
}

t_list	*try_sort_stack_b(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	if (0 < info->stack_b_size)
	{
		if (stack_b->next->index == info->sorted)
		{
			log = execute_operation(Push_a, stack_a, stack_b, log);
			return (log);
		}
	}
	if (1 < info->stack_b_size)
	{
		if (stack_b->prev->index == info->sorted)
		{
			log = execute_operation(Reverse_rotate_b, stack_a, stack_b, log);
			return (log);
		}
	}
	return (log);
}

t_list	*push_swap_stack_a(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *log)
{
	// int	i = 0;
	info->section_size = calculate_section_size(info, stack_a);
	if (info->section_size < SORT_MINIMAM_SIZE)
	{
		log = sort_section_size_under_4(info, stack_a, stack_b, log);
	}
	// this_section_push_swap
	else
	{
		while (info->sorted <= stack_a->next->index && stack_a->next->index < info->limit)
		{
			// if (i == 1000)
			// 	exit(1) ;
			// i += 1;
			info->stack_b_size = stack_len(stack_b);
			if (stack_a->next->index == info->sorted)
			{
				log = try_sort_check_exist_next(info, stack_a, stack_b, log);
				continue ;
			}
			if (is_sort_stack_b(info, stack_b))
			{
				log = try_sort_stack_b(info, stack_a, stack_b, log);
				continue ;
			}
			if (stack_a->next->index == (info->sorted + 1))
			{
				log = execute_operation(Rotate_a, stack_a, stack_b, log);
				continue ;
			}
			if (is_swap_a(stack_a) || is_swap_b(stack_b))
			{
				log = try_swap(stack_a, stack_b, log);
				continue ;
			}
			log = execute_operation(Push_b, stack_a, stack_b, log);
			if (is_under_pivot_b(info, stack_b))
			{
				log = execute_operation(Rotate_b, stack_a, stack_b, log);
			}
		}
	}
	return (log);
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
	initialize_sort_info(&info, n);
	log = split_first_half(&info, stack_a, stack_b, log);
	pivot = info.a_pivot;
	// print_sort_info(&info,'0');
	// output_stack(stack_a, stack_b);
	while(info.sorted != info.size)
	{
		if (info.a_pivot <= info.sorted)
		{
			initialize_sort_info_second(&info);
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
				set_sort_info_stack_a(&info, stack_a);
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

