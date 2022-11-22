/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_first_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/15 20:03:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	output_stack(t_bidrect_circle_list *head_p_stack_a, t_bidrect_circle_list *head_p_stack_b);
void	print_ranges_info(t_sort_range_index *ranges, char stack);

/*
t_operation	search_under_a_pivot(int pivot, t_bidrect_circle_list *stack)
{
	t_bidrect_circle_list	*head;
	t_bidrect_circle_list	*tail;

	head = stack->next;
	tail = stack->prev;
	while (head != tail)
	{
		if (head->index < pivot && pivot <= tail->index)
		{
			return (Rotate_a);
		}
		else if (tail->index < pivot && pivot <= head->index)
		{
			return (Reverse_rotate_a);
		}
		else if (head->index < pivot && tail->index < pivot)
		{
			if (head->index < tail->index)
			{
				return (Rotate_a);
			}
			else
			{
				return (Reverse_rotate_a);
			}
		}
		head = head->next;
		tail = tail->prev;
	}
	return (Not);
}

int	count_execute_operation(t_operation operation, int pivot, t_bidrect_circle_list *stack)
{
	int	count;
	t_bidrect_circle_list *node;

	count = 0;
	node = NULL;
	if (operation == Rotate_a)
	{
		node = stack->next;
		while (pivot <= node->index)
		{
			count += 1;
			node = node->next;
		}
	}
	else if (operation == Reverse_rotate_a)
	{
		count = 1;
		node = stack->prev;
		while (pivot <= node->index)
		{
			count += 1;
			node = node->prev;
		}
	}
	return (count);
}

t_list	*try_rotate_under_a_pivot(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a,
		t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_operation	flag;
	int			count;

	flag = search_under_a_pivot(ranges->a_pivot, stack_a);
	count = count_execute_operation(flag, ranges->a_pivot, stack_a);
	if (flag == Rotate_a)
	{
		while (count)
		{
			head_p_log = execute_operation(Rotate_a, stack_a, stack_b, head_p_log);
			count -= 1;
		}
	}
	else if (flag == Reverse_rotate_a)
	{
		while (count)
		{
			head_p_log = execute_operation(Reverse_rotate_a, stack_a, stack_b, head_p_log);
			count -= 1;
		}
	}
	return (head_p_log);
}
*/

// t_list	*try_2(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
static t_list	*try_2(t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_operation	operation;
	t_operation	a;
	t_operation	b;

	operation = Not;
	a = Not;
	b = Not;
	if ((stack_a->next->index - stack_a->next->next->index) == 1)
	{
		a = Swap_a;
	}
	if ((stack_b->next->index - stack_b->next->next->index) == -1)
	{
		b = Swap_b;
	}
	if (a == Swap_a && b == Swap_b)
	{
		operation = Swap_s;
	}
	else if (a == Swap_a && b != Swap_b)
	{
		operation = a;
	}
	else if (a != Swap_a && b == Swap_b)
	{
		operation = b;
	}
	head_p_log = execute_operation(operation, stack_a, stack_b, head_p_log);
	return (head_p_log);
}

t_list	*try(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	t_operation	operation;
	t_operation	a;
	t_operation	b;

	operation = Not;
	a = Not;
	b = Not;
	if (ranges->a_pivot <= stack_a->next->index)
	{
		a = Rotate_a;
	}
	if (1 < ranges->count_pushed && stack_b->next->index < ranges->b_pivot)
	{
		b = Rotate_b;
	}
	if (a == Rotate_a && b == Rotate_b)
	{
		operation = Rotate_r;
	}
	else if (a == Rotate_a && b != Rotate_b)
	{
		operation = a;
	}
	else if (a != Rotate_a && b == Rotate_b)
	{
		operation = b;
	}
	head_p_log = execute_operation(operation, stack_a, stack_b, head_p_log);
	return (head_p_log);
}

t_list	*split_first_half(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a, t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	// int	cycle = 0;
	ranges->b_pivot = calculate_median(ranges->begin + ranges->a_pivot);
	while (1)
	{
		// print_ranges_info(ranges, 'a');
		// output_stack(stack_a, stack_b);
		if (is_finish(ranges->count_pushed, ranges->a_pivot))
		{
			break ;
		}
		if (stack_a->next->index < ranges->a_pivot)
		{
			head_p_log = execute_operation(Push_b, stack_a, stack_b, head_p_log);
			ranges->count_pushed += 1;
		}
		head_p_log = try(ranges, stack_a, stack_b, head_p_log);
		head_p_log = try_2(stack_a, stack_b, head_p_log);
		// putstr_log(head_p_log);
		// output_stack(stack_a, stack_b);

	}
	// cycle += 1;
	// if (cycle == 1000)
	// {
	// 	exit(1);
		// return (head_p_log);
	// }
	return (head_p_log);
}

/*
t_list	*split_first_half(t_sort_range_index *ranges, t_bidrect_circle_list *stack_a,
		t_bidrect_circle_list *stack_b, t_list *head_p_log)
{
	ranges->b_pivot = calculate_median(ranges->begin + ranges->a_pivot);
	while (1)
	{
		// if (ranges->count_pushed == ranges->a_pivot)
		if (is_finish(ranges->count_pushed, ranges->a_pivot))
		{
			head_p_log = try_rotate(ranges, stack_a, stack_b, head_p_log);
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
*/
