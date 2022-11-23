/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first_half.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/23 17:47:22 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_dcl_list *head_p_stack_a, t_dcl_list *head_p_stack_b);
void	print_sort_info(t_sort_info *info, char stack);

/*
void	set_ranges_stack_a(t_sort_info *info, int stack_size);
bool	is_empty_stack_b(t_dcl_list *stack_b);
void	set_ranges_stack_b(t_sort_info *ranges, t_dcl_list *stack_b);
t_list	*try_sort_three_relation(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
t_list	*try_sort_stack_b_head(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
t_list	*try_push_a(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
bool	is_sort_to_over_median_from_n(t_sort_info *ranges, t_dcl_list *stack);
int	check_sort_to_over_median_from_n(t_sort_info *ranges, t_dcl_list *stack);
bool	is_under_median(int sorted, int median);
t_list	*try_push_b(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
bool	is_descending_sort_until_next_sort(int sorted, t_dcl_list *stack);
int	descending_sort_until_next_sort_size(int sorted, t_dcl_list *stack);
t_list	*try_sort_stack_b(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
bool	is_ascending_sort_until_next_sort(int sorted, t_dcl_list *stack);
int	ascending_sort_until_next_sort_size(int sorted, t_dcl_list *stack);
t_list	*try_sort_n_th_from_front_stack_a(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
t_list	*try_swap_rotate(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
t_list	*try_sort_three_relation(t_sort_info *ranges, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	t_order	order;

	if ((ranges->size - ranges->count_sorted) < 3)
	{
		return (head_p_log);
	}
	order = compare_3_values(stack_a->next->index, stack_a->next->next->index, stack_a->next->next->next->index);
	// printf("\n[%d] [%d] [%d]\n", stack_a->next->index, stack_a->next->next->index, stack_a->next->next->next->index);
	// printf("ranges->count_sorted is [%d]\n\n", ranges->count_sorted);
	if (order != Max_mid_min)
	{
		return (head_p_log);
	}
	if (!is_sort_n_node(ranges->count_sorted, stack_a, 3) || !is_sort_n_node(ranges->count_sorted + 1, stack_a, 2))
	{
		return (head_p_log);
	}
	head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
	ranges->count_pushed += 1;
	return (head_p_log);
}
t_list	*sort_first_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	// int	cycle = 0;

	while (1)
	{
		if (is_finish(info->sorted, info->a_pivot))
		{
			break ;
		}
		set_sort_ranges(info);
		while (1)
		{
			// print_ranges_info(ranges, 'a');
			// output_stack(stack_a, stack_b);
			if (is_finish(info->sorted, info->end_idxes[info->position_ary - 1]))
			{
				break ;
			}
			// head_p_log = try_sort_three_relation(info, stack_a, stack_b, head_p_log);
			// head_p_log = try_sort_stack_b_head(info, stack_a, stack_b, head_p_log);
			// head_p_log = try_sort_stack_b(info, stack_a, stack_b, head_p_log);
			// head_p_log = try_sort_n_th_from_front_stack_a(info, stack_a, stack_b, head_p_log);
			// if (is_sort(info->sorted, stack_a) || is_sort_n_node(info->sorted, stack_a, 2))
			if (is_sort(info->sorted, stack_a))
			{
				// head_p_log = try_sort(info, stack_a, stack_b, head_p_log);
				head_p_log = execute_operation(info, stack_a, stack_b, head_p_log);
				ranges->sorted += 1;
				continue ;
			}
			head_p_log = try_swap(info, stack_a, stack_b, head_p_log);
			// head_p_log = try_swap_rotate(ranges, stack_a, stack_b, head_p_log);
			ranges->count_pushed = check_sort_to_over_median_from_n(info, stack_a);
			head_p_log = try_push_b(info, stack_a, stack_b, head_p_log);
			// putstr_log(head_p_log);
			// output_stack(stack_a, stack_b);
			// cycle += 1;
			// if (cycle == 1000)
			// {
			// 	exit(1);
				// return (head_p_log);
			// }
		}
	}
	return (head_p_log);
}
*/

t_list	*sort_rotate_a(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log);
bool	is_sort_stack_a(int target, t_dcl_list *stack);
t_list	*sort_first_half(t_sort_info *info, t_dcl_list *stack_a, t_dcl_list *stack_b, t_list *head_p_log)
{
	// int	cycle = 0;
	int	begin_idx;
	int	end_idx;
	int	pivot;

	begin_idx = 0;
	end_idx = 0;
	pivot = 0;
	while (1)
	{
		if (is_finish(info->sorted, info->a_pivot))
		{
			break ;
		}
		// set_next_range();
		info->position_ary -= 1;
		begin_idx = info->sorted;
		end_idx = info->end_idxes[info->position_ary];
		pivot = calculate_median(begin_idx + end_idx);
		while (1)
		{
			// print_ranges_info(ranges, 'a');
			// output_stack(stack_a, stack_b);
			if (is_finish(info->sorted, end_idx))
			{
				break ;
			}
			if (is_sort_stack_a(info->sorted, stack_a))
			{
				// head_p_log = try_sort(info, stack_a, stack_b, head_p_log);
				head_p_log = sort_rotate_a(info, stack_a, stack_b, head_p_log);
				continue ;
			}
			else
			{
				head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
				if (pivot <= stack_b->next->index)
				{
					head_p_log = execute_operation(Rotate_b, stack_a, stack_b, head_p_log);
				}
			}
			// head_p_log = try_swap(info, stack_a, stack_b, head_p_log);
			// head_p_log = try_swap_rotate(ranges, stack_a, stack_b, head_p_log);
			// ranges->count_pushed = check_sort_to_over_median_from_n(info, stack_a);
			// head_p_log = try_push_b(info, stack_a, stack_b, head_p_log);
			// putstr_log(head_p_log);
			// output_stack(stack_a, stack_b);
			// cycle += 1;
			// if (cycle == 1000)
			// {
			// 	exit(1);
				// return (head_p_log);
			// }
		}
	}
	return (head_p_log);
}
