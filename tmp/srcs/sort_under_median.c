/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/16 14:45:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

void	output_stack(t_bidrect_circle_list *head_p_stack_a,
			t_bidrect_circle_list *head_p_stack_b);
void	print_ranges_info(t_sort_range_index *ranges, char stack);

void	set_ranges_stack_a(t_sort_range_index *ranges, int stack_size);
bool	is_empty_stack_b(t_bidrect_circle_list *stack_b);
void	set_ranges_stack_b(t_sort_range_index *ranges, t_bidrect_circle_list *stack_b);
t_list	*try_sort_three_relation(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log);
t_list	*try_sort_stack_b_head(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log);
t_list	*try_push_a(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log);
bool	is_sort_to_over_median_from_n(t_sort_range_index *ranges, t_bidrect_circle_list *stack);
int	check_sort_to_over_median_from_n(t_sort_range_index *ranges, t_bidrect_circle_list *stack);
bool	is_under_median(int sorted, int median);
t_list	*try_push_b(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log);
bool	is_descending_sort_until_next_sort(int sorted, t_bidrect_circle_list *stack);
int	descending_sort_until_next_sort_size(int sorted, t_bidrect_circle_list *stack);
t_list	*try_sort_stack_b(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log);
bool	is_ascending_sort_until_next_sort(int sorted, t_bidrect_circle_list *stack);
int	ascending_sort_until_next_sort_size(int sorted, t_bidrect_circle_list *stack);
t_list	*try_sort_n_th_from_front_stack_a(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log);
t_list	*try_swap_rotate(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log);

t_list	*sort_under_median(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	int	cycle = 0;

	while (1)
	{
		// print_ranges_info(ranges, 'a');
		// output_stack(stack_a, stack_b);
		if (is_finish(ranges->count_sorted + ranges->count_pushed, ranges->a_pivot))
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
